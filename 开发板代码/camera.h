#ifndef CAMERA_H
#define CAMERA_H
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
#include <linux/fb.h>
#include <linux/videodev2.h>
#include <poll.h>
#include <QImage>
#include <QThread>

#define CAMERA_FILE "/dev/video0"
#define V4L_BUFFERS_DEFAULT     4
#define V4L_BUFFERS_MAX		32

typedef struct  _fb_v4l
{
    int fbfd ;
    char *fbp;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
}fb_v41;

class Camera: public QThread {
    Q_OBJECT
private:
    int _width;
    int _height;
    void *mem[V4L_BUFFERS_MAX];
    int dev;
public:
    Camera();
    void yuv_to_framebuffer(QImage* img, unsigned char *buffer);
    void convert_to_rgb16(unsigned char *buf, unsigned char *rgb, int width, int height);
    void convert_to_rgb24(unsigned char *buf, unsigned char *rgb, int width, int height);
    void yuv_to_rgb16(unsigned char y,
                      unsigned char u,
                      unsigned char v,
                      unsigned char *rgb);
    void yuv_to_rgb24(unsigned char y,
                      unsigned char u,
                      unsigned char v,
                      unsigned char *rgb);
    int video_open(const char *devname);
    int get_pixel_depth(unsigned int fmt);
    int video_set_format(int dev, unsigned int w, unsigned int h, unsigned int format);
    int video_reqbufs(int dev, int nbufs);
    int video_enable(int dev, int enable);
    int video_set_input(int dev, unsigned int in);
    int width() { return _width; }
    int height() { return _height; }
    virtual void run();
    QImage* img;
signals:
    void send();

};
#endif // CAMERA_H
