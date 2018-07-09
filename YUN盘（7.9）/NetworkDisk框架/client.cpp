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

Client::Client()
{
    _sock = std::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(_io));
    try{
        _sock->async_connect(ip::tcp::endpoint(ip::address::from_string("10.253.188.20"), 2001), [](const boost::system::error_code &err){if(!err)cout << "Connect successful!" << endl;});
        _io.run();
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
}

void Client::registerUser()
{
    cout << __FUNCTION__ << endl;

    string str = _request.toStdString();
    cout << str << endl;

    char act[1024];
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        cout << act << endl;
        _sock->write_some(buffer(act, 1024));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _request.clear();
    //    try{
    //        cout << act << endl;
    //        _sock->read_some(buffer(act, 1024));
    //    } catch(std::exception& _e) {
    //        cout << _e.what() << endl;
    //    }

    //    ResourceTransmission rt;
    //    if(str == "上传")
    //        boost::thread (boost::bind(&ResourceTransmission::clientUploadResource, rt, _sock, _resources));
    //    if(str == "下载") {
    //        string resources = "/root/YUN.tar";
    //        boost::thread (boost::bind(&ResourceTransmission::clientDownloadResource, rt, _sock, resources));
    //    }
}

int Client::loginSystem()
{
    cout << __FUNCTION__ << endl;

    string str = _request.toStdString();
    cout << str << endl;

    char act[1024];
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        cout << act << endl;
        _sock->write_some(buffer(act, 1024));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _request.clear();

    try{
        cout << act << endl;
        _sock->read_some(buffer(act, 1024));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    string loginFlag = act;
    cout << loginFlag << endl;
    if(loginFlag == "success") {
        cout << "asas" << endl;
        return 1;
    }else if(loginFlag == "fail") {
        return 0;
    }
}

QList<QString> Client::getUserFolder()
{
    cout << __FUNCTION__ << endl;

    string str = _request.toStdString();
    cout << str << endl;

    char act[1024];
    memset(act,0,sizeof(char)*1024);
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        cout << act << endl;
        _sock->write_some(buffer(act, 1024));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _request.clear();


    QList<QString> qfolderNames;
    int ilength;
    string slength;
    try{
        _sock->read_some(buffer(act, 1024));
        slength = act;
        ilength = std::stoi(slength);
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    cout << "length" << ilength;
    memset(act, 0, 1024);

    string flag = "false";
    int i = 0;
    while(i != ilength) {
        memset(act, 0, 1024);
        string sfolder;
        while(flag == "false") {
            _sock->read_some(buffer(act, 1024));
            sfolder = act;
            if(sfolder == "")
                _sock->write_some(buffer("again"));
            else {
                _sock->write_some(buffer("ok"));
                flag = "true";
            }
        }
        QString qfolder = QString::fromStdString(sfolder);
        qfolderNames.push_back(qfolder);
        flag = "false";
        i++;
    }

    return qfolderNames;
}

void Client::addFolder()
{
    cout << __FUNCTION__ << endl;

    string str = _request.toStdString();
    cout << str << endl;

    char act[1024];
    str.copy(act, str.size(), 0);
    *(act + str.size()) = '\0';

    try{
        cout << act << endl;
        _sock->write_some(buffer(act, 1024));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    _request.clear();
}

void Client::request(QString request)
{
    _request = request;
}

void Client::setResource(QString s)
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
    _resources.push_back(resourcePath);
}

QString Client::analysisRequest(QString jsonRequest)
{
    QString request;
    QJsonParseError error;
    QJsonDocument requestDocument = QJsonDocument::fromJson(jsonRequest.toUtf8(),&error);
    if(error.error == QJsonParseError::NoError){
        if(requestDocument.isObject()) {
            QJsonObject ob = requestDocument.object();
            if(ob.contains("request")) {
                QJsonValue value = ob.take("request");
                if(value.isString())
                    request = value.toVariant().toString();
            }
        }
    }
    return request;
}
