#include "resourceproxy.h"
#include "resourcebroker.h"
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>
#include <QDebug>
using std::cout;
using std::endl;

QList<Resource> ResourceProxy::getUserResource(QString request)
{
    QJsonParseError request_json_error;
    QString userName,currentDirName;
    int  currentLevel;
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
                if (currentlevel_value.isDouble())
                {
                        currentLevel = currentlevel_value.toVariant().toInt();

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
    ResourceBroker resourceBroker;
    QList<Resource> resources= resourceBroker.getUserResource(userName,currentLevel,currentDirName);
    return resources;
}

void ResourceProxy::addResource(QString request)
{

    QJsonParseError request_json_error;
    QString userName, currentLevel,currentDirName;
    QList<QString> resourceNames;
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
                if (currentlevel_value.isDouble())
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

            if(obj.contains("resourceArray"))
            {
                QJsonValue resource_value=obj.take("resourceArray");
                if(resource_value.isArray()){
                    QJsonArray resourceArray=resource_value.toArray();
                    for(auto re:resourceArray){
                        QJsonValue resourceArrayValue=re;
                        if(resourceArrayValue.isString()){
                                resourceNames<<resourceArrayValue.toString();
                        }
                    }
                }
            }

        }
    }
    ResourceBroker resourceBroker;
    qDebug()<<"helo";
    for(int i=0;i!=resourceNames.size();++i){
        cout<<resourceNames[i].toStdString();

        resourceBroker.addResource(userName,resourceNames[i],currentDirName,currentLevel);

    }



}

