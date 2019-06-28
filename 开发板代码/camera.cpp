
/*
 *      test.c  --  USB Video Class test application
 *
 *      Copyright (C) 2005-2008
 *          Laurent Pinchart (laurent.pinchart@skynet.be)
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 */

/*
 * WARNING: This is just a test application. Don't fill bug reports, flame me,
 * curse me on 7 generations :-).
 */


//#undef V4L2_BUF_TYPE_VIDEO_CAPTURE
//#define V4L2_BUF_TYPE_VIDEO_CAPTURE 9
#include "camera.h"
#include <QImage>

Camera::Camera(): _width(200), _height(200), img(new QImage(_width, _height, QImage::Format_RGB888)) {
    int ret;
    /* V4L */
    unsigned int pixelformat = V4L2_PIX_FMT_YUYV;
    unsigned int width = 200;
    unsigned int height = 200;
    int nbufs = V4L_BUFFERS_DEFAULT;
    struct v4l2_buffer buf;

    int i;
    /* Open the video device. */
    dev = video_open(CAMERA_FILE);
    video_set_input(dev, 0);

    video_set_format(dev, width, height, pixelformat);


    /* Allocate buffers. */
    nbufs = video_reqbufs(dev, nbufs);
    /* Map the buffers. */
    for (i = 0; i < nbufs; ++i) {
        memset(&buf, 0, sizeof buf);
        buf.index = i;
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(dev, VIDIOC_QUERYBUF, &buf);

        printf("length: %u offset: %u\n", buf.length, buf.m.offset);

        mem[i] = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, dev, buf.m.offset);

        printf("Buffer %u mapped at address %p.\n", i, mem[i]);
    }

    /* Start streaming. */
    video_enable(dev, 1);

    /* Queue the buffers. */
    for (i = 0; i < nbufs; ++i) {
        memset(&buf, 0, sizeof buf);
        buf.index = i;
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(dev, VIDIOC_QBUF, &buf);

    }
}

void Camera::yuv_to_framebuffer(QImage* img, unsigned char *buffer)
{
    unsigned char* bits = img->bits();
    for (int i = 0; i < img->width() * img->height() * 3; i += 3) {
        bits[i] = buffer[i];
        bits[i+1] = buffer[i+1];
        bits[i+2] = buffer[i+2];
    }
}

void Camera::yuv_to_rgb16(unsigned char y,
                  unsigned char u,
                  unsigned char v,
                  unsigned char *rgb)
{
    register int r,g,b;
    int rgb16;

    r = (1192 * (y - 16) + 1634 * (v - 128) ) >> 10;
    g = (1192 * (y - 16) - 833 * (v - 128) - 400 * (u -128) ) >> 10;
    b = (1192 * (y - 16) + 2066 * (u - 128) ) >> 10;

    r = r > 255 ? 255 : r < 0 ? 0 : r;
    g = g > 255 ? 255 : g < 0 ? 0 : g;
    b = b > 255 ? 255 : b < 0 ? 0 : b;

    rgb16 = (int)(((r >> 3)<<11) | ((g >> 2) << 5)| ((b >> 3) << 0));

    *rgb = (unsigned char)(rgb16 & 0xFF);
    rgb++;
    *rgb = (unsigned char)((rgb16 & 0xFF00) >> 8);
}
void Camera::yuv_to_rgb24(unsigned char y,
                                unsigned char u,
                                unsigned char v,
                                unsigned char *rgb)
{
    register int r,g,b;

    r = (1192 * (y - 16) + 1634 * (v - 128) ) >> 10;
    g = (1192 * (y - 16) - 833 * (v - 128) - 400 * (u -128) ) >> 10;
    b = (1192 * (y - 16) + 2066 * (u - 128) ) >> 10;

    r = r > 255 ? 255 : r < 0 ? 0 : r;
    g = g > 255 ? 255 : g < 0 ? 0 : g;
    b = b > 255 ? 255 : b < 0 ? 0 : b;

    *rgb = (unsigned char)b;
    rgb++;
    *rgb = (unsigned char)g;
    rgb++;
    *rgb = (unsigned char)r;
}

void Camera::convert_to_rgb16(unsigned char *buf, unsigned char *rgb, int width, int height)
{
    int y=0;
    int blocks;

    blocks = (width * height) * 2;

    for (y = 0; y < blocks; y+=4) {
        unsigned char Y1, Y2, U, V;

        Y1 = buf[y + 0];
        U = buf[y + 1];
        Y2 = buf[y + 2];
        V = buf[y + 3];

        yuv_to_rgb16(Y1, U, V, &rgb[y]);
        yuv_to_rgb16(Y2, U, V, &rgb[y + 2]);
    }
}
void Camera::convert_to_rgb24(unsigned char *buf, unsigned char *rgb, int width, int height)
{
    int y, z = 0;
    int blocks;

    blocks = (width * height) * 2;

    for (y = 0, z = 0; y < blocks; y+=4, z+=6) {
        unsigned char Y1, Y2, U, V;

        Y1 = buf[y + 0];
        U = buf[y + 1];
        Y2 = buf[y + 2];
        V = buf[y + 3];

        yuv_to_rgb24(Y1, U, V, &rgb[z]);
        yuv_to_rgb24(Y2, U, V, &rgb[z + 3]);
    }
}

