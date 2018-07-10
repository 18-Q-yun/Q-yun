#include "resourcetransmissio.h"
#include "localfolder.h"

#define MAX_DATA_LENGTH 1448

using std::cout; using std::endl;
using std::string;
using namespace boost::asio;

void ResourceTransmission::clientUploadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock, std::list<std::string> resources)
{
    char str[MAX_DATA_LENGTH];
    int num2 = resources.size();
    string flag = std::to_string(num2);
    flag.copy(str, flag.size(), 0);
    *(str + flag.size()) = '\0';
    sock->write_some(buffer(str, MAX_DATA_LENGTH));
    for(auto re: resources)
        sendUploadResource(sock, re);
}

void ResourceTransmission::sendUploadResource(std::shared_ptr<ip::tcp::socket> sock, std::string resource)
{
    char str[MAX_DATA_LENGTH];
    cout << "The resource path: ";
    string resourceName = getResourceName(resource);
    resourceName.copy(str, resourceName.size(), 0);
    *(str + resourceName.size()) = '\0';
    cout << str << endl;
    try{
        sock->write_some(buffer(str, MAX_DATA_LENGTH));
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    //    //资源名字

    std::ifstream ifs(resource, std::ios::binary);
    ifs.seekg(0, std::ios::end);
    int size = ifs.tellg();
    to_char(str, size);
    cout << "The size is " << str << endl;
    try{
        sock->write_some(buffer(str, MAX_DATA_LENGTH));
        if(ifs){
            ifs.seekg(0, ifs.beg);
            int offset = 0;
            int readSize = std::min(MAX_DATA_LENGTH, size - offset);
            char boo[] = "again";
            while(readSize > 0) {
                ifs.read(str, readSize);
                sock->write_some(buffer(str, readSize));
                //丢包重传
                sock->read_some(buffer(str));
                while(str == boo) {
                    sock->write_some(buffer(str, readSize));
                    sock->read_some(buffer(str));
                }
                offset += readSize;
                readSize = std::min(MAX_DATA_LENGTH, size - offset);
                cout << "offset: " << offset << endl;
            }
        }

    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    ifs.close();
}

void ResourceTransmission::clientDownloadResource(std::shared_ptr<boost::asio::ip::tcp::socket> sock, string resource)
{
    char str[MAX_DATA_LENGTH];

    cout << "The resource name " << resource << endl;

    resource.copy(str, resource.size(), 0);
    *(str + resource.size()) = '\0';
    cout << "The str resource name" << str << endl;
    try{
        sock->write_some(buffer(str, MAX_DATA_LENGTH));
        sock->read_some(buffer(str, MAX_DATA_LENGTH));//get resource size
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    //传输到相应的文件夹中
    string resourcePath = "/root/downloadResource/";
    LocalFolder folder(resourcePath);
    bool flag = folder.exitDirectory();
    cout << flag << endl;
    while(!flag)
        flag = folder.createDirectory();

    string length = str;
    int ilength = std::stoi (length);
    cout << "The length is " << ilength << endl;
    //计算传输次数
    int num = 0;
    if(ilength < MAX_DATA_LENGTH)
        num = 1;
    else if(ilength >= MAX_DATA_LENGTH) {
        int reminder = ilength % MAX_DATA_LENGTH;
        if(reminder == 0)
            num = ilength / MAX_DATA_LENGTH;
        else
            num = (ilength / MAX_DATA_LENGTH) + 1;
    }

    //传输到相应的文件夹中

    string downloadResource = resourcePath + "/" + resource;
    std::ofstream ofs(downloadResource, std::ios::binary);

    int i = 0;
    int n = 0;
    try{
        while (i++ < num) {
            size_t data =  sock->read_some(buffer(str));
            //丢包重传
            while(data != MAX_DATA_LENGTH && i < num - 1) {
                sock->write_some(buffer("again"));
                data =  sock->read_some(buffer(str));
            }
            sock->write_some(buffer("ok"));
            n += data;
            ofs.write(str, data);
        }
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    cout << n << endl;
    ofs.close();
}

//----------------------------------General----------------------------------------------

void ResourceTransmission::to_char(char c[], int i)
{
    string s = std::to_string(i);
    s.copy(c, s.size(), 0);
    *(c + s.size()) = '\0';
}


std::string ResourceTransmission::getResourceName(std::string resourceName)
{
    auto reIterator = resourceName.end();
    while(*reIterator-- != '/');
    string name;
    reIterator++;
    while(reIterator++ != resourceName.end())
        name += *reIterator;
    return name;
}
