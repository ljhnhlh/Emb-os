#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QString>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    void init();
    void addUser(QString username,QString passwd);
    bool isExist(QString username);
    bool isCorrect(QString username,QString passwd);
private slots:
    void confirm_btn_Clicked();
    void switch_btn_Clicked();
private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
