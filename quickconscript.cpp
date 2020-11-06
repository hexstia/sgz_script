#include "quickconscript.h"
#include "position.h"
#include "workthread.h"
//快速征兵
QuickConscript::QuickConscript(QObject *parent) : QObject(parent)
{

}
QuickConscript::QuickConscript(int width,int height,int density,int select_team_index){
    this->width = width;
    this->height = height;
    this->density = density;
    this->select_team_index = select_team_index;
    this->select_landMarkIndex = 0;

}

QuickConscript::QuickConscript(int width,int height,int density,int select_team_index,int select_landMarkIndex){
    this->width = width;
    this->height = height;
    this->density = density;
    this->select_team_index = select_team_index;
    this->select_landMarkIndex = select_landMarkIndex;
}
//选择地标
bool QuickConscript::click_landMark_option(){
    bool res = false;
    int basedp_x = 33;//距右边沿的差值 单位dp
    int basedp_y = 55;//距离上边沿的差值
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边沿的差值
    Position ps;
    int w =width<height?height:width;
    ps.setX(w-x);
    ps.setY(y);
    res = ps.exec();

    return res;
}
//选择地标
bool QuickConscript::select_landMark(){
    bool res = false;
    int basedp_x = 61;//距右边沿的差值 单位dp
    int basedp_y = 80;//距离上边沿的差值
    int x = basedp_x*(density/160) ;//距右边沿的差值 单位px
    int y = basedp_y*(density/160) ;//距离底边沿的差值
    Position ps;
    int w =width<height?height:width;
    ps.setX(w-x);
    ps.setY(y);
    res = ps.exec();

    return res;
}
//入城
bool QuickConscript::come_home(){
    bool res = false;

    Position ps;
    int w =width<height?height:width;
    int h =width>height?height:width;
    w =w/2;//水平的中心
    h = h/2;//垂直的中心
    int basedp_y = 17;//与中心点向上偏移17 dp
    int y = basedp_y*(density/160) ;//与中心点向上偏移17 dp 像素值
    h = h -y;
    ps.setX(w);
    ps.setY(h);
    res = ps.exec();
    return res;

}
//选择部队
bool QuickConscript::select_team(){
    int sumId = 5;
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
    int x =  startX+(select_team_index-1)*moduleSize;
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
//快速分兵
bool QuickConscript::quick_conscript(){
    int h =width>height?height:width;
    int w =width<height?height:width;
    int centerX = w/2;
    int basedp_x = 247;//距中心的差值 单位dp
    int basedp_y = 22;//距底边延的值 单位dp
    int x = basedp_x*(density/160) ;//距中心的差值 单位px
    int y = basedp_y*(density/160) ;//距底边延的差值

    y = h-y;
    x = centerX -x;
    Position ps;
    ps.setX(x);
    ps.setY(y);
    bool res =   ps.exec();
    return res;

}
//确认分兵
bool QuickConscript::commit_conscript(){
    int h =width>height?height:width;
    int w =width<height?height:width;
    int centerX = w/2;

    int basedp_x = -241;//距中心的差值 单位dp
    int basedp_y = 60;//距底边延的值 单位dp
    int x = basedp_x*(density/160) ;//距左边沿的值 单位px
    int y = basedp_y*(density/160) ;//距底边延的差值
    y = h-y;
    x = centerX-x;
    Position ps;
    ps.setX(x);
    ps.setY(y);
    bool res =   ps.exec();
    return res;


}
//返回功能（两次）
bool QuickConscript::goback(){
    int basedp_x = 35;//距右边沿的差值 单位dp
    int basedp_y = 15;//距底边延的值 单位dp
    int x = basedp_x*(density/160) ;//距右边沿的值 单位px
    int y = basedp_y*(density/160) ;//距底边延的差值
    int w =width<height?height:width;
    x = w-x;
    Position ps;
    ps.setX(x);
    ps.setY(y);
    bool res =   ps.exec();
    res =   ps.exec();
    return res;

}
//一次完整的分兵
bool QuickConscript::one_complete_quickConscript(){
    bool res =false;
    res = click_landMark_option();//点击地标选项
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }

    res =select_landMark();//选择地标
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    res = come_home();//选择地标
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    res = select_team();//选择部队
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    res =quick_conscript();//快速分兵
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    res = commit_conscript();//确认分兵
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
    res = goback();//返回功能（两次）
    if(!res)
        return res;
    if(WorkThread::isStop){
        return false;
    }
return res;
}

void QuickConscript::setWidth( int width){
    this->width = width;
}
void QuickConscript::setheight(int height){
    this->height = height;
}
void QuickConscript::setDensity(int density){
    this->density = density;
}
void QuickConscript::setSelect_team_index(int select_team_index){
    this->select_team_index = select_team_index;
}
void QuickConscript::setSelect_landMarkIndex(int select_landMarkIndex){
    this->select_landMarkIndex = select_landMarkIndex;
}
