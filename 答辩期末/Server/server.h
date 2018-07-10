#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <action.h>

class Server
{
public:
    Server();
    void start_accept();
    void handle_accept(std::shared_ptr<Action> act, const boost::system::error_code &err);

private:
    boost::asio::io_service _io;
    std::shared_ptr<boost::asio::ip::tcp::acceptor> _acceptor;
};

#endif // SERVER_H
