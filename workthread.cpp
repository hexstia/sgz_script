#include "workthread.h"
#include "sgz.h"

volatile bool WorkThread::isStop = false;
WorkThread::WorkThread(std::shared_ptr<Sgz> sgz,int event_id)
{
    isStop =false;
    this->sgz = sgz;
    this->event_id =event_id;
    connect(sgz.get(),SIGNAL(updateText1(QString)),this,SLOT(sgz_updateText(QString)));
}

void WorkThread::sgz_updateText(QString message){
    emit updateText(message);

}
WorkThread::WorkThread(std::shared_ptr<Device> device,int event_id,int size)
{
    isStop =false;
    this->device = device;
    this->event_id =event_id;
    this->size =size;
}

void WorkThread::closeThread(){
        isStop = true;

}
//坚持出征的设置
void WorkThread::setPersiAttack(bool pack){
        this->persiAttack = pack;
}
void WorkThread::run(){
    switch (this->event_id) {
     case CLICK_ID: //铺路
    {

        int size = sgz->getSize();
        emit updateText("铺路前的等待，正在执行...");
        int element_count = sgz->start_wait();//开始前的等待
         emit updateText("铺路前的等待,结束！");
        size = size-element_count;
        qDebug()<<"size :"<<size<<endl;
        for (int i = 0;i<size;i++) {
             emit updateText("坐标:"+QString::number(i)+"：正在执行...");
             qDebug()<<"start loop  ------>i :"<<i<<endl;
             if(isStop){
                break;
             }
           bool res =  sgz->one_complete(i,persiAttack);
           if(!res){
                break;
           }
              emit updateText("坐标:"+QString::number(i)+"：已经结束...");
            qDebug()<<"end ------>i :"<<i<<endl;
        }
          emit updateText("脚本执行结束");
         qDebug()<<"for loop end:"<<endl;
                 break;
    }
    case SCRCPY_ID://投屏
    {
        device->scrcpy(size);
        break;
    }

    }
}
