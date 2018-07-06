#include <boost/thread.hpp>
#include "resourceserver.h"
#include "resourcetransmission.h"
#include "action.h"

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
//    std::shared_ptr<ip::tcp::socket> sock(new ip::tcp::socket (_io));
    std::shared_ptr<Action> act(new Action(_io));
    try{
        _acceptor->async_accept(act->socket(), bind(&ResourceServer::handle_accept, this, act, _1));//避免静态成员函数调用非静态成员变量
        _io.run();
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

}

void ResourceServer::handle_accept(std::shared_ptr<Action> act, const boost::system::error_code &err)
{
    if(err) return;
    cout << "receive from" << act->socket().remote_endpoint().address() << endl;
    boost::thread t(boost::bind(&ResourceServer::start_accept, this));
    t.detach();
    act->selectWay();
}
