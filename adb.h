#ifndef ADB_H
#define ADB_H

#include "position.h"
#include<QString>
class ADB
{
public:
    ADB();
    static bool isConnect(QString& rescontent);
    static QString getDeviceName();
    static Position getDeviceSize();
     static int getDeviceDensity();
    static bool scrcpy(int size);
    static bool command(QString cmd,const QStringList &arguments,QString& rescontent);
    static bool sleep(int second);
    static bool click(int x,int y);
    static bool input(int code);
    static bool input(QString text);
    static bool startadb();
    static QString getHostMacAddress();


    static QString adb_bin;
        static QString scrcpy_bin;
};


#endif // ADB_H
