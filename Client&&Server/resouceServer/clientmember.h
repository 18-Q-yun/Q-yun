#ifndef CLIENTMEMBER_H
#define CLIENTMEMBER_H

#include <boost/asio.hpp>

class ClientMember
{
public:
    ClientMember();
private:
    boost::asio::ip::tcp::socket _sock;
};

#endif // CLIENTMEMBER_H
