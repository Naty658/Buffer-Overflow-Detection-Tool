#include "login.h"
#include "staticcodeanalyzer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Show the login dialog first
    Login loginDialog;
    loginDialog.exec();  // This blocks the code until the dialog is closed

    // After the login dialog is closed, show the StaticCodeAnalyzer window
    StaticCodeAnalyzer w;
    w.show();

    return a.exec();  // Start the application's event loop
}
