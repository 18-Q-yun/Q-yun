#ifndef FOLDERBROKER_H
#define FOLDERBROKER_H
#include "database.h"
#include "folder.h"
#include "database.h"
#include <QList>
class FolderBroker:public dataBase
{


public:
    FolderBroker(){}
    QString getUserTableName(int level, QString userName);
    QList<Folder> getUserFolder(QString userName, int currentLevel, QString lastfilename);
    void deleteFolder(QString userName, QString folderName, QString lastFolderName, int currentLevel);
    void addFolder(QString userName,QString folderName,QString lastFolderName,QString currentLevel);
private:
    QList<Folder>  _folders;
};

#endif // FOLDERBROKER_H
