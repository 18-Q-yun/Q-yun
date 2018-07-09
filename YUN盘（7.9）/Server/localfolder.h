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
    LocalFolder(){}
    bool createDirectory(std::string _dirPath);
    bool deleteDirectory(std::string _dirPath);
    bool exitDirectory(std::string _dirPath);
};
#endif // LOCALFOLDER_H
