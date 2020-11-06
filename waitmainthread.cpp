#include "waitmainthread.h"


waitMainThread::waitMainThread(QLabel* label ){
    this->label = label;

}
 void waitMainThread::run(){
label->setText("激活成功，使用时长 30天！");
//     this->sleep(3);
//     dialog->close();
}
