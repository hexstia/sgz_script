#ifndef CONFIGSAVE_H
#define CONFIGSAVE_H

#include <QSettings>
#include <QString>
#include <QCoreApplication>
class ConfigSave
{
public:
    ConfigSave();
    void putMac(QString mac);
    void putcode(QString code);
    QString getMac();
    QString getCode();
    QString EncryptionStr(QString str);
private:
    QSettings* setting;
};

#endif // CONFIGSAVE_H
