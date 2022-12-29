#include <QApplication>
#include <QDebug>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    QString logoImagePath = ":/images/logo.png";

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(logoImagePath));

    MainWindow* w = MainWindow::GetInstance();
    w->setWindowIcon(QIcon(logoImagePath));
    w->show();

    auto retValue = a.exec();

    delete w;

    return retValue;
}
