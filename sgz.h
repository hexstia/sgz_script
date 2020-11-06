#ifndef SGZ_H
#define SGZ_H

#include "position.h"
#include <QThread>

class Sgz:public QObject
{


    Q_OBJECT
public:
    Sgz( QHash<QString,Position*>*  hash);
    void setWh(int width,int height);
    void setDensity(int density);
    int start_wait();//开始前的等待时间
    bool land(int index,Position* &ps);//土地
//    bool land(int index,Position* &ps,int x,int y);//土地

    bool attack_occupy_unuse();//攻占
    bool march_unuse();//行军

    bool attack_occupy_foe();//攻占
    bool march_foe();//行军



    bool march_self();//行军
    bool garrison_self();//驻守
    bool mopup_self();//扫荡
    bool cultivation_self();//屯田

    bool garrison_out();//驻守(营)
    bool transfer_out();//调动(营)

    bool transfer_friend();//调动(盟)
    bool garrison_friend();//驻守（盟）


    bool _select_hero(int index);//选择英雄
    bool select_team(int selectTeamId,int teamSumId);//选择队伍
    bool commit();//确认
    bool openMap();//打开地图
    bool map_x();//地图页下点击X
    bool map_y();//地图页下点击Y
    bool map_commit();//地图页下确认
    bool input_pos();//输入页下输入框
    bool input_commit();//输入页下完成
    bool input_content(int x, int y);
    bool finish_wait(const Position* const p,int index);//完成等待
    bool goHome();//回城
    bool persistAttack();//坚持出征
    bool one_complete(int index,bool persiAttack); //一次完整的打地
    bool select_Combobox_option_handle(int id);
    bool getHashValue(QString key,Position* & pos);
    int getSize();
    ~Sgz();


private:
    QHash<QString,Position*> *hash;
    int width;
    int height;
    int density;
    Position* center;
    //====================================
    const int BASE_X_OPTION_1 = 113;
    const int BASE_Y_OPTION_A_1 = 67+20;
    const int BASE_Y_OPTION_A_2 = 37+20;
    const int BASE_Y_OPTION_B_1 = 42+20;
    const int BASE_Y_OPTION_B_2 = 12+20;
    const int BASE_Y_OPTION_B_3 = -18+20;
    const int BASE_Y_OPTION_B_4 = -48+20;
    const int BASE_Y_OPTION_B_5 = -78+20;
    const int ID_GOHOME = 12;
signals:
    void updateText1(QString message);
};

#endif // SGZ_H
