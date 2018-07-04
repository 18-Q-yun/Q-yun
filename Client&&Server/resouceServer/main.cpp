#include <iostream>
#include "resourceserver.h"

using std::cout; using std::endl;
using namespace boost::asio;

int main()
{
    try{
        ResourceServer MyServer;
        MyServer.start_accept();
    }
    catch (std::exception& _e) {
        std::cout << _e.what() << std::endl;
    }
    return 0;
}
