#ifndef NETRESDATA_H
#define NETRESDATA_H

#include <QString>
class NetResData
{
public:
    NetResData(int flag,int day,QString reson);
    int getFlag();
    int getDay();
    QString getReson();
    void setFlag(int flag);
    void setDay(int day);
    void setReson(QString reson);

private:
    int flag;
    int day;
    QString reson;
};

#endif // NETRESDATA_H
