#include "folderbroker.h"
#include <QString>
#include<QDebug>
using std::cout;
using std::endl;
QString FolderBroker::getUserTableName(int level,QString userName)
{
    QString levelDirTableName;
    //    int level1=level.toInt();
    switch (level) {
    case 1:

        levelDirTableName=userName+"firstDir";
        break;
    case 2:

        levelDirTableName=userName+"secondDir";
        break;
    case 3:

        levelDirTableName=userName+"thirdDir";
        break;
    case 4:

        levelDirTableName=userName+"fourthDir";
        break;
    case 5:

        levelDirTableName=userName+"fifthDir";
        break;
    case 6:
        levelDirTableName=userName+"sixDir";
        break;
    case 7:

        levelDirTableName=userName+"seventhDir";
        break;
    case 8:

        levelDirTableName=userName+"eighthDir";
        break;
    default:
        break;
    }
    return levelDirTableName;
}

QList<Folder> FolderBroker::getUserFolder(QString userName,int currentLevel, QString lastfilename)
{
    qDebug()<<currentLevel<<userName;
    QString levelDirTableName=getUserTableName(currentLevel,userName);
    qDebug()<<levelDirTableName;
    QList<QString> folderNames=selectLevelDir(levelDirTableName,lastfilename);
    QList<Folder> folders;
    for(int i = folderNames.size() - 1;i != -1; --i) {
        Folder folder(folderNames.at(i));
        folders << folder;
    }
    _folders=folders;
    return folders;
}
void FolderBroker::deleteFolder(QString userName,QString folderName,QString lastFolderName,int currentLevel)
{
    QString levelDirTableName=getUserTableName(currentLevel,userName);
    deleteLevelDir(levelDirTableName,folderName,lastFolderName);
}

void FolderBroker::addFolder(QString userName,QString folderName,QString lastFolderName,QString currentLevel)
{
    //   QString levelDirTableName=getUserTableName(currentLevel,userName);
    int level = currentLevel.toInt();
    qDebug()<<"hello"<<userName<<folderName<<lastFolderName<<level;
    insertLevelDir(level,userName,folderName,lastFolderName,"D");
}
