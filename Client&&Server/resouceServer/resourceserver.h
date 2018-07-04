#ifndef RESOURCESERVER_H
#define RESOURCESERVER_H


#include <iostream>
#include <fstream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class ResourceServer
{
public:
    ResourceServer();
    void start_accept();
    void handle_accept(std::shared_ptr<boost::asio::ip::tcp::socket> sock, const boost::system::error_code &err);
    void selectWay(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
    void download(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
    void upload(std::shared_ptr<boost::asio::ip::tcp::socket> sock);


private:
    boost::asio::io_service _io;
    std::shared_ptr<boost::asio::ip::tcp::acceptor> _acceptor;
};

#endif // RESOURCESERVER_H
