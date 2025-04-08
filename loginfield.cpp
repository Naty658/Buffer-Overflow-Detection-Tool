#include "loginfield.h"
#include "ui_loginfield.h"

loginfield::loginfield(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginfield)
{
    ui->setupUi(this);
}

loginfield::~loginfield()
{
    delete ui;
}


void loginfield::on_loginButton_clicked()
{
    // Handle login logic here
}

