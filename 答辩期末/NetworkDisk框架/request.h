#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QObject>

class Request: public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE Request(){}
    Q_INVOKABLE QString updatePassword(QString userName, QString userPassword);
    Q_INVOKABLE QString updateRemainSapce(QString userName, int remainSpace);
    Q_INVOKABLE QString verifyAccount(QString userName, QString userPassword);
    Q_INVOKABLE QString applyAccount(QString userName,QString userPassword);
    Q_INVOKABLE QString getUserResource(QString userName, int currentLevel, QString currentDirName);
    //   Q_INVOKABLE  QString findResource(QString userName);
    //   Q_INVOKABLE  QString checkUploadList(QString userName);
    Q_INVOKABLE QString getUserFolder(QString userName, int currentLevel, QString currentDirName);
    Q_INVOKABLE QString addResource(QString userName,int currentLevel,QString currentDirName,QString resourceName);
    Q_INVOKABLE QString addFolder(QString userName, int currentLevel, QString currentDirName,QString folderName);
    Q_INVOKABLE QString deleteFolder(QString userName,int currentLevel,QString currentDirName,QString folderName);
    Q_INVOKABLE QString deleteResource(QString userName,int currentLevel,QString currentDirName,QString resourceName);

    Q_INVOKABLE QString uploadResource(QString userName, int currentLevel, QString currentDirName, QList<QString> resourceName);
    Q_INVOKABLE QString downloadResource(QString userName);


};
#endif // ACCOUNT_H
