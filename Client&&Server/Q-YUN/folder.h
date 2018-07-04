#ifndef FOLDER_H
#define FOLDER_H


#include <iostream>
#include <string>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

class  Folder
{
public:
    Folder(std::string dirPath):_dirPath{dirPath}{}
    bool createDirectory();
    bool deleteDirectory();
    bool exitDirectory();
private:
    std::string _dirPath;
};


#endif // FOLDER_H
