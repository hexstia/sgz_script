#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include "sgz.h"
#include "device.h"
class WorkThread: public QThread
{


    Q_OBJECT
public:
    static const int  CLICK_ID = 1;
    static const int SCRCPY_ID = 2;
    WorkThread(std::shared_ptr<Sgz> sgz,int ID);
    WorkThread(std::shared_ptr<Device> device,int ID,int size);
    void closeThread();
    void setPersiAttack(bool pack);
    virtual void run();
    static volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
    std::shared_ptr<Sgz> sgz;
signals:
    void updateText(QString message);
 public slots:
    void sgz_updateText(QString message);
  private:

    std::shared_ptr<Device> device;
     int event_id;
     int size;  //scrcpy的size
     bool persiAttack;

};

#endif // WORKTHREAD_H
