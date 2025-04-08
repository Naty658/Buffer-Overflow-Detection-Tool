/********************************************************************************
** Form generated from reading UI file 'loginfield.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFIELD_H
#define UI_LOGINFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_loginfield
{
public:
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *loginfield)
    {
        if (loginfield->objectName().isEmpty())
            loginfield->setObjectName("loginfield");
        loginfield->resize(400, 300);
        textEdit = new QTextEdit(loginfield);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(120, 60, 101, 31));
        textEdit_2 = new QTextEdit(loginfield);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(120, 100, 101, 21));

        retranslateUi(loginfield);

        QMetaObject::connectSlotsByName(loginfield);
    } // setupUi

    void retranslateUi(QDialog *loginfield)
    {
        loginfield->setWindowTitle(QCoreApplication::translate("loginfield", "Dialog", nullptr));
        textEdit->setHtml(QCoreApplication::translate("loginfield", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">      user name</p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("loginfield", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
    class loginfield: public Ui_loginfield {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFIELD_H
