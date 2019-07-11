 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    img(new QImage(640, 480, QImage::Format_RGB888)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSocket();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pause() {
    socket->writeDatagram("pause", QHostAddress("127.0.0.1"), 3000);
}

void MainWindow::begin() {
    socket->writeDatagram("begin", QHostAddress("127.0.0.1"), 3000);
}

void MainWindow::screenshot() {
    img->save("./camera.bmp", "bmp");
}

void MainWindow::display() {
    QByteArray datagram;
    static int j = 0;
    while (socket->hasPendingDatagrams()) {

        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());
        unsigned char* bits = img->bits();

        unsigned char* buffer = (unsigned char*) datagram.data();
        std::cout << datagram.size() << std::endl;
        for (int i = 0; i < datagram.size(); i += 3) {
            bits[j] = buffer[i];
            bits[j+1] = buffer[i+1];
            bits[j+2] = buffer[i+2];
            j += 3;
            if (j >= 640 * 480 * 3) {

                j = 0;

            }
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(*img));

}

void MainWindow::initSocket() {
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress("127.0.0.1"), 8080);
    connect(ui->pauseButton, SIGNAL(clicked(bool)), this, SLOT(pause()));
    connect(ui->beginButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(ui->screenButton, SIGNAL(clicked(bool)), this, SLOT(screenshot()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(display()));
}
