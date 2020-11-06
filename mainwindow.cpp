#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "device.h"
#include "workthread.h"
#include "sgz.h"
#include "dialog.h"
void MainWindow::clickListen1(bool flag){
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    Device* device = new Device();

    if(btn==ui->btn_flush){
        device->connect();
        QString x;
        ;

        ui->dev_x->setText(x.number(device->getWidth()));
        ui->dev_y->setText(x.number(device->getHeight()));
        ui->dev_status->setText(*device->getName()+"      " + (*device->getStatus()));
        //        QPalette pe;
        //        pe.setColor(QPalette::Text,Qt::green); //const QColor &acolor
        //        ui->dev_status->setPalette(pe);
        //        ui->dev_status->setAutoFillBackground(true);
        //        btn->setFlat(true);
        ui->dev_size->setText("1080");
        delete device;
    }
    if(btn==ui->btn_scrcpy){
        std::shared_ptr<Device> devs(device);
        wk_scrcpy = new WorkThread(devs,WorkThread::SCRCPY_ID,ui->dev_size->text().toInt());
        wk_scrcpy->start();
        delete  device;
    }

    if(btn==ui->btn_start_exec){//开始点击
        device->connect();
        if(device->isOnline()){ //在线
            hash->clear();
            getData();
            bool persiAttack = ui->checkBox->isChecked();
            std::shared_ptr<Sgz> s = std::make_shared<Sgz>(hash);
            s->setWh(device->getWidth(),device->getHeight());
            s->setDensity(device->getDensity());
            WorkThread* wk_start = new WorkThread(s,1);
            wk_start->setPersiAttack(persiAttack);
            connect(wk_start,SIGNAL(updateText(QString)),this,SLOT(showMessage(QString)));
            wk_start->start();
            qDebug()<<"haha "<< endl;
            //            wk->wait();

        }else{
            qDebug()<<"设备属于离线状态"<<endl;
        }
        //        device->initData();
        //        WorkThread* wk = new WorkThread(device);
        //         wk->start();


    }

    if(btn==ui->btn_stop_exec){
        hash->clear();

        if(wk_start!=nullptr){
            //              qDebug()<<"wk_start closeThread"<<endl;
            wk_start->closeThread();
            //              qDebug()<<"wk_start->wait()"<<endl;
            //            wk_start->wait();
            //            delete wk_start;
        }
        qDebug()<<"wk_scrcpy"<<endl;
        if(wk_scrcpy!=nullptr){
            wk_scrcpy->closeThread();
            //            wk_scrcpy->wait();
            //            delete wk_scrcpy;
        }
    }


}


void MainWindow::showMessage(QString message){
    ui->label_4->setStyleSheet("color:green");
    ui->label_4->setText(message);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    findAllView();
    initPushButton();

}



void MainWindow::initPushButton(){
    QPushButton::connect( ui->btn_flush,SIGNAL(clicked(bool)),this,SLOT(clickListen1(bool)));
    QPushButton::connect( ui->btn_scrcpy,SIGNAL(clicked(bool)),this,SLOT(clickListen1(bool)));
    QPushButton::connect( ui->btn_start_exec,SIGNAL(clicked(bool)),this,SLOT(clickListen1(bool)));
    QPushButton::connect( ui->btn_stop_exec,SIGNAL(clicked(bool)),this,SLOT(clickListen1(bool)));
}



MainWindow::~MainWindow()
{


    delete ui;
}

void MainWindow::initLineEdit( QLineEdit * et_pos_x){


}
void MainWindow::initLineEdit( QLineEdit ** ets,int lenth){
    for (int i =0 ;i<lenth;i++) {
        ets[i]->setValidator(new QIntValidator(0,9999,this));
    }
}


