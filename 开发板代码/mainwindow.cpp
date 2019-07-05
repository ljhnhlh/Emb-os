#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    isrunning(true),
    camera(new Camera()),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSocket();
    connect(camera, SIGNAL(send()), this, SLOT(display()));
    camera->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display() {
    isrunning = true;
    if (isrunning) {
        ui->label->setPixmap(QPixmap::fromImage(*camera->img));
        char* bits = (char*) camera->img->bits();
        // QByteArray data = QByteArray(bits, 200 * 200 * 3);
        for (int i = 0; i < 200 * 200 * 3; i += 1023) {
            socket->writeDatagram(bits+i, (200*200*3-i) > 1023 ? 1023: (200*200*3-i), QHostAddress("192.168.0.205"), 8080);
        }
        camera->img->save("./1.png");
    }
    QImage *t = new QImage("test.png");
    if(!t->isNull())
    {
        ui->img->setPixmap(QPixmap::fromImage(*t));
    }
    else{
        std::cout << "no Image" << endl;
    }
}

void MainWindow::initSocket() {
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress("127.0.0.1"), 8080);
    connect(socket, SIGNAL(readyRead()), this, SLOT(process()));

}

void MainWindow::process() {
    QByteArray datagram;
    datagram.resize(socket->pendingDatagramSize());
    socket->readDatagram(datagram.data(), datagram.size());

    if (datagram == "pause") {
        printf("pause");
        isrunning = false;
    } else if (datagram == "begin") {
        isrunning = true;
        printf("begin");
    } else {
        printf("else\n");
    }
}
