#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    w.show();
    Dialog* dlog =  new Dialog();
    dlog->setWindow(w);
    dlog->show();
    int res =a.exec();
    return res ;
}
