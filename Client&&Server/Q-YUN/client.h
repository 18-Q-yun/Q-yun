#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <QObject>

class Client: public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE Client();
    Q_INVOKABLE void selectWay();
    Q_INVOKABLE void setFlag(int flag);
    Q_INVOKABLE void setResource(QString s);
    Q_INVOKABLE void coutResource();

private:
    boost::asio::io_service _io;
    std::shared_ptr<boost::asio::ip::tcp::socket> _sock;
    int _flag;
    std::vector<std::string> _resources;
};

#endif // CLIENT_H