int Camera::video_open(const char *devname)
{
    struct v4l2_capability cap;
    int dev, ret;

    dev = open(devname, O_RDWR);
    if (dev < 0) {
        printf("Error opening device %s: %d.\n", devname, errno);
        return dev;
    }

    memset(&cap, 0, sizeof cap);
    ret = ioctl(dev, VIDIOC_QUERYCAP, &cap);
    if (ret < 0) {
        printf("Error opening device %s: unable to query device.\n",
            devname);
        close(dev);
        return ret;
    }

    if ((cap.capabilities & V4L2_CAP_VIDEO_CAPTURE) == 0) {
        printf("Error opening device %s: video capture not supported.\n",
            devname);
        close(dev);
        return -EINVAL;
    }

    printf("Device %s opened: %s.\n", devname, cap.card);
    return dev;
}


int Camera::get_pixel_depth(unsigned int fmt)
{
    int depth = 0;

    switch (fmt) {
    case V4L2_PIX_FMT_NV12:
        depth = 12;
        break;
    //case V4L2_PIX_FMT_NV12T:
    //    depth = 12;
    //    break;
    case V4L2_PIX_FMT_NV21:
        depth = 12;
        break;
    case V4L2_PIX_FMT_YUV420:
        depth = 12;
        break;

    case V4L2_PIX_FMT_RGB565:
    case V4L2_PIX_FMT_YUYV:
    case V4L2_PIX_FMT_YVYU:
    case V4L2_PIX_FMT_UYVY:
    case V4L2_PIX_FMT_VYUY:
    case V4L2_PIX_FMT_NV16:
    case V4L2_PIX_FMT_NV61:
    case V4L2_PIX_FMT_YUV422P:
        depth = 16;
        break;

    case V4L2_PIX_FMT_RGB32:
        depth = 32;
        break;
    }

    return depth;
}

int Camera::video_set_format(int dev, unsigned int w, unsigned int h, unsigned int format)
{
    struct v4l2_format fmt;

    int ret;

    printf("video_set_format: width: %u height: %u\n", w, h);

    memset(&fmt, 0, sizeof fmt);
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = w;
    fmt.fmt.pix.height = h;
    fmt.fmt.pix.pixelformat = format;
    if (format == V4L2_PIX_FMT_JPEG) fmt.fmt.pix.colorspace = V4L2_COLORSPACE_JPEG;
    fmt.fmt.pix.sizeimage = (w * h * get_pixel_depth(format)) / 8;
    fmt.fmt.pix.field = V4L2_FIELD_NONE;
    fmt.fmt.pix.priv = 1;
    ret = ioctl(dev, VIDIOC_S_FMT, &fmt);
    if (ret < 0) {
        printf("Unable to set format: %d.\n", errno);
        return ret;
    }



    printf("Video format set: width: %u height: %u buffer size: %u\n",
        fmt.fmt.pix.width, fmt.fmt.pix.height, fmt.fmt.pix.sizeimage);
    return 0;
}



int Camera::video_reqbufs(int dev, int nbufs)
{
    struct v4l2_requestbuffers rb;
    int ret;

    memset(&rb, 0, sizeof rb);
    rb.count = nbufs;
    rb.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    rb.memory = V4L2_MEMORY_MMAP;

    ret = ioctl(dev, VIDIOC_REQBUFS, &rb);
    if (ret < 0) {
        printf("Unable to allocate buffers: %d.\n", errno);
        return ret;
    }

    printf("%u buffers allocated.\n", rb.count);
    return rb.count;
}

int Camera::video_enable(int dev, int enable)
{
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret;

    ret = ioctl(dev, enable ? VIDIOC_STREAMON : VIDIOC_STREAMOFF, &type);
    if (ret < 0) {
        printf("Unable to %s capture: %d.\n",
            enable ? "start" : "stop", errno);
        return ret;
    }

    return 0;
}

int Camera::video_set_input(int dev, unsigned int in)
{
    int ret;

    struct v4l2_input input;

        input.index = in;

    ret = ioctl(dev, VIDIOC_S_INPUT, &input);
    return ret;
}

void Camera::run() {
    unsigned char *tmpBuffer, *dispBuffer;
    struct v4l2_buffer buf;
    unsigned int pixelformat = V4L2_PIX_FMT_YUYV;
    for (; ; ) {
        struct pollfd pfds[1];

        pfds[0].fd = dev;
        pfds[0].events = POLLIN | POLLERR;

        poll(pfds, 1, 10000); //10s
        /* Dequeue a buffer. */
        memset(&buf, 0, sizeof buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        ioctl(dev, VIDIOC_DQBUF, &buf);

        if(pixelformat == V4L2_PIX_FMT_YUYV){

            tmpBuffer = (unsigned char*) malloc(width() * height() * 2);
            dispBuffer = (unsigned char*) malloc(width() * height() * 4);
            memcpy(tmpBuffer, mem[buf.index],  (width() * height() * get_pixel_depth(pixelformat)) / 8);
            convert_to_rgb24(tmpBuffer, dispBuffer, width(), height());
            yuv_to_framebuffer(img, (unsigned char *)dispBuffer);
            emit send();
            free(dispBuffer);
            free(tmpBuffer);
        }

        /* Requeue the buffer. */
        ioctl(dev, VIDIOC_QBUF, &buf);

        usleep(1);

    }
}
