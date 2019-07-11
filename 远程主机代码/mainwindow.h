#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void pause();
    void begin();
    void display();
    void screenshot();
    void reply();
private:
    QUdpSocket* socket;
    QImage* img;
    Ui::MainWindow *ui;
    void initSocket();
    bool isok;

};

#endif // MAINWINDOW_H
