#ifndef DEVICE_H
#define DEVICE_H

#include "adb.h"
class Device
{

public:
    Device();
    Device(const Device& devi);
    bool connect();

    void scrcpy(int size);
    ~Device();
     int getWidth() const;

     void setWidth(int width);

     int getHeight() const;

     void setHeight(int height);

     QString *getName() const;

     void setName(QString *name);

     QString *getStatus() const;

     void setStatus(QString *status);

     bool isOnline() const;

     void setOnline(bool online);
     void setDensity(int density);
     int getDensity();



private:
    int Width;
    int Height;
    QString* name;
    QString* status;
    bool online;
    int density;


};

#endif // DEVICE_H
