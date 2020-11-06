#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include "position.h"
#include <QPushButton>
#include <QComboBox>
#include "workthread.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void findAllView();
    void initLineEdit( QLineEdit * et_pos_xs);
    void initLineEdit( QLineEdit ** et_pos_xs,int lenth);
    void initPushButton();
    void getData();
    void setDay(int day);

   private slots:
   void clickListen1(bool flag);
    void showMessage(QString message);


private:
    Ui::MainWindow *ui;
    QHash<QString,Position*> *hash;
    QLineEdit ** et_pos_xs;
    QLineEdit ** et_pos_ys;
    QLineEdit ** et_pos_delays;
    QComboBox ** et_pos_comboBox;
    QComboBox ** et_quickcon_comboBox;
    QComboBox ** et_select_team_comboBox;
    QComboBox ** et_sum_team_comboBox;
    WorkThread* wk_start;
    WorkThread* wk_scrcpy;
    int useDay;
};

#endif // MAINWINDOW_H
