/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QStackedWidget *stackedWidget;
    QWidget *loginScreen;
    QVBoxLayout *vboxLayout;
    QPushButton *loginButton;
    QPushButton *createAccountButton;
    QWidget *loginfieldScreen;
    QVBoxLayout *vboxLayout1;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 400, 300));
        loginScreen = new QWidget();
        loginScreen->setObjectName("loginScreen");
        vboxLayout = new QVBoxLayout(loginScreen);
        vboxLayout->setObjectName("vboxLayout");
        loginButton = new QPushButton(loginScreen);
        loginButton->setObjectName("loginButton");

        vboxLayout->addWidget(loginButton);

        createAccountButton = new QPushButton(loginScreen);
        createAccountButton->setObjectName("createAccountButton");

        vboxLayout->addWidget(createAccountButton);

        stackedWidget->addWidget(loginScreen);
        loginfieldScreen = new QWidget();
        loginfieldScreen->setObjectName("loginfieldScreen");
        vboxLayout1 = new QVBoxLayout(loginfieldScreen);
        vboxLayout1->setObjectName("vboxLayout1");
        textEdit = new QTextEdit(loginfieldScreen);
        textEdit->setObjectName("textEdit");

        vboxLayout1->addWidget(textEdit);

        textEdit_2 = new QTextEdit(loginfieldScreen);
        textEdit_2->setObjectName("textEdit_2");

        vboxLayout1->addWidget(textEdit_2);

        stackedWidget->addWidget(loginfieldScreen);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "Login", nullptr));
        createAccountButton->setText(QCoreApplication::translate("Login", "Create account", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      user name</p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("Login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">       Password</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
