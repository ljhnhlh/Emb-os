#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include "camera.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void display();
    void process();
private:
    Camera* camera;
    QUdpSocket* socket;
    QUdpSocket* socket2;
    Ui::MainWindow *ui;
    void initSocket();
    bool isrunning;
    bool isok;
};

#endif // isok
