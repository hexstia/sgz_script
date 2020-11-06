#include "configsave.h"

ConfigSave::ConfigSave()
{
    setting = new QSettings(QCoreApplication::applicationDirPath()+"/config.ini",QSettings::IniFormat);
}

void ConfigSave::putMac(QString mac){
    setting->setValue(EncryptionStr("mac"),EncryptionStr(mac));
}
void ConfigSave::putcode(QString code){
    setting->setValue(EncryptionStr("code"),EncryptionStr(code));
}
QString ConfigSave::getMac(){
    return EncryptionStr(setting->value(EncryptionStr("mac")).toString());
}
QString ConfigSave::getCode(){
 return EncryptionStr(setting->value(EncryptionStr("code")).toString());
}
QString ConfigSave::EncryptionStr(QString str){
    std::wstring wString = str.toStdWString();
        static QByteArray key = ".....";
        for (int i = 0; i < wString.size(); i++)
        {
            wString[i] = wString[i] ^ key[i % key.size()];
        }
        return QString::fromStdWString(wString).toUtf8();
}
