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
    Q_INVOKABLE void uploadResource();
    Q_INVOKABLE void downloadResource();

    Q_INVOKABLE void request(QString request);
    Q_INVOKABLE void uploadRequest(QString request);
    Q_INVOKABLE void downloadRequest(QString request);

    Q_INVOKABLE void setUploadResource(QString s);
    Q_INVOKABLE void setDownloadResource(QString s);
    Q_INVOKABLE QList<QString> getResourcesName();
    Q_INVOKABLE void sendRequest();
    Q_INVOKABLE QString verifyResourceType(QString resourceName);


private:
    boost::asio::io_service _io;
    std::shared_ptr<boost::asio::ip::tcp::socket> _sock;
    std::shared_ptr<boost::asio::ip::tcp::socket> _uploadSock;
    std::shared_ptr<boost::asio::ip::tcp::socket> _downloadSock;
    QString _request;
    QString _uploadRequest;
    QString _downloadRequest;
    std::list<std::string> _uploadResources;
    std::string _downloadResource;
};

#endif // CLIENT_H
