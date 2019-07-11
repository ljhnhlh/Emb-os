#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QString>
#include"camera.h"
#include <sqlite3.h>


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
    void keybored_press(int num);

private slots:
    void confirm_btn_Clicked();
    void switch_btn_Clicked();

    void on_btn1_clicked();

    void on_username_text_lostFocus();

    void on_passwd_text_lostFocus();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btn0_clicked();

    void on_btn_delete_clicked();

    void on_btn_clear_clicked();

private:
    Ui::LoginWindow *ui;
};
void inquire_usecb(sqlite3 * db);
int displaycb(void *para,int ncolumn,char ** columnvalue,char *columnname[]);
int checkPW(void* para,int ncolumn,char ** columnvalue,char *columnname[]);

#endif // LOGINWINDOW_H
