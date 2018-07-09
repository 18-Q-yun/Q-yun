#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <string>
#include <list>
#include <boost/asio.hpp>
#include <QString>
#include <QList>
#include <QObject>

class Client: public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE Client();

    Q_INVOKABLE void registerUser();
    Q_INVOKABLE int loginSystem();
    Q_INVOKABLE QList<QString> getUserFolder();
    Q_INVOKABLE void addFolder();

    Q_INVOKABLE void request(QString request);
    Q_INVOKABLE void setResource(QString s);
    Q_INVOKABLE QString analysisRequest(QString jsonRequest);


private:
    boost::asio::io_service _io;
    std::shared_ptr<boost::asio::ip::tcp::socket> _sock;
    QString _request;
    std::list<std::string> _resources;
};

#endif // CLIENT_H
