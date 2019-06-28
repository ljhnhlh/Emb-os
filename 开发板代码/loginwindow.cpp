#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QDateTime>
#include <QDebug>

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
        if(isCorrect(ui->username_text->text(),ui->passwd_text->text()))
        {
            QMessageBox::information( 0, "Info", "Login successfully!" );
            MainWindow *d = new MainWindow();
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
    QSqlQuery query;
    query.exec("select * from user where username is '" + username + "'");
    if(query.next() == NULL) return false;
    else
    {
        if(query.value(1).toString() == passwd)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
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
    QSqlQuery query;
    if(query.exec("insert into user(username,passwd) values('"+
               username +
                  "','" + passwd + "')"))
        QMessageBox::information( 0, "Info", "register Successfully" );

}
bool LoginWindow::isExist(QString username)
{
    QSqlQuery query;
    query.exec("select * from user where username is '" + username + "'");
    if(query.next() == NULL) return false;
    else return true;
}

void LoginWindow::init()
{
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
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
