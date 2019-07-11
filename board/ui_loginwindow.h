/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created: Thu Jul 11 12:40:32 2019
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *username_text;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLineEdit *passwd_text;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirm_btn;
    QPushButton *switch_btn;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn5;
    QPushButton *btn4;
    QPushButton *btn1;
    QPushButton *btn7;
    QPushButton *btn2;
    QPushButton *btn9;
    QPushButton *btn3;
    QPushButton *btn8;
    QPushButton *btn0;
    QPushButton *btn6;
    QPushButton *btn_delete;
    QPushButton *btn_clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(607, 300);
        LoginWindow->setInputMethodHints(Qt::ImhNone);
        centralWidget = new QWidget(LoginWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 228, 195));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(verticalLayoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setLayoutDirection(Qt::LeftToRight);
        label_name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_name);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        username_text = new QLineEdit(verticalLayoutWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));

        horizontalLayout_3->addWidget(username_text);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_9->addWidget(label_3);

        passwd_text = new QLineEdit(verticalLayoutWidget);
        passwd_text->setObjectName(QString::fromUtf8("passwd_text"));
        passwd_text->setEchoMode(QLineEdit::Password);

        horizontalLayout_9->addWidget(passwd_text);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        confirm_btn = new QPushButton(verticalLayoutWidget);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));

        horizontalLayout_2->addWidget(confirm_btn);

        switch_btn = new QPushButton(verticalLayoutWidget);
        switch_btn->setObjectName(QString::fromUtf8("switch_btn"));

        horizontalLayout_2->addWidget(switch_btn);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(290, 40, 302, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn5 = new QPushButton(gridLayoutWidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));

        gridLayout->addWidget(btn5, 1, 1, 1, 1);

        btn4 = new QPushButton(gridLayoutWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));

        gridLayout->addWidget(btn4, 1, 0, 1, 1);

        btn1 = new QPushButton(gridLayoutWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));

        gridLayout->addWidget(btn1, 0, 0, 1, 1);

        btn7 = new QPushButton(gridLayoutWidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));

        gridLayout->addWidget(btn7, 2, 0, 1, 1);

        btn2 = new QPushButton(gridLayoutWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        gridLayout->addWidget(btn2, 0, 1, 1, 1);

        btn9 = new QPushButton(gridLayoutWidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));

        gridLayout->addWidget(btn9, 2, 2, 1, 1);

        btn3 = new QPushButton(gridLayoutWidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));

        gridLayout->addWidget(btn3, 0, 2, 1, 1);

        btn8 = new QPushButton(gridLayoutWidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));

        gridLayout->addWidget(btn8, 2, 1, 1, 1);

        btn0 = new QPushButton(gridLayoutWidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));

        gridLayout->addWidget(btn0, 3, 1, 1, 1);

        btn6 = new QPushButton(gridLayoutWidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));

        gridLayout->addWidget(btn6, 1, 2, 1, 1);

        btn_delete = new QPushButton(gridLayoutWidget);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        gridLayout->addWidget(btn_delete, 3, 2, 1, 1);

        btn_clear = new QPushButton(gridLayoutWidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        gridLayout->addWidget(btn_clear, 3, 0, 1, 1);

        LoginWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 607, 23));
        LoginWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LoginWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LoginWindow->setStatusBar(statusBar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("LoginWindow", "Register", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoginWindow", " Username:  ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LoginWindow", " Password: ", 0, QApplication::UnicodeUTF8));
        passwd_text->setText(QString());
        confirm_btn->setText(QApplication::translate("LoginWindow", "Confirm", 0, QApplication::UnicodeUTF8));
        switch_btn->setText(QApplication::translate("LoginWindow", "Switch to Login", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("LoginWindow", "5", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("LoginWindow", "4", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("LoginWindow", "1", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("LoginWindow", "7", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("LoginWindow", "2", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("LoginWindow", "9", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("LoginWindow", "3", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("LoginWindow", "8", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("LoginWindow", "0", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("LoginWindow", "6", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("LoginWindow", "delete", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("LoginWindow", "clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
