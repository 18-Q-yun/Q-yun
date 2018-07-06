#ifndef LOCALFOLDER_H
#define LOCALFOLDER_H


#include <iostream>
#include <string>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

class  LocalFolder
{
public:
    LocalFolder(std::string dirPath):_dirPath{dirPath}{}
    bool createDirectory();
    bool deleteDirectory();
    bool exitDirectory();
private:
    std::string _dirPath;
};


#endif // LOCALFOLDER_H