void MainWindow::findAllView(){

    ui->label_4->setStyleSheet("color:red");
    ui->label_6->setStyleSheet("color:red");
    ui->label_10->setStyleSheet("color:red");
    ui->label_11->setStyleSheet("color:red");
    ui->label_12->setStyleSheet("color:red");
    ui->label_42->setStyleSheet("color:red");
    ui->label_46->setStyleSheet("color:red");

    this->hash = new QHash<QString,Position*>();
    et_pos_xs = new  QLineEdit *[12];
    et_pos_ys = new  QLineEdit *[12];
    et_pos_delays = new  QLineEdit *[12];
    et_pos_comboBox = new QComboBox *[12];
    et_quickcon_comboBox = new QComboBox *[12];
    et_select_team_comboBox = new QComboBox *[12];
    et_sum_team_comboBox = new QComboBox *[12];
    int i = 0;
    et_pos_xs[i++] =ui->et_pos_x;
    et_pos_xs[i++] =ui->et_pos_x_1;
    et_pos_xs[i++] =ui->et_pos_x_2;
    et_pos_xs[i++] =ui->et_pos_x_3;
    et_pos_xs[i++] =ui->et_pos_x_4;
    et_pos_xs[i++] =ui->et_pos_x_5;
    et_pos_xs[i++] =ui->et_pos_x_6;
    et_pos_xs[i++] =ui->et_pos_x_7;
    et_pos_xs[i++] =ui->et_pos_x_8;
    et_pos_xs[i++] =ui->et_pos_x_9;
    et_pos_xs[i++] =ui->et_pos_x_10;
    et_pos_xs[i++] =ui->et_pos_x_11;
    i = 0;
    et_pos_ys[i++] =ui->et_pos_y;
    et_pos_ys[i++] =ui->et_pos_y_1;
    et_pos_ys[i++] =ui->et_pos_y_2;
    et_pos_ys[i++] =ui->et_pos_y_3;
    et_pos_ys[i++] =ui->et_pos_y_4;
    et_pos_ys[i++] =ui->et_pos_y_5;
    et_pos_ys[i++] =ui->et_pos_y_6;
    et_pos_ys[i++] =ui->et_pos_y_7;
    et_pos_ys[i++] =ui->et_pos_y_8;
    et_pos_ys[i++] =ui->et_pos_y_9;
    et_pos_ys[i++] =ui->et_pos_y_10;
    et_pos_ys[i++] =ui->et_pos_y_11;
    i = 0;
    et_pos_delays[i++] =ui->et_delay;
    et_pos_delays[i++] =ui->et_delay_1;
    et_pos_delays[i++] =ui->et_delay_2;
    et_pos_delays[i++] =ui->et_delay_3;
    et_pos_delays[i++] =ui->et_delay_4;
    et_pos_delays[i++] =ui->et_delay_5;
    et_pos_delays[i++] =ui->et_delay_6;
    et_pos_delays[i++] =ui->et_delay_7;
    et_pos_delays[i++] =ui->et_delay_8;
    et_pos_delays[i++] =ui->et_delay_9;
    et_pos_delays[i++] =ui->et_delay_10;
    et_pos_delays[i++] =ui->et_delay_11;
    i = 0;
    et_pos_comboBox[i++] =ui->cbb;
    et_pos_comboBox[i++] =ui->cbb1;
    et_pos_comboBox[i++] =ui->cbb2;
    et_pos_comboBox[i++] =ui->cbb3;
    et_pos_comboBox[i++] =ui->cbb4;
    et_pos_comboBox[i++] =ui->cbb5;
    et_pos_comboBox[i++] =ui->cbb6;
    et_pos_comboBox[i++] =ui->cbb7;
    et_pos_comboBox[i++] =ui->cbb8;
    et_pos_comboBox[i++] =ui->cbb9;
    et_pos_comboBox[i++] =ui->cbb10;
    et_pos_comboBox[i++] =ui->cbb11;
    i = 0;
    et_quickcon_comboBox[i++] =ui->cb_qk;
    et_quickcon_comboBox[i++] =ui->cb_qk1;
    et_quickcon_comboBox[i++] =ui->cb_qk2;
    et_quickcon_comboBox[i++] =ui->cb_qk3;
    et_quickcon_comboBox[i++] =ui->cb_qk4;
    et_quickcon_comboBox[i++] =ui->cb_qk5;
    et_quickcon_comboBox[i++] =ui->cb_qk6;
    et_quickcon_comboBox[i++] =ui->cb_qk7;
    et_quickcon_comboBox[i++] =ui->cb_qk8;
    et_quickcon_comboBox[i++] =ui->cb_qk9;
    et_quickcon_comboBox[i++] =ui->cb_qk10;
    et_quickcon_comboBox[i++] =ui->cb_qk11;

    i = 0;
    et_select_team_comboBox[i++] =ui->cb_select_0;
    et_select_team_comboBox[i++] =ui->cb_select_1;
    et_select_team_comboBox[i++] =ui->cb_select_2;
    et_select_team_comboBox[i++] =ui->cb_select_3;
    et_select_team_comboBox[i++] =ui->cb_select_4;
    et_select_team_comboBox[i++] =ui->cb_select_5;
    et_select_team_comboBox[i++] =ui->cb_select_6;
    et_select_team_comboBox[i++] =ui->cb_select_7;
    et_select_team_comboBox[i++] =ui->cb_select_8;
    et_select_team_comboBox[i++] =ui->cb_select_9;
    et_select_team_comboBox[i++] =ui->cb_select_10;
    et_select_team_comboBox[i++] =ui->cb_select_11;
    i = 0;
    et_sum_team_comboBox[i++] =ui->cb_sum_0;
    et_sum_team_comboBox[i++] =ui->cb_sum_1;
    et_sum_team_comboBox[i++] =ui->cb_sum_2;
    et_sum_team_comboBox[i++] =ui->cb_sum_3;
    et_sum_team_comboBox[i++] =ui->cb_sum_4;
    et_sum_team_comboBox[i++] =ui->cb_sum_5;
    et_sum_team_comboBox[i++] =ui->cb_sum_6;
    et_sum_team_comboBox[i++] =ui->cb_sum_7;
    et_sum_team_comboBox[i++] =ui->cb_sum_8;
    et_sum_team_comboBox[i++] =ui->cb_sum_9;
    et_sum_team_comboBox[i++] =ui->cb_sum_10;
    et_sum_team_comboBox[i++] =ui->cb_sum_11;


    initLineEdit(et_pos_xs,12);
    initLineEdit(et_pos_ys,12);
    initLineEdit(et_pos_delays,12);
    ui->dev_status->setReadOnly(true);
    ui->dev_x->setReadOnly(true);
    ui->dev_y->setReadOnly(true);
    initLineEdit(ui->et_before_delay);
}


