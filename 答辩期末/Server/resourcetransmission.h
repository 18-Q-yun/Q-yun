#ifndef RESOURCETRANSMISSION_H
#define RESOURCETRANSMISSION_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <QString>

class  ResourceTransmission
{
public:
    void serverUploadResources(boost::asio::ip::tcp::socket &sock, std::string userName);
    void acceptUploadResources(boost::asio::ip::tcp::socket &sock, std::string userName);

    void serverDownloadResource(boost::asio::ip::tcp::socket &sock, std::string userName);

    std::string getResourceName(std::string resourceName);
    void int_to_char(char c[], int i);
    void str_to_char(char c[], std::string s);
    std::string verifyResourceType(QString resourceName);
};
#endif // RESOURCETRANSMISSION_H
