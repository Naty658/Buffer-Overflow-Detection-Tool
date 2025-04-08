#include "login.h"
#include "ui_login.h"
#include "loginfield.h"  // Ensure this header is included

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // Connect buttons or actions if needed
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_loginButton_clicked);
    connect(ui->createAccountButton, &QPushButton::clicked, this, &Login::on_createAccountButton_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    loginfield *loginfieldScreen = new loginfield(this);
    loginfieldScreen->exec();  // Shows the new window in a modal way
}

void Login::on_createAccountButton_clicked()
{
    loginfield *loginfieldScreen = new loginfield(this);
    loginfieldScreen->exec();  // Shows the new window in a modal way
}
