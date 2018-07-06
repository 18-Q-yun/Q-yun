#ifndef FOLDER_H
#define FOLDER_H
#include <QString>
#include <iostream>
class Folder
{
public:
    Folder(){}
    Folder(QString folderName):_folderName{folderName}{}
private:
    QString _folderName;

};
#endif // FOLDER_H
