#ifndef RESOURCETRANSMISSION_H
#define RESOURCETRANSMISSION_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class  ResourceTransmission
{
public:
    void serverUploadResources(boost::asio::ip::tcp::socket &sock);
    void acceptUploadResources(boost::asio::ip::tcp::socket &sock);
    void serverDownloadResource(boost::asio::ip::tcp::socket &sock);

    std::string getResourceName(std::string resourceName);
    void int_to_char(char c[], int i);
    void str_to_char(char c[], std::string s);
};
#endif // RESOURCETRANSMISSION_H
