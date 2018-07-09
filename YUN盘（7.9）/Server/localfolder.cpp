#include <string>
#include "localfolder.h"


using std::string; using std::cout;
using std::endl;

bool LocalFolder::createDirectory(std::string _dirPath)
{
    int flag = mkdir(_dirPath.c_str(), 0777);//该函数功能为建立一个新的目录，创建成功则返回0，否则返回-1
    //默认mode是0777，表示最大可能的访问权

    if (flag == 0) {
        cout << "make successfully" << endl;
        return true;
    } else {
        cout << "make errorly" << endl;
        return false;
    }
    return false;
}

bool LocalFolder::deleteDirectory(std::string _dirPath)
{
    int flag = rmdir(_dirPath.c_str());
    if (flag == 0) {
        cout << "delete it successfully" << endl;
        return true;
    } else {
        cout << "delete it errorly" << endl;
        return false;
    }
    return false;
}

bool LocalFolder::exitDirectory(std::string _dirPath)
{
    int flag = access(_dirPath.c_str(), 0);//该函数功能为确定文件或文件夹的访问权限，如果指定的访问权限有效，则函数返回0，否则返回-1
    if(flag == 0)
        return true;
    else if(flag == -1)
        return false;
    return false;
}
