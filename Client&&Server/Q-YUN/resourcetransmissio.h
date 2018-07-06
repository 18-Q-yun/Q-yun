#ifndef RESOURCETRANSMISSIO_H
#define RESOURCETRANSMISSIO_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


class  ResourceTransmission
{
public:

    void clientUploadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock, std::vector<std::string> resources);
    void sendUploadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock, std::string resource);
    void clientDownloadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock, std::string resource);

    std::string getResourceName(std::string resourceName);
    void to_char(char c[], int i);
};
#endif // RESOURCETRANSMISSIO_H
