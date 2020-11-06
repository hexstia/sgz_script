#ifndef STARTMAINTHREAD_H
#define STARTMAINTHREAD_H

#include <QThread>
#include "dialog.h"
class StartMainThread :public QThread
{
public:
    StartMainThread(Dialog *dl);
    virtual void run();
private:
    Dialog* dialog;
};

#endif // STARTMAINTHREAD_H
