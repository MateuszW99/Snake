#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Board* window = new Board();
    qDebug() << "main";
    window->show();
    return app.exec();
}
