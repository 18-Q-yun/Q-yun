#include <boost/thread.hpp>
#include "resourceserver.h"
#include "resourcetransmission.h"

#define MAX_DATA_LENGTH 1448

using namespace boost::asio; using std::string;
using std::cout; using std::endl;

ResourceServer::ResourceServer()
{
    std::shared_ptr<ip::tcp::acceptor> acceptor(new ip::tcp::acceptor(_io, ip::tcp::endpoint(ip::tcp::v4(), 2001)));
    _acceptor = acceptor;
}

void ResourceServer::start_accept()
{
    std::shared_ptr<ip::tcp::socket> sock(new ip::tcp::socket (_io));
    try{
        _acceptor->async_accept(*sock, bind(&ResourceServer::handle_accept, this, sock, _1));//避免静态成员函数调用非静态成员变量
        _io.run();
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

}

void ResourceServer::handle_accept(std::shared_ptr<ip::tcp::socket> sock, const boost::system::error_code &err)
{
    if(err) return;
    cout << "receive from" << sock->remote_endpoint().address() << endl;
    boost::thread t(boost::bind(&ResourceServer::start_accept, this));
    t.detach();
    selectWay(sock);
}

void ResourceServer::selectWay(std::shared_ptr<ip::tcp::socket> sock)
{
    char str[2];
    try{
        sock->read_some(buffer(str));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    string boo = str;
    cout << boo << endl;
    if(boo == "d")
        download(sock);
    if(boo == "s")
        upload(sock);


}

void ResourceServer::download(std::shared_ptr<ip::tcp::socket> sock)
{
    cout << "download" << endl;
    ResourceTransmission rt;
    rt.serverDownloadResource(sock);
    selectWay(sock);
}

void ResourceServer::upload(std::shared_ptr<ip::tcp::socket> sock)
{
    cout << "upload" << endl;
    ResourceTransmission rt;
    rt.serverUploadResource(sock);
    selectWay(sock);
}
