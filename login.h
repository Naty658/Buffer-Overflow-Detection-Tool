#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();        // Slot for Login button click
    void on_createAccountButton_clicked(); // Slot for Create Account button click

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
