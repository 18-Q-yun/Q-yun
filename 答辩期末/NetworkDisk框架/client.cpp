#include "client.h"
#include "resourcetransmissio.h"
#include <boost/thread.hpp>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

using namespace boost::asio;
using std::cout; using std::endl;
using std::string;

#define dataLength 1024

Client::Client()
{
    _sock = std::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(_io));
    _uploadSock = std::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(_io));
    _downloadSock = std::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(_io));
    try{
        _sock->async_connect(ip::tcp::endpoint(ip::address::from_string("10.253.188.20"), 2001), [](const boost::system::error_code &err){if(!err)cout << "Connect successful!" << endl;});
        _uploadSock->async_connect(ip::tcp::endpoint(ip::address::from_string("10.253.188.20"), 2001), [](const boost::system::error_code &err){if(!err)cout << "Connect successful!" << endl;});
        _downloadSock->async_connect(ip::tcp::endpoint(ip::address::from_string("10.253.188.20"), 2001), [](const boost::system::error_code &err){if(!err)cout << "Connect successful!" << endl;});
        _io.run();
        _io.run();
        _io.run();
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
}

void Client::registerUser()
{
    cout << __FUNCTION__ << endl;
    sendRequest();
}

int Client::loginSystem()
{
    cout << __FUNCTION__ << endl;

    sendRequest();
    char act[dataLength];

    try{
        _sock->read_some(buffer(act, dataLength));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    string loginFlag = act;
    if(loginFlag == "success") {
        return 1;
    }else if(loginFlag == "fail") {
        return 0;
    }
}

QList<QString> Client::getUserFolder()
{
    cout << __FUNCTION__ << endl;

    sendRequest();
    char act[dataLength];

    QList<QString> qfolderNames;
    int ilength;
    string slength;
    try{
        _sock->read_some(buffer(act, dataLength));
        slength = act;
        ilength = std::stoi(slength);
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    memset(act, 0, dataLength);

    string flag = "false";
    int i = 0;
    while(i != ilength) {
        memset(act, 0, dataLength);
        string sfolder;
        while(flag == "false") {
            _sock->read_some(buffer(act, dataLength));
            sfolder = act;
            if(sfolder == "")
                _sock->write_some(buffer("again"));
            else {
                _sock->write_some(buffer("ok"));
                flag = "true";
            }
        }

        QString qfolder = QString::fromStdString(sfolder);
        if(qfolder[qfolder.size() - 1] != 'D' && qfolder[qfolder.size() - 2] != ':')
            qfolder += ":" + verifyResourceType(qfolder);

        qfolderNames.push_back(qfolder);
        flag = "false";
        i++;
    }
    for(auto re:qfolderNames)
        qDebug() << re;
    cout << __FUNCTION__ << endl;
    return qfolderNames;
}

void Client::addFolder()
{
    cout << __FUNCTION__ << endl;
    sendRequest();
}

void Client::uploadResource()
{
    cout << __FUNCTION__ << endl;
    string str = _uploadRequest.toStdString();

    char act[dataLength];
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        _uploadSock->write_some(buffer(act, dataLength));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _uploadRequest.clear();
    ResourceTransmission rt;
    boost::thread (boost::bind(&ResourceTransmission::clientUploadResource, rt, _uploadSock, _uploadResources));
}

void Client::downloadResource()
{
    cout << __FUNCTION__ << endl;
    string str = _downloadRequest.toStdString();

    char act[dataLength];
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        _downloadSock->write_some(buffer(act, dataLength));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _downloadRequest.clear();
    ResourceTransmission rt;
    boost::thread (boost::bind(&ResourceTransmission::clientDownloadResource, rt, _downloadSock, _downloadResource));
}

void Client::request(QString request)
{
    _request = request;
}

void Client::uploadRequest(QString request)
{
    _uploadRequest = request;
}

void Client::downloadRequest(QString request)
{
    _downloadRequest = request;
}

void Client::setUploadResource(QString s)
{
    string resource = string((const char*)s.toLocal8Bit());
    auto reIterator = resource.begin();
    int i = 0;
    while(i < 1) {
        if(*reIterator++ == '/')
            i++;
    }
    string resourcePath;
    while(reIterator++ != resource.end())
        resourcePath += *reIterator;
    _uploadResources.push_back(resourcePath);
}

void Client::setDownloadResource(QString s)
{
    string resource = string((const char*)s.toLocal8Bit());
    _downloadResource = resource;
}

QList<QString> Client::getResourcesName()
{
    cout << __FUNCTION__ << endl;
    QList<QString> resourceName;
    for(auto re: _uploadResources) {
        auto reIterator = re.end();
        while(*reIterator-- != '/');
        string sname;
        reIterator++;
        while(reIterator++ != re.end())
            sname += *reIterator;
        QString qname = QString::fromStdString(sname);
        resourceName.append(qname);
    }
    return resourceName;
}

void Client::sendRequest()
{
    string str = _request.toStdString();

    char act[dataLength];
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        _sock->write_some(buffer(act, dataLength));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _request.clear();
}


QString Client::verifyResourceType(QString resourceName)
{
    QList<QString> resourceTypeDoc,resourceTypeMusic,resourceTypeMv;
    int index=-1;
    int i=0;
    resourceTypeMv<<"avi"<<"rmvb"<<"f4v"<<"rm"<<"asf"<<"divx"<<"mpg"<<"mpeg"<<"mpe"<<"wmv"<<"mp4"<<"mkv"<<"vob";
    while(i!=resourceTypeMv.size()){
        index=resourceName.indexOf(resourceTypeMv[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
        i++;
        if(index!=-1){
            return QString("V");
        }
    }
    index=-1;
    i=0;
    resourceTypeDoc<<"txt"<<"doc"<<"wps"<<"xls"<<"ppt"<<"pdf"<<"fla"<<"cpp"<<"h"<<"o";

    while(i!=resourceTypeDoc.size()){
        index=resourceName.indexOf(resourceTypeDoc[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
        i++;
        if(index!=-1){
            return QString("W");
        }
    }
    index=-1;
    i=0;
    resourceTypeMusic<<"mp3"<<"wma"<<"wav"<<"mod"<<"cd"<<"md"<<"asf"<<"aac"<<"mpspro"<<"vqf"<<"flac"<<"ape"<<"mid"<<"m4a"<<"ogg";
    while(i!=resourceTypeMusic.size()){
        index=resourceName.indexOf(resourceTypeMusic[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
        i++;
        if(index!=-1){

            return QString("M");
        }
    }
    return QString("O");

}

