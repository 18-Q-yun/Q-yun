#include "accountproxy.h"
#include "accountbroker.h"
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
AccountProxy::AccountProxy()
{

}
void AccountProxy::updatePassword(QString request)
{
    QJsonParseError request_json_error;
    QString userName, userPasword;
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
            if (obj.contains("userPassword"))
            {
                QJsonValue userPassword_value = obj.take("userPassword");
                if (userPassword_value.isString())
                {
                        userPasword = userPassword_value.toVariant().toString();
                }
            }


        }
    }
    AccountBroker accountBroker;
    accountBroker.updatePassword(userName,userPasword);

}
bool AccountProxy::verifyAccount(QString request)
{
    QJsonParseError request_json_error;
    QString userName,userPasword;
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
            if (obj.contains("userPassword"))
            {
                QJsonValue userPassword_value = obj.take("userPassword");
                if (userPassword_value.isString())
                {
                        userPasword = userPassword_value.toVariant().toString();
                }
            }


        }
    }
    AccountBroker accountBroker;

    return accountBroker.verifyAccount(userName,userPasword);
}
void AccountProxy::updateRemainSpace(QString request)
{
    QJsonParseError request_json_error;
    QString userName;
    int userRemainSpace;
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
            if (obj.contains("userRemainSpace"))
            {
                QJsonValue userRemainSpace_value = obj.take("userRemainSpace");
                if (userRemainSpace_value.isString())
                {
                        userRemainSpace = userRemainSpace_value.toVariant().toInt();
                }
            }


        }
    }
    AccountBroker accountBroker;
    accountBroker.updateRemainSpace(userName,userRemainSpace);

}
QString AccountProxy::applyAccount(QString request)
{
    QJsonParseError request_json_error;
    QString userName, userPasword;
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
            if (obj.contains("userPassword"))
            {
                QJsonValue userPassword_value = obj.take("userPassword");
                if (userPassword_value.isString())
                {
                        userPasword = userPassword_value.toVariant().toString();
                }
            }


        }
    }
    AccountBroker accountBroker;
    accountBroker.applyAccount(userName,userPasword);
    return userName;
}
