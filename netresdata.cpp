#include "netresdata.h"

NetResData::NetResData(int flag,int day,QString reson):flag(flag),day(day),reson(reson){

}
int NetResData::getFlag(){
 return this->flag;
}
int NetResData::getDay(){
 return this->day;
}
QString NetResData::getReson(){

    return this->reson;
}
void NetResData::setFlag(int flag){
  this->flag =flag;
}
void NetResData::setDay(int day){
  this->day =day;
}
void NetResData::setReson(QString reson){
    this->reson =reson;
}
