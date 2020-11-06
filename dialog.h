#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <netresdata.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setSlot();
    void setWindow(MainWindow& mw);
    bool NET_HTTP_request(QString code,QString mac);
    static bool startWindow;
 private slots:
    void commit(bool flag);
    void requestFinished(QNetworkReply* reply);
    void showWindow(int flag ,int day,QString Reason);
    NetResData* parseJson(QByteArray json);

private:
    Ui::Dialog *ui;
    MainWindow* window;

};

#endif // DIALOG_H
