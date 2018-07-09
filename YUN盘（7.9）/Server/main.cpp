#include <iostream>
#include "server.h"
#include "database.h"
using std::cout; using std::endl;
using namespace boost::asio;

int main()
{
    dataBase yunBase;
    yunBase.initDataBase();
    yunBase.createUserInfoTable();
    try{
        Server MyServer;
        MyServer.start_accept();
    }
    catch (std::exception& _e) {
        std::cout << _e.what() << std::endl;
    }
    return 0;
}
