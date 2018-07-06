#ifndef ACTION_H
#define ACTION_H

#include <boost/thread.hpp>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


class Action
{
public:
    Action(boost::asio::io_service& io_service): _sock(io_service){}
    void selectWay();
    void download();
    void upload();
    boost::asio::ip::tcp::socket& socket(){return _sock;}
private:
    boost::asio::ip::tcp::socket _sock;
};

#endif // ACTION_H
