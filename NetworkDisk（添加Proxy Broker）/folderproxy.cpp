#include "folderproxy.h"
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

QList<Folder> FolderProxy::getUserResource(QString request)
{
    QJsonParseError request_json_error;
    QString userName, currentLevel,currentDirName;
    //QTJSON所有的元素
    QJsonDocument request_doucment = QJsonDocument::fromJson(request.toUtf8(), &request_json_error);
    //检查json是否有错误
    if (request_json_error.error == QJsonParseError::NoError)
    {
        if (request_doucment.isObject())
        {
            //开始解析json对象
            QJsonObject obj = request_doucment.object();
            //如果包含userName
            if (obj.contains("userName"))
            {
                //的到name
                QJsonValue name_value = obj.take("userName");
                if (name_value.isString())
                {
                    //转换name
                    userName = name_value.toVariant().toString();
                }
            }
            if (obj.contains("currentLevel"))
            {
                QJsonValue currentlevel_value = obj.take("currentLevel");
                if (currentlevel_value.isString())
                {
                        currentLevel = currentlevel_value.toVariant().toString();
                }
            }
            if (obj.contains("currentDirName"))
            {
                QJsonValue currentdirname_value = obj.take("currentDirName");
                if (currentdirname_value.isString())
                {
                    currentDirName = currentdirname_value.toVariant().toString();
                }
            }

        }
    }
    FolderBroker folderBroker;
    QList<Folder> folders= folderBroker.getUserFolder(userName,currentLevel,currentDirName);
    return folders;
}

void FolderProxy::deleteFolder(QString request)
{
    QJsonParseError request_json_error;
    QString userName, currentLevel,currentDirName,folderName;
    //QTJSON所有的元素
    QJsonDocument request_doucment = QJsonDocument::fromJson(request.toUtf8(), &request_json_error);
    //检查json是否有错误
    if (request_json_error.error == QJsonParseError::NoError)
    {
        if (request_doucment.isObject())
        {
            //开始解析json对象
            QJsonObject obj = request_doucment.object();
            //如果包含userName
            if (obj.contains("userName"))
            {
                //的到name
                QJsonValue name_value = obj.take("userName");
                if (name_value.isString())
                {
                    //转换name
                    userName = name_value.toVariant().toString();
                }
            }
            if (obj.contains("currentLevel"))
            {
                QJsonValue currentlevel_value = obj.take("currentLevel");
                if (currentlevel_value.isString())
                {
                        currentLevel = currentlevel_value.toVariant().toString();
                }
            }
            if (obj.contains("currentDirName"))
            {
                QJsonValue currentdirname_value = obj.take("currentDirName");
                if (currentdirname_value.isString())
                {
                    currentDirName = currentdirname_value.toVariant().toString();
                }
            }
            if (obj.contains("folderName"))
            {
                QJsonValue foldername_value = obj.take("folderName");
                if (foldername_value.isString())
                {
                    folderName = foldername_value.toVariant().toString();
                }
            }

        }
    }
    FolderBroker folderBroker;
   folderBroker.deleteFolder(userName,currentLevel,currentDirName,folderName);
}

void FolderProxy::addFolder(QString request)
{
    QJsonParseError request_json_error;
    QString userName, currentLevel,currentDirName,folderName;
    //QTJSON所有的元素
    QJsonDocument request_doucment = QJsonDocument::fromJson(request.toUtf8(), &request_json_error);
    //检查json是否有错误
    if (request_json_error.error == QJsonParseError::NoError)
    {
        if (request_doucment.isObject())
        {
            //开始解析json对象
            QJsonObject obj = request_doucment.object();
            //如果包含userName
            if (obj.contains("userName"))
            {
                //的到name
                QJsonValue name_value = obj.take("userName");
                if (name_value.isString())
                {
                    //转换name
                    userName = name_value.toVariant().toString();
                }
            }
            if (obj.contains("currentLevel"))
            {
                QJsonValue currentlevel_value = obj.take("currentLevel");
                if (currentlevel_value.isString())
                {
                        currentLevel = currentlevel_value.toVariant().toString();
                }
            }
            if (obj.contains("currentDirName"))
            {
                QJsonValue currentdirname_value = obj.take("currentDirName");
                if (currentdirname_value.isString())
                {
                    currentDirName = currentdirname_value.toVariant().toString();
                }
            }
            if (obj.contains("folderName"))
            {
                QJsonValue foldername_value = obj.take("folderName");
                if (foldername_value.isString())
                {
                    folderName = foldername_value.toVariant().toString();
                }
            }

        }
    }
    FolderBroker folderBroker;
    folderBroker.addFolder(userName,currentLevel,currentDirName,folderName);

}
