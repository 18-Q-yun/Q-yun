#include <string>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>
#include <cstring>
#include "action.h"
#include "folder.h"
#include "localfolder.h"
#include "resourcetransmission.h"
#include "accountproxy.h"
#include "folderproxy.h"
#include "resourceproxy.h"

using namespace boost::asio;
using std::cout; using std::endl;
using std::string;

void Action::selectWay()
{
    char str[1024];

    try{
        _sock.read_some(buffer(str));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
        cout << "client exit!" << endl;
        return;
    }

    string request = str;
    QString qRequest = QString::fromStdString(request);
    request = analysisRequest(qRequest);
    cout << "the act is " << request << endl;

    if(request == "downloadResource") {
        AccountProxy accountProxy;
        QString userName=accountProxy.applyAccount(qRequest);
        string suserName = userName.toStdString();
        download(suserName);
        selectWay();
    }
    if(request == "uploadResource"){
        AccountProxy accountProxy;
        QString userName=accountProxy.applyAccount(qRequest);
        string suserName = userName.toStdString();
        upload(suserName);
        ResourceProxy resourceProxy;
        resourceProxy.addResource(qRequest);
        selectWay();
    }

    if(request=="applyAccount"){

        AccountProxy accountProxy;
        FolderProxy folderProxy;
        QString userName=accountProxy.applyAccount(qRequest);
        QString first="firstApply "+userName;
        folderProxy.addFolder(first);
        createUserResourceFolder(userName);
        selectWay();
    }
    if(request=="verifyAccount"){
        AccountProxy accountProxy;
        if(accountProxy.verifyAccount(qRequest)){
            string verify = "success";
            verify.copy(str, verify.size());
            *(str + verify.size()) = '\0';
            _sock.write_some(buffer(str, 1024));
            selectWay();
        }else{
            string verify = "fail";
            verify.copy(str, verify.size());
            *(str + verify.size()) = '\0';
            _sock.write_some(buffer(str, 1024));
            selectWay();
        }
    }

    if(request=="getUserFolder"){
        FolderProxy folderProxy;
        QList<Folder> folders=folderProxy.getUserFolder(qRequest);
        auto size = folders.length();
        string s = std::to_string(size);
        s.copy(str,s.size(),0);
        *(str + s.size()) = '\0';
        _sock.write_some(buffer(str, 1024));

        int i = 0;
        while(i != folders.length())
        {
            string flag = "again";
            memset(str, 0, 1024);
            string folderName =  folders[i].getFolderName().toStdString();

            folderName.copy(str, folderName.size(), 0);
            *(str + folderName.size()) = '\0';
            cout << str <<endl;
            while(flag == "again") {
                try{
                    _sock.write_some(buffer(str,1024));
                    _sock.read_some(buffer(str, 1024));
                } catch(std::exception& _e) {
                    cout << _e.what() << endl;
                }
                flag = str;
            }
            i++;
        }

        selectWay();
    }

    if(request=="addFolder"){
        FolderProxy folderProxy;
        folderProxy.addFolder(qRequest);
        selectWay();
    }
}

string Action::analysisRequest(QString jsonHeader)
{
    QString jsonRequest;
    QJsonParseError jsonerror;
    QJsonDocument requestDocument = QJsonDocument::fromJson(jsonHeader.toUtf8(),&jsonerror);
    if(jsonerror.error == QJsonParseError::NoError){

        if(requestDocument.isObject()){
            QJsonObject ob = requestDocument.object();

            if(ob.contains("requestType")){
                QJsonValue value = ob.take("requestType");

                if(value.isString()){
                    jsonRequest = value.toVariant().toString();

                }
            }
        }

    }
    string request = string((const char*)jsonRequest.toLocal8Bit());
    return request;
}

void Action::download(string userName)
{
    cout << __FUNCTION__ << endl;
    ResourceTransmission rt;
    rt.serverDownloadResource(_sock, userName);
}

void Action::upload(std::string userName)
{
    cout << __FUNCTION__ << endl;

    ResourceTransmission rt;
    rt.serverUploadResources(_sock, userName);
}

void Action::createUserResourceFolder(QString userName)
{
    LocalFolder localFolder;
    string suserName = userName.toStdString();
    string resourcePath = "/root/云盘用户文件/";
    resourcePath += suserName;
    cout <<resourcePath << endl;
    bool flag = localFolder.exitDirectory(resourcePath);
    if(!flag)
        flag = localFolder.createDirectory(resourcePath);

    string videoResourcePath = resourcePath + "/视频";
    string audioResourcePath = resourcePath + "/音频";
    string picResourcePath = resourcePath + "/图片";
    string docResourcePath = resourcePath + "/文档";
    string otherResourcePath = resourcePath + "/其他";

    flag = localFolder.exitDirectory(videoResourcePath);
    if(!flag)
        flag = localFolder.createDirectory(videoResourcePath);

    flag = localFolder.exitDirectory(audioResourcePath);
    if(!flag)
        flag = localFolder.createDirectory(audioResourcePath);

    flag = localFolder.exitDirectory(picResourcePath);
    if(!flag)
        flag = localFolder.createDirectory(picResourcePath);

    flag = localFolder.exitDirectory(docResourcePath);
    if(!flag)
        flag = localFolder.createDirectory(docResourcePath);

    flag = localFolder.exitDirectory(otherResourcePath);
    if(!flag)
        flag = localFolder.createDirectory(otherResourcePath);
}


