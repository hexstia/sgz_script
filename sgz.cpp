#include "sgz.h"



#include <QThread>
#include <QDateTime>
#include "workthread.h"
#include "quickconscript.h"


Sgz::Sgz( QHash<QString,Position*>*  hash){
    this->hash = hash;
    center = new Position();

}
void Sgz::setWh(int width,int height){
    this->width = width;
    this->height = height;
    center->setX(width/2);
    center->setY(height/2);
}

void Sgz::setDensity(int density)
{

    this->density = density;
}

bool Sgz::getHashValue(QString key,Position* & pos){
    bool res;
    auto it_value=  hash->find(key);
    if(it_value !=hash->end()){
        Position* ele  =  it_value.value();
        int y = ele->getY();
        int x = ele->getX();
        int delay=ele->getDelay();
        int basecheck = ele->getBaseCheck();
        int quickId = ele->getQuickId();
        int selectTeamId = ele->getSelectTeamId();
        int teamSumId = ele->getTeamSumId();
        qDebug()<<" getHashValue() x :"<<x<<endl;
        qDebug()<<" getHashValue()y :"<<y<<endl;
        pos->setX(x);
        pos->setY(y);
        pos->setDelay(delay);
        pos->setBaseCheck(basecheck);
        pos->setQuickId(quickId);
        pos->setSelectTeamId(selectTeamId);
        pos->setTeamSumId(teamSumId);
        res = true;
    }else{
        res = false;
    }
    return res;

}
//开始前的等待时间
int Sgz::start_wait(){
    Position* ps = new Position();
    getHashValue("before_delay",ps);
    unsigned long second =static_cast<unsigned long>( ps->getDelay());
    qDebug()<<"second "<<second<<endl;
    if(second !=0){
        QThread::sleep(second);
        return 1; //如果有开始前等待，那么则size上减去该节点
    }else{
        return 0; //如果有开始前等待，那么则size上减去该节点
    }


    //    ps->sleep();
}
//土地
bool Sgz::land(int index,Position* &ps){

    bool res =  getHashValue("land"+QString::number(index),ps);

    if(!res)
        return res;
    res =ps->exec();

    return res;

}
/*
bool Sgz::land(int index,Position* &ps,int x,int y){

    //    bool res =  getHashValue("land"+QString::number(index),ps);
    //    if(moveX>0||moveY>0){
    //        ps->setX(ps->getX()-moveX);
    //        ps->setY(ps->getY()-moveY);
    //    }
    //    moveX =ps->getX() - x;
    //    moveY =ps->getY() - y;
    //    if(!res)
    //        return res;
    //    res =ps->exec();

    //    return res;
    return false;

}
*/
//攻占(空) ---1
bool Sgz::attack_occupy_unuse(){

    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_A_1;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击攻占"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;

    qDebug()<<"点击"<<"res : "<<res<<endl;
    return res;
}
//行军(空)-----2
bool Sgz::march_unuse(){

    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_A_2;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}
//攻占(敌)------1
bool Sgz::attack_occupy_foe(){

    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_1;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}
//行军(敌)---===2
bool Sgz::march_foe(){

    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_2;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}

//行军 (自己)-----2
bool Sgz::march_self(){

    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_2;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}

//驻守(自己)------3
bool Sgz::garrison_self(){

    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_3;//模块dp单位
    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}
//扫荡（自己）----4
bool Sgz::mopup_self(){
    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_4;//模块dp单位
    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}
//屯田（自己）---5
bool Sgz::cultivation_self(){
    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_5;//模块dp单位
    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}
//驻守(营)---4
bool Sgz::garrison_out(){
    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_4;//模块dp单位
    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}
//回城
bool Sgz::goHome(){
    bool res = false;
    int basedp_x = 40;//距右边沿的差值 单位dp
    int basedp_y = 115;//距离底边沿的差值
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边沿的差值
    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    ps.setX(w-x);
    ps.setY(h-y);
    res = ps.exec();

    return res;
}
//坚持出征
bool Sgz::persistAttack(){
    int basedp_x = -40;  //距离中心点的差值 单位dp
    int basedp_y = 59;   //距离中心点的差值
    int x = basedp_x*(density/160) ;//距离中心点的差值 单位px
    int y = basedp_y*(density/160) ;//距离中心点的差值
    Position ps;
    ps.setX(center->getX()+x);
    ps.setY(center->getY()+y);
    bool res = ps.exec();
    return res;
}

//调动(营)---2
bool Sgz::transfer_out(){
    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_2;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}

//调动(盟城)-----2
bool Sgz::transfer_friend(){
    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_2;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}

