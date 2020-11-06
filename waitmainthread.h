#ifndef WAITMAINTHREAD_H
#define WAITMAINTHREAD_H

#include "dialog.h"
#include <QThread>
#include <QLabel>
class waitMainThread :public QThread
{
public:
    waitMainThread(QLabel* label);
 virtual void run();
private:
    QLabel* label;

};

#endif // WAITMAINTHREAD_H
