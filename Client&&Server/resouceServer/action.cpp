#include <string>
#include "action.h"
#include "resourcetransmission.h"

using namespace boost::asio;
using std::cout; using std::endl;
using std::string;

void Action::selectWay()
{
    char str[2];
    try{
        _sock.read_some(buffer(str));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    string boo = str;
    cout << boo << endl;
    if(boo == "d")
        download();
    if(boo == "s")
        upload();
}

void Action::download()
{
    cout << "download" << endl;
    ResourceTransmission rt;
    rt.serverDownloadResource(_sock);
    selectWay();
}

void Action::upload()
{
    cout << "upload" << endl;
    ResourceTransmission rt;
    rt.serverUploadResources(_sock);
    selectWay();
}
