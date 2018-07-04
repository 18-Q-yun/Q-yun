#include "client.h"
#include "resourcetransmissio.h"
#include <boost/thread.hpp>

using namespace boost::asio;
using std::cout; using std::endl;
using std::string;

//boost::asio::io_service _io;
//std::shared_ptr<ip::tcp::socket> sock(new ip::tcp::socket(_io));
//ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);


Client::Client()
{
    _sock = std::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(_io));
    try{
        _sock->async_connect(ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), 2001), [](const boost::system::error_code &err){if(!err)cout << "Connect successful!" << endl;});
        _io.run();
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

}

void Client::selectWay()
{
    cout << __FUNCTION__ << endl;
    char *act;
    if(_flag == 0)
        act = "d";
    if(_flag == 1)
        act = "s";
    ResourceTransmission rt;

    try{
        _sock->write_some(buffer(act, 2));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    if(*act == 'd') {
        cout << _resource << endl;
        boost::thread (boost::bind(&ResourceTransmission::clientDownloadResource, rt, _sock, _resource));
    }
    else if(*act == 's')
    {
        cout << _resource << endl;
        boost::thread (boost::bind(&ResourceTransmission::clientUploadResource, rt, _sock, _resource));
    }
}

void Client::setFlag(int flag)
{
    _flag = flag;
}

void Client::setResource(QString s)
{
    _resource = string((const char*)s.toLocal8Bit());
}