void MainWindow::getData(){
    int i = 0;
    for (i=0;i<12;i++) {
        //        Position
        if(et_pos_xs[i]->text()!=nullptr&&et_pos_ys[i]->text()!=nullptr&&et_pos_delays[i]->text()!=nullptr){
            hash->insert(QString("land") + QString::number(i),       \
   new Position(et_pos_xs[i],et_pos_ys[i],et_pos_delays[i],           \
                et_pos_comboBox[i],et_quickcon_comboBox[i],            \
                et_select_team_comboBox[i],et_sum_team_comboBox[i]));

        }else if(et_pos_xs[i]->text()==nullptr&&et_pos_ys[i]->text()==nullptr&&et_pos_delays[i]->text()==nullptr){

            qDebug()<<"土地截至坐标"<<i<<endl;
            break;
        }else{
            qDebug()<<"土地跳过坐标"<<i<<endl;
        }
    }

    if(ui->et_before_delay->text()!=nullptr){
        hash->insert(QString("before_delay"),new Position(0,0,ui->et_before_delay->text().toInt()));
    }else {
        qDebug()<<"铺路前等待 跳过坐标"<<i<<endl;
    }

}

void MainWindow::setDay(int day){

    this->useDay = day;
    ui->lab_day->setText(QString::number(useDay)+"天");


}


