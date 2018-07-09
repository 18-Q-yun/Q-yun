#include "resourcetransmission.h"
#include "localfolder.h"
#include "stdlib.h"

#define MAX_DATA_LENGTH 1448

using std::cout; using std::endl;
using std::string;
using namespace boost::asio;

//---------------------------------------------Server------------------------------------------
void ResourceTransmission::serverUploadResources(boost::asio::ip::tcp::socket &sock)
{
    char str[MAX_DATA_LENGTH];
    sock.read_some(buffer(str));
    string resourceNum = str;
    int reNum = std::stoi(resourceNum);
    cout << "resource num is " << reNum << endl;

    for(int j = 0; j != reNum; j++) {
        acceptUploadResources(sock);
    }
}

void ResourceTransmission::acceptUploadResources(ip::tcp::socket &sock)
{
    char str[MAX_DATA_LENGTH];
    try{

        sock.read_some(buffer(str, MAX_DATA_LENGTH));
        cout << str << endl;
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }


    string resourcePath;
    //传输到相应的文件夹中
    string resourceName = str;
    resourcePath = "/root/uploadResource";
    cout << resourcePath << endl;
    LocalFolder folder;
    bool flag = folder.exitDirectory(resourcePath);
    while(!flag)
        flag = folder.createDirectory(resourcePath);
    string resource =  resourcePath + "/" + resourceName;

    //接受数据长度
    int ilength ;
    try{
        sock.read_some(buffer(str, MAX_DATA_LENGTH));
        string length = str;
        cout << length << endl;
        ilength = std::stoi (length);
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    cout << "The length is " << ilength << endl;
    //    计算传输次数
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

    std::ofstream ofs(resource, std::ios::binary);

    int i = 0;
    int n = 0;
    try{
        while (i++ < num) {
            size_t data =  sock.read_some(buffer(str));
            //丢包重传
            while(data != MAX_DATA_LENGTH && i < num - 1) {
                sock.write_some(buffer("again"));
                data =  sock.read_some(buffer(str));
            }
            sock.write_some(buffer("ok"));
            n += data;
            ofs.write(str, data);
        }
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    cout << n << endl;
    ofs.close();
}

void ResourceTransmission::serverDownloadResource(ip::tcp::socket &sock)
{
    char str[MAX_DATA_LENGTH];
    try{
        sock.read_some(buffer(str, MAX_DATA_LENGTH));
        cout << str << endl;

    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    string resource = str;
    std::ifstream ifs(resource,std::ios::binary);
    ifs.seekg(0, std::ios::end);
    int size = ifs.tellg();
    int_to_char(str, size);
    cout << "The size is " << str << endl;
    try{
        sock.write_some(buffer(str, MAX_DATA_LENGTH));
        if(ifs){
            ifs.seekg(0, ifs.beg);
            int offset = 0;
            int readSize = std::min(MAX_DATA_LENGTH, size - offset);
            char boo[] = "again";
            while(readSize > 0) {
                ifs.read(str, readSize);
                sock.write_some(buffer(str, readSize));
                //丢包重传
                sock.read_some(buffer(str));
                while(str == boo) {
                    sock.write_some(buffer(str, readSize));
                    sock.read_some(buffer(str));
                }
                offset += readSize;
                readSize = std::min(MAX_DATA_LENGTH, size - offset);
                std::cout << "offset:" << offset << std::endl;
            }
        }
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }
    ifs.close();
}

//----------------------------------General----------------------------------------------

void ResourceTransmission::int_to_char(char c[], int i)
{
    string s = std::to_string(i);
    s.copy(c, s.size(), 0);
    *(c + s.size()) = '\0';
}

void ResourceTransmission::str_to_char(char c[], std::string s)
{
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
