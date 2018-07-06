#include "client.h"
#include "resourcetransmissio.h"
#include <boost/thread.hpp>

using namespace boost::asio;
using std::cout; using std::endl;
using std::string;

Client::Client()
{
    _sock = std::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(_io));
    try{
        _sock->async_connect(ip::tcp::endpoint(ip::address::from_string("10.253.37.104"), 2001), [](const boost::system::error_code &err){if(!err)cout << "Connect successful!" << endl;});
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
        string resources = "/root/YUN.tar";
        boost::thread (boost::bind(&ResourceTransmission::clientDownloadResource, rt, _sock, resources));
    }
    else if(*act == 's')
    {
        boost::thread (boost::bind(&ResourceTransmission::clientUploadResource, rt, _sock, _resources));
    }
}

void Client::setFlag(int flag)
{
    _flag = flag;
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

void Client::coutResource()
{
    for(auto r: _resources)
        cout << r << endl;
}
