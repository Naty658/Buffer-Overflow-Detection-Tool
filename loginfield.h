#ifndef LOGINFIELD_H
#define LOGINFIELD_H

#include <QDialog>

namespace Ui {
class loginfield;
}

class loginfield : public QDialog
{
    Q_OBJECT

public:
    explicit loginfield(QWidget *parent = nullptr);
    ~loginfield();


private slots:
    void on_loginButton_clicked();


private:
    Ui::loginfield *ui;
};

#endif // LOGINFIELD_H
