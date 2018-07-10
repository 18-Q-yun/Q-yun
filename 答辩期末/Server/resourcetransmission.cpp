#include "resourcetransmission.h"
#include "localfolder.h"
#include "stdlib.h"
#include <QList>

#define MAX_DATA_LENGTH 1448

using std::cout; using std::endl;
using std::string;
using namespace boost::asio;

//---------------------------------------------Server------------------------------------------
void ResourceTransmission::serverUploadResources(boost::asio::ip::tcp::socket &sock, std::string userName)
{
    char str[MAX_DATA_LENGTH];
    sock.read_some(buffer(str));
    string resourceNum = str;
    int reNum = std::stoi(resourceNum);
    cout << "resource num is " << reNum << endl;

    for(int j = 0; j != reNum; j++) {
        acceptUploadResources(sock, userName);
    }
}

void ResourceTransmission::acceptUploadResources(ip::tcp::socket &sock, std::string userName)
{
    char str[MAX_DATA_LENGTH];
    try{

        sock.read_some(buffer(str, MAX_DATA_LENGTH));//获取资源名
        cout << str << endl;
    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }


    string resourcePath;
    string resourceName = str;

    //传输到相应的文件夹中
    QString qresourceName = QString::fromStdString(resourceName);
    string resourceType = verifyResourceType(qresourceName);
    cout << "type" << resourceType <<endl;

    resourcePath = "/root/云盘用户文件/" + userName + "/" + resourceType;
    cout << resourcePath << endl;
    LocalFolder folder;
    bool flag = folder.exitDirectory(resourcePath);
    while(!flag)
        flag = folder.createDirectory(resourcePath);
    string resource =  resourcePath + "/" + resourceName;//资源存放服务器的具体位置,例如：/root/云盘用户文件/userName/resourceType/resourceName

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

void ResourceTransmission::serverDownloadResource(ip::tcp::socket &sock, string userName)
{
    char str[MAX_DATA_LENGTH];
    try{
        sock.read_some(buffer(str, MAX_DATA_LENGTH));
        cout << str << endl;

    } catch(std::exception& _e) {
        cout << _e.what() << endl;
    }

    string resourceName = str;
    QString qresourceName = QString::fromStdString(resourceName);
    string resourceType = verifyResourceType(qresourceName);
    cout << "type" << resourceType <<endl;
    string resourcePath = "/root/云盘用户文件/" + userName + "/" + resourceType + "/" + resourceName;
    cout << resourcePath << endl;

    std::ifstream ifs(resourcePath,std::ios::binary);
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

std::string ResourceTransmission::verifyResourceType(QString resourceName)
{
    QList<QString> resourceTypeDoc,resourceTypeMusic,resourceTypeMv;
    int index=-1;
    int i=0;
    resourceTypeMv<<"avi"<<"rmvb"<<"f4v"<<"rm"<<"asf"<<"divx"<<"mpg"<<"mpeg"<<"mpe"<<"wmv"<<"mp4"<<"mkv"<<"vob";
    while(i!=resourceTypeMv.size()){
        index=resourceName.indexOf(resourceTypeMv[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
        i++;
        if(index!=-1){
            return string("视频");
        }
    }
    index=-1;
    i=0;
    resourceTypeDoc<<"txt"<<"doc"<<"wps"<<"xls"<<"ppt"<<"pdf"<<"fla"<<"cpp"<<"h"<<"o";

    while(i!=resourceTypeDoc.size()){
        index=resourceName.indexOf(resourceTypeDoc[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
        i++;
        if(index!=-1){
            return string("文档");
        }
    }
    index=-1;
    i=0;
    resourceTypeMusic<<"mp3"<<"wma"<<"wav"<<"mod"<<"cd"<<"md"<<"asf"<<"aac"<<"mpspro"<<"vqf"<<"flac"<<"ape"<<"mid"<<"m4a"<<"ogg";
    while(i!=resourceTypeMusic.size()){
        index=resourceName.indexOf(resourceTypeMusic[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
        i++;
        if(index!=-1){

            return string("音频");
        }
    }
    return string("其他");

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
