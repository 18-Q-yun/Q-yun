#ifndef ACTION_H
#define ACTION_H

#include <boost/thread.hpp>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <QString>

class Action
{
public:
    Action(boost::asio::io_service& io_service): _sock(io_service){}
    void selectWay();
    std::string analysisRequest(QString jsonHeader);

    void applyAccount();
    void download();
    void upload();

    void createUserResourceFolder(QString userName);//此处建立的是用户在服务器端存储资源文件夹

    boost::asio::ip::tcp::socket& socket(){return _sock;}
private:
    boost::asio::ip::tcp::socket _sock;
};
#endif // ACTION_H
