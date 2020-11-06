#include "startmainthread.h"
#include "mainwindow.h"

StartMainThread::StartMainThread(Dialog* dl)
{
    this->dialog  = dl;
}

void StartMainThread::run(){
    this->sleep(3);
    MainWindow * mw =new MainWindow();
    mw->hide();
//    mw->show();
//    dialog->close();
//    while(true);
//    this->sleep(100000);
}
