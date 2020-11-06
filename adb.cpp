#include "adb.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <QProcess>
#include <QDebug>
#include <QStringList>
#include <QtGlobal>
#include <QCoreApplication>
#include <QNetworkInterface>
#include <QList>

QString ADB::adb_bin="D:\\Downloads\\scrcpy-win64\\adb";
QString ADB::scrcpy_bin ="D:\\Downloads\\scrcpy-win64\\scrcpy.exe";
ADB::ADB() {

}
QString ADB::getHostMacAddress(){
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
       int nCnt = nets.count();
       QString strMacAddr = "";
        int j= 0;
       for(int i = 0; i < nCnt; i ++)
       {
           // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
           if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
           {

               if(j>3){
                break;
               }
               j++;
               strMacAddr += nets[i].hardwareAddress();
//               qDebug()<<"strmacAddr : "<<strMacAddr;
//                qDebug()<<"name : "<<  nets[i].name();
//               break;
           }
       }
       return strMacAddr;

}
 bool ADB::startadb(){
     QString fileName = QCoreApplication::applicationDirPath();
     qDebug()<<"fileName "<<fileName<<endl;
     if((fileName.indexOf("QtpProject"))<0){
         adb_bin =fileName+"/adb";
         scrcpy_bin =fileName+"/scrcpy";
     }

     QString rescontent = "";
     return command("cmd", QStringList()<<"/c"<<adb_bin+ " start-server",rescontent);
}

bool ADB::isConnect(QString& rescontent) {

    return command("cmd", QStringList()<<"/c"<<adb_bin+ " devices",rescontent);
}

QString ADB::getDeviceName() {
    QString name;
    bool res =  command("cmd", QStringList()<<"/c"<<adb_bin+" shell getprop ro.product.name",name);
    if(res == false){
        name = "";
    }
    name.replace("\r\n","");
     qDebug()<<"name :"<<name <<endl;
    return name;
}


Position ADB::getDeviceSize() {
    QString str_size;
      command("cmd", QStringList()<<"/c"<<adb_bin+" shell wm size",str_size);
    auto size = str_size.split("\r\n");
    QString oversize ="";
    int i = 0;
    foreach(QString o,size){

        o.replace("Physical size: ","");
        o.replace("Override size: ","");

        if(o!=""){
        oversize = o;
        }
        i++;
    }

    auto wh = oversize.split("x");
    i =0;
    int x= 0;
    int y = 0;

    foreach(QString pos,wh){
        if(i == 0){
            i++;
            x= pos.toInt();
        }else{
            y= pos.toInt();
        }
    }
    if(x < y){
        qSwap(x,y);
    }
  qDebug()<<"x :"<<x <<"y :"<<y<<endl;
    return Position(x,y,0);
}

 int  ADB::getDeviceDensity(){
     QString str_size;
       command("cmd", QStringList()<<"/c"<<adb_bin+" shell wm density",str_size);
     auto size = str_size.split("\r\n");
     QString overdensity;
     int i = 0;
     foreach(QString o,size){

         o.replace("Physical density: ","");
         o.replace("Override density: ","");

         if(o!=""){
             overdensity =o;
         }
         i++;
     }
     qDebug()<<"overdensity" <<overdensity<<endl;

     return overdensity.toInt();


}

bool ADB::scrcpy(int size) {
    QString str_size;
   // bool res =  command("cmd", QStringList()<<"/c"<<scrcpy_bin+" -m 720",str_size);
    qDebug()<<"scrcpy size :"<<size<<endl;
    qDebug()<<scrcpy_bin<<endl;
    QString std = "-m";
    QString std1 =QString::number(size);
    QList<QString> list;
    list.push_back(std);
    list.push_back(std1);
    QStringList qslist(list);
    QProcess::execute(scrcpy_bin,qslist);
     bool res = false;
    return res;
}


bool ADB::command(QString cmd,const QStringList &arguments,QString& rescontent) {
    QProcess* process = new QProcess();
    bool res = false;
    process->start(cmd,arguments);
    process->waitForFinished();
    QByteArray qbt_success ;
    qbt_success  = process->readAllStandardOutput();
    QByteArray qbt_error ;
    qbt_error = process->readAllStandardError();
    QString msg1 = QString::fromLocal8Bit(qbt_success);
    QString msg_error = QString::fromLocal8Bit(qbt_error);
//    qDebug()<<"output :"<<msg1<<endl;
//    qDebug()<<"error  :"<<msg_error<<endl;
    if(msg_error!=""){
        res = false;
    }else{
        res = true;
        rescontent =msg1;
    }
    return res;
}

bool ADB::sleep(int second) {
     QString sslep;
//     qDebug()<<QString::number(second)<<endl;;
     bool res =  command("cmd", QStringList()<<"/c"<<adb_bin+" shell sleep "+QString::number(second),sslep);
     return res;
}

bool ADB::click(int x, int y) {
    QString cclick;
    bool res =  command("cmd", QStringList()<<"/c"<<adb_bin+" shell input tap "+QString::number(x) + " "+QString::number(y),cclick);
    return res;
}

bool ADB::input(int code) {
    QString cclick;
    bool res =  command("cmd", QStringList()<<"/c"<<adb_bin+" shell input keyevent "+QString::number(code),cclick);
    return res;
}
bool ADB::input(QString text) {
    QString cclick;
    qDebug()<<"text :"<<text<<endl;
    bool res =  command("cmd", QStringList()<<"/c"<<adb_bin+" shell input text "+text ,cclick);
    return res;
}














