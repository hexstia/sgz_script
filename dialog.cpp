#include "dialog.h"
#include "ui_dialog.h"
#include "adb.h"
#include <QPushButton>
#include <QString>
#include "mainwindow.h"
#include "waitmainthread.h"
#include "configsave.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    ui->lab_toast->setStyleSheet("color:red");
    ui->lab_toast->setText("");

    setSlot();
    ConfigSave cs;
    if(cs.getCode()==nullptr||cs.getMac()==nullptr){
        qDebug()<<"hello "<<endl;
        return ;
    }
    NET_HTTP_request(cs.getCode(),cs.getMac());

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setWindow(MainWindow& win){

    this->window = &win;
}

void Dialog::setSlot(){

QPushButton::connect(ui->btn_ok,SIGNAL(clicked(bool)),this,SLOT(commit(bool)));

QPushButton::connect(ui->btn_cancle,SIGNAL(clicked(bool)),this,SLOT(commit(bool)));
}

void  Dialog::commit(bool flag){

    QPushButton *btn = qobject_cast<QPushButton *>(sender());//当前点击的按钮对象

    if(btn ==ui->btn_ok){

        QString code =   ui->et_code->text();
        if(code.isEmpty()){
            ui->lab_toast->setText("激活码 不能为空!");
            return ;
        }
         QString mac =  ADB::getHostMacAddress();
         NET_HTTP_request(code,mac);




    }else if(btn ==ui->btn_cancle){

            this->close();

    }

}
bool  Dialog::NET_HTTP_request(QString code,QString mac){

    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

    request.setUrl(QUrl("http://101.200.152.1:3000?mac="+mac+"&code="+code));
//    request.setUrl(QUrl("http://127.0.0.1:3000?mac="+mac+"&code="+code));

    QNetworkReply* reply = naManager->get(request);
    return true;
}


void Dialog::requestFinished(QNetworkReply* reply) {
    // 获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();


    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    QByteArray content;
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {
        // 获取返回内容
//        qDebug() << "bbb: "<<);
//        content = QString(reply->readAll());
          content = reply->readAll();
    }
    if(statusCode.toInt()==200){
           NetResData* data = parseJson(content);
           if(data!=nullptr){
             showWindow(data->getFlag(),data->getDay(),data->getReson());
             delete data;
           }else{
            showWindow(-1,0,"网络错误");
           }


    }else{
        showWindow(-1,0,"请检查网络，服务器异常");
    }
}
NetResData* Dialog::parseJson(QByteArray json){

    QJsonParseError err_rpt;
        QJsonDocument  root_Doc = QJsonDocument::fromJson(json, &err_rpt);//字符串格式化为JSON
        if(err_rpt.error != QJsonParseError::NoError)
        {
            qDebug() << "JSON格式错误";
            return nullptr;
        }
        else    //JSON格式正确
        {
            //        qDebug() << "JSON格式正确：\n" << root_Doc;
             QJsonObject root_Obj = root_Doc.object();
             int flag = root_Obj.value("flag").toInt();
             QString reason = root_Obj.value("reason").toString();
             int day = root_Obj.value("day").toInt();
                NetResData* data = new NetResData(flag,day,reason);
                return data;
        }
}



void Dialog::showWindow(int flag,int day,QString Reason){

    if(flag<0){
      ui->lab_toast->setText(Reason);
    }

    if(day<=0){

    }else if(day >0&&day < 1000){
        ui->lab_toast->setText(QString(Reason)+",剩余时长 "+QString::number(day)+"天！"); //没有设置等待时长
        window->setDay(day);
        window->show();
        this->close();
        ConfigSave cs;
        if(flag ==2){ //注册
            cs.putMac(ADB::getHostMacAddress());
            cs.putcode(ui->et_code->text());
        }else{
            cs.putMac(ADB::getHostMacAddress());
            if(!ui->et_code->text().isEmpty()){
                 cs.putcode(ui->et_code->text());
            }else{
                 cs.putcode(cs.getCode());
            }

        }
    }else{
    ui->lab_toast->setText("异常数据");
    }


}
