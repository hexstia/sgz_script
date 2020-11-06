#include "position.h"
#include <QLineEdit>
#include "adb.h"



Position::Position(){

}
Position::Position(int x,int y,int delay)
{
    if(x==0||y==0||delay==0){
        enable =false;
    }else{
        enable = true;
    }
    this->x = x;
    this->y = y;
    this->delay = delay;
}

Position::Position(int x,int y,int delay,int checkbox,int quickId,int selectTeamId,int teamSumId)
    :x(x),y(y),delay(delay),baseCheck(checkbox),quickId(quickId),selectTeamId(selectTeamId),teamSumId(teamSumId)
{
    if(x==0||y==0||delay==0){
        enable =false;
    }else{
        enable = true;
    }
//    qDebug()<<"Position::Position() quickId :"<<this->quickId<<endl;
}

bool Position::isenable(){ //是否可用

    return this->enable;
}

Position::Position(QLineEdit* et_x,QLineEdit* et_y,QLineEdit* et_delay,QComboBox* cbx,QComboBox* quickbox,QComboBox* selectTeamBox,QComboBox* teamSumIdBox):
    Position(et_x->text().toInt(), et_y->text().toInt(),et_delay->text().toInt(),cbx->currentIndex(),quickbox->currentIndex(),selectTeamBox->currentIndex(),teamSumIdBox->currentIndex())
{
//    qDebug()<<"id======"<<quickbox->currentText()<<quickbox->currentIndex();
}

int Position::getX() const {
    return x;
}

void Position::setX(int x) {
    Position::x = x;
}

int Position::getY() const {
    return y;
}

void Position::setY(int y) {
    Position::y = y;
}

int Position::getDelay() const {
    return delay;
}

void Position::setDelay(int delay) {
    Position::delay = delay;
}

bool Position::exec(){

       bool  res = ADB::click(x,y);
       res =  ADB::sleep(2);
     return res;
}
void Position::setBaseCheck(int check){

    this->baseCheck = check;
}
int Position::getBaseCheck() const {

    return baseCheck;
}

bool Position::sleep(){
    bool res =  ADB::sleep(delay);
       qDebug()<<"delay yyyy :"<<delay<<endl;
    return res;
}
int Position::getQuickId() const {

    return quickId;
}
void Position::setQuickId(int quickId){
    this->quickId =quickId;
}
int Position::getSelectTeamId() const{
 return selectTeamId;
}
void Position::setSelectTeamId(int selectTeamId){
  this->selectTeamId =selectTeamId;
}
int Position::getTeamSumId() const{
 return teamSumId;
}
void Position::setTeamSumId(int teamSumId){
  this->teamSumId =teamSumId;
}


Position::~Position()
{



}
