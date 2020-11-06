#ifndef QUICKCONSCRIPT_H
#define QUICKCONSCRIPT_H

#include <QObject>
class QuickConscript : public QObject
{
    Q_OBJECT
public:
    explicit QuickConscript(QObject *parent = nullptr);
    QuickConscript(int width,int height,int density,int select_team_index);
    QuickConscript(int width,int height,int density,int select_team_index,int select_landMarkIndex);
    bool click_landMark_option();//点击地标选项
    bool select_landMark();//选择地标
    bool come_home();//选择地标
    bool select_team();//选择部队
    bool quick_conscript();//快速分兵
    bool commit_conscript();//确认分兵
    bool goback();//返回功能（两次）
    bool one_complete_quickConscript();//一次完整的分兵
    void setWidth( int width);
    void setheight(int height);
    void setDensity(int density);
    void setSelect_team_index(int select_team_index);
    void setSelect_landMarkIndex(int select_landMarkIndex);

private:
    int width;
    int height;
    int density;
    int select_team_index;
    int select_landMarkIndex;

signals:

public slots:


};

#endif // QUICKCONSCRIPT_H
