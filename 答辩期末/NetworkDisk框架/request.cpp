#include "request.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

QString Request::updatePassword(QString userName,QString userPassword)
{
    QJsonObject requestObject;
    QString requestType="updatePassword";
    requestObject.insert("requestType",requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("userPassword",userPassword);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray=requestDocument.toJson(QJsonDocument::Compact);
    QString requestString(QString::fromLocal8Bit(requestArray));
    return requestString;
}

QString Request::updateRemainSapce(QString userName,int remainSpace)
{
    QJsonObject requestObject;
    QString requestType="updateRemainSapce";
    requestObject.insert("requestType",requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("userRemainSpace",remainSpace);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray=requestDocument.toJson(QJsonDocument::Compact);
    QString requestString(QString::fromLocal8Bit(requestArray));
    return requestString;
}

QString Request::verifyAccount(QString userName, QString userPassword)//验证账户，同时将帐号类封装成JSON对象，以便传输给服务器。后续代码同理
{
    QJsonObject requestObject;
    QString requestType="verifyAccount";
    requestObject.insert("requestType",requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("userPassword",userPassword);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray=requestDocument.toJson(QJsonDocument::Compact);
    QString requestString(QString::fromLocal8Bit(requestArray));
    return requestString;
}

QString Request::applyAccount(QString userName, QString userPassword)
{
    QJsonObject requestObject;
    QString requestType="applyAccount";
    requestObject.insert("requestType",requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("userPassword",userPassword);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray=requestDocument.toJson(QJsonDocument::Compact);
    QString requestString(QString::fromLocal8Bit(requestArray));
    return requestString;
}

QString Request::getUserResource(QString userName,int currentLevel,QString currentDirName)
{
    QJsonObject requestObject;
    QString requestType="getUserResource";
    requestObject.insert("requestType",requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("currentDirName",currentDirName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray=requestDocument.toJson(QJsonDocument::Compact);
    QString requestString(QString::fromLocal8Bit(requestArray));
    return requestString;

}

//QString Request::findResource(QString userName)
//{

//}

QString Request::getUserFolder(QString userName,int currentLevel,QString currentDirName)
{
    QJsonObject requestObject;
    QString requestType="getUserFolder";
    requestObject.insert("requestType",requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("currentDirName",currentDirName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray=requestDocument.toJson(QJsonDocument::Compact);
    QString requestString(QString::fromLocal8Bit(requestArray));
    return requestString;

}

QString Request::addResource(QString userName,int currentLevel,QString currentDirName,QString resourceName)
{
    QJsonObject requestObject;
    QString requestType="addResource";
    requestObject.insert("userName",userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("resourceName",resourceName);
    requestObject.insert("currentDirName",currentDirName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray  requestArray= requestDocument.toJson(QJsonDocument::Compact);
    QString  requestString(QString::fromLocal8Bit( requestArray));
    return requestString;
}

QString Request::addFolder(QString userName,int currentLevel,QString currentDirName,QString folderName)
{
    QJsonObject requestObject;
    QString requestType="addFolder";
    requestObject.insert("requestType", requestType);
    requestObject.insert("userName", userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("folderName",folderName);
    requestObject.insert("currentDirName",currentDirName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray  requestArray= requestDocument.toJson(QJsonDocument::Compact);
    QString  requestString(QString::fromLocal8Bit( requestArray));
    return requestString;
}

QString Request::deleteFolder(QString userName, int currentLevel,QString currentDirName, QString folderName)
{
    QJsonObject requestObject;
    QString requestType="deleteFolder";
    requestObject.insert("userName",userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("folderName",folderName);
    requestObject.insert("currentDirName",currentDirName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray  requestArray= requestDocument.toJson(QJsonDocument::Compact);
    QString  requestString(QString::fromLocal8Bit( requestArray));
    return requestString;
}

QString Request::deleteResource(QString userName, int currentLevel,QString currentDirName, QString resourceName)
{
    QJsonObject requestObject;
    QString requestType="deleteResource";
    requestObject.insert("userName",userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("resourceName",resourceName);
    requestObject.insert("currentDirName",currentDirName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray     requestArray= requestDocument.toJson(QJsonDocument::Compact);
    QString  requestString(QString::fromLocal8Bit(    requestArray));
    return requestString;
}

QString Request::uploadResource(QString userName, int currentLevel, QString currentDirName, QList<QString> resourceName)
{
    QJsonObject requestObject;
    QString requestType="uploadResource";
    requestObject.insert("requestType", requestType);
    requestObject.insert("userName",userName);
    requestObject.insert("currentLevel",currentLevel);
    requestObject.insert("currentDirName",currentDirName);
    QJsonArray resourceArray;
    for(int i = 0; i != resourceName.size(); i++)
        resourceArray.insert(i, resourceName[i]);
    requestObject.insert("resourceArray", resourceArray);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray= requestDocument.toJson(QJsonDocument::Compact);
    QString  requestString(QString::fromLocal8Bit(requestArray));
    return requestString;
}

QString Request:: downloadResource(QString userName)
{
    QJsonObject requestObject;
    QString requestType="downloadResource";
    requestObject.insert("requestType", requestType);
    requestObject.insert("userName", userName);
    QJsonDocument requestDocument;
    requestDocument.setObject(requestObject);
    QByteArray requestArray= requestDocument.toJson(QJsonDocument::Compact);
    QString  requestString(QString::fromLocal8Bit(requestArray));
    return requestString;
}