//驻守(盟城)-----4
bool Sgz::garrison_friend(){
    int basedp_x = BASE_X_OPTION_1;//模块dp单位
    int basedp_y = BASE_Y_OPTION_B_4;//模块dp单位

    int add_x = basedp_x*density/160 ;
    int add_y = basedp_y*density/160 ;
    int x = center->getX()+add_x; //攻占的坐标
    int y = center->getY()-add_y; //攻占的坐标

    Position* pao = new Position(x,y,0);
    qDebug()<<"点击行军"<<"X :"<<pao->getX()<<" Y :"<<pao->getY()<<endl;
    bool res = pao->exec();
    delete pao;
    //点击
    return res;
}


//选择英雄
bool Sgz::_select_hero(int index){

    Position* ps = new Position();
    bool res =  getHashValue("select_hero"+QString::number(index),ps);
    ps->exec();
    delete ps;
    return res;

}
//选择队伍
bool Sgz::select_team(int selectId,int sumId){
    sumId = sumId+1;
    qDebug()<<"selectId : "<<selectId <<endl;
    qDebug()<<"sumId : "<<sumId <<endl;
//    int moduleSize = width/5;//每一块的大小 px
    int moduleSizeDp = 125;
    int moduleSize = moduleSizeDp*(density/160) ;//距底边延的差值
    int centerX = width/2;//中心点
    int baseMove = moduleSize/2 ; //半块的px
    int totalmoduleSize =sumId*moduleSize; //总块数的尺寸
    //x起始坐标 =  总长度一半 - 总块数的尺寸一半
    int startX =centerX - (totalmoduleSize/2);
      startX = startX +baseMove;
    //当前X坐标
    int x =  startX+selectId*moduleSize;
    //Y
    int basedp_y = 34;//距底边延的值 单位dp
    int y = basedp_y*(density/160) ;//距底边延的差值
    int h =width>height?height:width;
    y = h-y;
    Position ps;
    ps.setX(x);
    ps.setY(y);
    bool res = ps.exec();
    return res;
}

//确认
bool  Sgz::commit(){
    int basedp_x = 184;  //距离中心点的差值 单位dp
    int basedp_y = 68;   //距离中心点的差值
    int x = basedp_x*(density/160) ;//距离中心点的差值 单位px
    int y = basedp_y*(density/160) ;//距离中心点的差值
    Position ps;
    ps.setX(center->getX()+x);
    ps.setY(center->getY()+y);
    bool res = ps.exec();

    return res;

}
//地图
bool  Sgz::openMap(){
    int basedp_x = 35;//距左边延的差值 单位dp
    int basedp_y = 92;//距离底边的差值
    int x = basedp_x*(density/160) ;//距左边延的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边的差值
    Position ps;
    ps.setX(x);
    int h =width>height?height:width;
    ps.setY(h-y);
    bool res = ps.exec();
    return res;

}

//地图页下点击X
bool  Sgz::map_x() {
    int basedp_x = 150;//距右边沿的差值 单位dp
    int basedp_y = 86;//距离底边沿的差值
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边沿的差值
    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    ps.setX(w-x);
    ps.setY(h-y);
    bool res = ps.exec();
    return res;

}
//地图页下点击Y
bool  Sgz::map_y() {
    int basedp_x = 91;//距右边沿的差值 单位dp
    int basedp_y = 86;//距离底边沿的差值
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边沿的差值
    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    ps.setX(w-x);
    ps.setY(h-y);
    bool res = ps.exec();
    return res;
}
//地图页下确认
bool  Sgz::map_commit() {
    int basedp_x = 32;//距右边沿的差值 单位dp
    int basedp_y = 86;//距离底边沿的差值
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边沿的差值
    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    ps.setX(w-x);
    ps.setY(h-y);
    bool res = ps.exec();
    return res;
}
//输入页下输入框
bool   Sgz::input_pos(){
    int basedp_x = 50;//距右边沿的差值 单位dp
    int basedp_y = 55;//
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//
    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    ps.setX(w-x);
    ps.setY(h-y);
    bool res = ps.exec();
    return res;
}
//输入页下完成
bool  Sgz::input_commit() {
    int basedp_x = 45;//距右边沿的差值 单位dp
    int basedp_y = 55;//
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//
    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    ps.setX(w-x);
    ps.setY(y);
    bool res = ps.exec();
    return res;
}

