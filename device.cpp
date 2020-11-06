#include "device.h"

Device::Device()
{
    name = new QString();
    status = new QString();
}

Device::Device(const Device& devi){
    this->status =devi.getStatus();
    this->name = devi.getName();


}
void Device::scrcpy(int size){
    ADB::scrcpy(size);
}
bool Device::connect(){

    online = false;
    QString rescontent;
     ADB::startadb();
    online = ADB::isConnect(rescontent);
//    qDebug()<<"rescontent"<<rescontent<<endl;
    if(rescontent =="List of devices attached\r\n\r\n"){

        online =false;
    }
    qDebug()<<"online :"<<online<<endl;
    if(online){
        auto s = rescontent.split("\r\n");

        foreach(QString item,s){
            if(item.indexOf("\t")&&item.indexOf("device")){
                *status =QString("在线");

            }else{
                *status =QString("异常");
                online = false;
                return online;
            }
        }
        *name = ADB::getDeviceName();
        density = ADB::getDeviceDensity();
        Position p = ADB::getDeviceSize();

        Width =p.getX();
        Height = p.getY();
        qDebug()<<"*name : "<<*name <<endl;
        qDebug()<<"*status : "<<*status <<endl;
        qDebug()<<"Width : "<<Width <<endl;
        qDebug()<<"Height : "<<Height <<endl;


    }else{
        *name =QString("");
        *status =QString("离线");
        Width = 0;
        Height = 0;
    }
    return online;
}



Device::~Device()
{
    if(name !=nullptr){
        delete name;
    }
    if(status !=nullptr){
        delete status;
    }

}


int Device::getWidth() const {
    return Width;
}

void Device::setWidth(int width) {
    Width = width;
}

int Device::getHeight() const {
    return Height;
}

void Device::setHeight(int height) {
    Height = height;
}

QString *Device::getName() const {
    return name;
}

void Device::setName(QString *name) {
    Device::name = name;
}

QString *Device::getStatus() const {
    return status;
}

void Device::setStatus(QString *status) {
    Device::status = status;
}

bool Device::isOnline() const {
    return online;
}

void Device::setOnline(bool online) {
    Device::online = online;
}

void Device::setDensity(int density)  {
    this->density = density;
}
int  Device::getDensity()  {
    return density;
}
