#include "loginwindow.h"
#include "ui_mainwindow.h"
#include "ui_loginwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QString>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include "mainwindow.h"

sqlite3 *db1;

int focus_flag = 1;
QString PW = "";
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    init();
    connect( ui->confirm_btn, SIGNAL(clicked()), this, SLOT(confirm_btn_Clicked()) );
    connect( ui->switch_btn, SIGNAL(clicked()), this, SLOT(switch_btn_Clicked()) );

}
void LoginWindow::confirm_btn_Clicked()
{
    QString state = ui->label_name->text();
    if(ui->username_text->text() == "" || ui->username_text->text() == "")
    {
        QMessageBox::information( 0, "Info", "Input can not be empty!");
        return;
    }
    if(state == "Register") addUser(ui->username_text->text(),ui->passwd_text->text());
    else
    {
        if(!isExist(ui->username_text->text()))
        {
            QMessageBox::information( 0, "Info", "Username is not existed!\nPlease register first" );
            return;
        }
        if(isCorrect(ui->username_text->text(),ui->passwd_text->text()))
        {
            QMessageBox::information( 0, "Info", "Login successfully!" );
            MainWindow *d = new MainWindow ;
            d->show();
            this->close();
        }
        else
        {
            QString temp = "Login failed!\n";
            if(isExist(ui->username_text->text()))
            {
                temp.append("Password error!");
            }
            else
            {
                temp.append("Username is not exist!");
            }
            QMessageBox::information( 0, "Info", temp );

        }
    }


}
bool LoginWindow::isCorrect(QString username,QString passwd)
{
    char *sql;
    char *errmsg;
    int ret;

    QString str = "select * from user where username is '" + username + "'";

    QByteArray ba = str.toLatin1(); // must

    sql = ba.data();
    PW = passwd;
    ret = sqlite3_exec(db1,sql,checkPW,NULL,&errmsg);
    //QMessageBox::information( 0, "isExist",QString::number(ret));
    if(ret == 0) return true;
    else return false;
}

void LoginWindow::switch_btn_Clicked()
{
    QString state = ui->label_name->text();
    if(state == "Register")
    {
        ui->label_name->setText("Login");
        ui->switch_btn->setText("Switch to Register");
    }
    else
    {
        ui->label_name->setText("Register");
        ui->switch_btn->setText("Switch to Login");
    }
}

void LoginWindow::addUser(QString username, QString passwd)
{

    if(isExist(username))
    {
        QMessageBox::information( 0, "Info", "Username has existed!\nPlease change the username" );
        return;
    }


    QString str = "insert into user values('" + username + "','" + passwd + "');";

    QByteArray ba = str.toLatin1(); // must

    char* sql;
    sql = ba.data();

    QMessageBox::information( 0, "Info","register successfully!");
    sqlite3_exec(db1, sql, NULL, NULL, NULL);


}
bool LoginWindow::isExist(QString username)
{
    char *sql;
    char *errmsg;
    int ret;
    QString str = "select * from user where username is '" + username + "'";

    QByteArray ba = str.toLatin1(); // must

    sql = ba.data();

    ret = sqlite3_exec(db1,sql,displaycb,NULL,&errmsg);
    //QMessageBox::information( 0, "isExist",QString::number(ret));
    if(ret == 0) return false;
    else return true;

}
int checkPW(void* para,int ncolumn,char ** columnvalue,char *columnname[])
{
    QString username = columnvalue[0];
    QString passwd = columnvalue[1];
    if(passwd == PW) return 0;
    else return 1;

}
int displaycb(void* para,int ncolumn,char ** columnvalue,char *columnname[])
{
    QString username = columnvalue[0];
    QString passwd = columnvalue[1];
    return 1;

}


void LoginWindow::init()
{

    char *zErrMsg = 0;
     int rc;
     rc = sqlite3_open("test.db", &db1);
    if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db1));
       exit(0);
    }
    else{ fprintf(stderr, "Opened database successfully\n"); }
    sqlite3_exec(db1,"Create table if not exists user(username VARCHAR(10),passwd VARCHAR(20))"
                 , NULL, NULL, &zErrMsg);


/*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     //设置数据库的名称;
     db.setDatabaseName("/home/ubuntu/dbtest");
     //打开数据库，如果数据库存在，则打开；如果不存在，则创建数据库;
     bool ok = db.open();
     if(ok)
     {
         //QMessageBox::information( 0, "Info", "open sql ok" );

     }
     else
     {
         QMessageBox::information( 0, "Info", "open sql not ok" );

     }
     QSqlQuery query;
     if(!query.exec("Create table if not exists user(username VARCHAR(10),passwd VARCHAR(20))"))
     {
         QMessageBox::information( 0, "Info", "create not ok" );

     }
     */
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::on_username_text_lostFocus()
{
    focus_flag = 1;
}

void LoginWindow::on_passwd_text_lostFocus()
{
    focus_flag = 2;
}

void LoginWindow::keybored_press(int num1)
{
    QString num = QString::number(num1);
    if(focus_flag == 1)
    {
        QString temp = ui->username_text->text();
        temp += num;
        ui->username_text->setText(temp);

    }
    else if(focus_flag == 2)
    {
        QString temp = ui->passwd_text->text();
        temp += num;
        ui->passwd_text->setText(temp);
    }
}

void LoginWindow::on_btn1_clicked()
{
    keybored_press(1);
}


void LoginWindow::on_btn2_clicked()
{
    keybored_press(2);
}

void LoginWindow::on_btn3_clicked()
{
    keybored_press(3);
}

void LoginWindow::on_btn4_clicked()
{
    keybored_press(4);
}

void LoginWindow::on_btn5_clicked()
{
    keybored_press(5);
}

void LoginWindow::on_btn6_clicked()
{
    keybored_press(6);
}

void LoginWindow::on_btn7_clicked()
{
    keybored_press(7);
}

void LoginWindow::on_btn8_clicked()
{
    keybored_press(8);
}

void LoginWindow::on_btn9_clicked()
{
    keybored_press(9);
}

void LoginWindow::on_btn0_clicked()
{
    keybored_press(0);
}

void LoginWindow::on_btn_delete_clicked()
{
    if(focus_flag == 1)
    {
        QString string = ui->username_text->text();
        if(string.isEmpty()) return;
        string = string.left(string.length() - 1);
        ui->username_text->setText(string);

    }
    else if(focus_flag == 2)
    {
        QString string = ui->passwd_text->text();
        if(string.isEmpty()) return;
        string = string.left(string.length() - 1);
        ui->passwd_text->setText(string);
    }
}

void LoginWindow::on_btn_clear_clicked()
{
    if(focus_flag == 1)
    {
        ui->username_text->setText("");

    }
    else if(focus_flag == 2)
    {
        ui->passwd_text->setText("");
    }
}