//输入页下完成
bool  Sgz::input_content(int x,int y) {

    emit updateText1("打开地图中。。。。。");
    openMap();

    emit updateText1("输入X坐标。。。。。");
    map_x();
    for(int i = 0;i<4;i++){
        ADB::input(67);//退格键
    }

    QString value = QString::number(x);
    ADB::input(value);//输入X
    //       ADB::sleep(2);
    input_commit();//完成
    emit updateText1("输入Y坐标。。。。。");
    map_y();
    for(int i = 0;i<4;i++){
        ADB::input(67);//退格键
    }
    ADB::input(QString::number(y));//输入Y
    //       ADB::sleep(2);
    emit updateText1("输入完成。。。。。");
    input_commit();//完成


    return map_commit();
}
//完成等待
bool Sgz::finish_wait(const Position* const pos,int index){
    //行军时间+攻占时间
    int attack_time = 1;

    //    int attack_time = 1;
    int delay = pos->getDelay();
    unsigned long second =static_cast<unsigned long>(attack_time+delay);
    //    Position* ps = new Position(0,0,pos->getDelay()+attack_time,false);
    //    bool res = ps->sleep();
    //    delete  ps;
    //     qDebug()<<"占领中等待 :"<<second <<endl;
    for(long i =0;i<second;i++){
        emit updateText1("坐标"+QString::number(index)+"：执行前,倒计时："+QString::number(second-i));
        QThread::sleep(1);
        if(WorkThread::isStop){
            delete pos;
            return false;
        }
    }
    delete pos;
    return true;
}

bool Sgz::select_Combobox_option_handle(int id){
    bool res = false;
    switch (id) {
    case 0://攻占新
        res = attack_occupy_unuse();
        break;
    case 1://行军新
        res = march_unuse();
        break;
    case 2://行军敌
        res = march_foe();
        break;
    case 3://攻占敌
        res = attack_occupy_foe();
        break;
    case 4://行军已
        res = march_self();
        break;
    case 5://驻守已
        res = garrison_self();
        break;
    case 6://扫荡已
        res = mopup_self();
        break;
    case 7://屯田已
        res = cultivation_self();
        break;
    case 8://驻守营
        res = garrison_out();
        break;
    case 9://调动营
        res = transfer_out();
        break;
    case 10://调动盟
        res = transfer_friend();
        break;
    case 11: //驻守盟
        res = garrison_friend();
        break;
    case 12: //回城
        res = goHome();
        break;
    }

    return res;
}
//一次完整的打地
bool Sgz::one_complete(int index,bool persiAttack){

    //上一次的x 和y
    //计算移动差值
    Position* ps = new Position();
    bool res =  getHashValue("land"+QString::number(index),ps);
    if(!res)
        return res;
    emit updateText1("坐标"+QString::number(index)+"：获取坐标数据---->完成");
    qDebug()<<"获取坐标------------完成"<<endl;
    int x = ps->getX();
    int y = ps->getY();
    int currentId = ps->getBaseCheck();
    int quickId = ps->getQuickId();
    int selectTeamId = ps->getSelectTeamId();
    int teamSumId = ps->getTeamSumId();
    qDebug()<<"currentId"<<currentId<<endl;
    qDebug()<<"getQuickId"<<quickId<<endl;
    //执行操作*******************************************************************
    //         emit updateText1("坐标"+QString::number(index)+"：执行前等待中。。。。");
    finish_wait(ps,index);
    //是否快速分兵
    if(quickId>0){
        QuickConscript qckcon(width,height,density,quickId);
        res= qckcon.one_complete_quickConscript();
        if(!res)
            return res;
        if(WorkThread::isStop){
            return false;
        }
    }

    emit updateText1("坐标"+QString::number(index)+"：执行前的等待---->完成");
    qDebug()<<"执行时间"+QString::number(index)+"----完成"<<endl;
    //地图上输入坐标  ，打开地图，点击X，输入x 完成 ，点击Y 输入Y，完成 确认，，，完成跳转坐标
    res = input_content(x,y);
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    emit updateText1("坐标"+QString::number(index)+"：跳转坐标 ：【"+QString::number(x)+","+QString::number(y)+"】");
    qDebug()<<"跳转坐标"+QString::number(index)+"----完成"<<endl;
    //选择下拉列表的选项处理 *********************************************

    res = select_Combobox_option_handle(currentId);
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    if(currentId ==ID_GOHOME){
        return true;
    }
    emit updateText1("坐标"+QString::number(index)+"：选项操作---->完成");
    qDebug()<<"选项操作"+QString::number(index)+"----完成"<<endl;
    //选择中间队伍 *********************************************
    res = select_team(selectTeamId,teamSumId);
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    emit updateText1("坐标"+QString::number(index)+"：选择队伍---->完成");
    qDebug()<<"选择队伍"+QString::number(index)+"----完成"<<endl;
    //确认攻占*********************************************/
    res = commit();
    if(!res)
        return res;
    emit updateText1("坐标"+QString::number(index)+"：确认攻占---->完成");
    qDebug()<<"确认攻占"+QString::number(index)+"----完成"<<endl;
    //坚持出征
    if(persiAttack){
        res = persistAttack();
    }
    return res;
}
int Sgz::getSize(){
    return this->hash->size();
}


Sgz::~Sgz(){

}

