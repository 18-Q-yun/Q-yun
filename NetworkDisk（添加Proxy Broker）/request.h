#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
class Request
{
public:
    Request(){}
    QString updatePassword(QString userName, QString userPassword);
    QString updateRemainSapce(QString userName, int remainSpace);
    QString verifyAccount(QString userName, QString userPassword);
    QString applyAccount(QString userName,QString userPassword);
    QString getUserResource(QString userName, int currentLevel, QString currentDirName);
//    QString findResource(QString userName);
//    QString checkUploadList(QString userName);
    QString getUserFolder(QString userName, int currentLevel, QString currentDirName);
    QString addResource(QString userName,int currentLevel,QString currentDirName,QString resourceName);
    QString addFolder(QString userName, int currentLevel, QString currentDirName,QString folderName);
    QString deleteFolder(QString userName,int currentLevel,QString currentDirName,QString folderName);
    QString deleteResource(QString userName,int currentLevel,QString currentDirName,QString resourceName);

};
#endif // ACCOUNT_H
