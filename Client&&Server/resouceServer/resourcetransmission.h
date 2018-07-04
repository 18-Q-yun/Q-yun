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
    void serverUploadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
    void serverDownloadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock);

    std::string getResourceName(std::string resourceName);
    void to_char(char c[], int i);
};
#endif // RESOURCETRANSMISSION_H
