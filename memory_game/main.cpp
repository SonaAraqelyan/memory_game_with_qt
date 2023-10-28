#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(610,780);
    w.setWindowTitle("Memory Game");
    w.show();
    return a.exec();
}
