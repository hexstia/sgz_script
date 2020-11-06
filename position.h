#ifndef POSITION_H
#define POSITION_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDebug>
#include <QComboBox>
class Position
{
public:
    Position(); //:x(x),y(y),delay(delay)
    Position(int x,int y,int delay);
    Position(int x,int y,int delay,int checkbox,int quickId,int selectTeamId,int teamSumId); //:x(x),y(y),delay(delay)
    Position(QLineEdit* et_x,QLineEdit* et_y,QLineEdit* et_delay,QComboBox* cbx,QComboBox* quickbox,QComboBox* selectTeamBox,QComboBox* teamSumIdBox);
    ~Position();
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getDelay() const;

    void setDelay(int delay);

    bool isenable();

    bool exec();

    bool sleep();
    int getBaseCheck() const ;
    void setBaseCheck(int check);
    int getQuickId() const;
    void setQuickId(int quickId);


    int getSelectTeamId() const;
    void setSelectTeamId(int quickId);
    int getTeamSumId() const;
    void setTeamSumId(int quickId);



private:
     int x ;
     int y ;
     int delay;
     bool enable;
     int baseCheck;
     int quickId;
     int selectTeamId;
     int teamSumId;

};

#endif // POSITION_H
