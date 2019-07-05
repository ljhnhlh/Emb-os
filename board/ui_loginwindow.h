/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created: Sun Jun 30 12:07:05 2019
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 300);
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

        LoginWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
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
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
