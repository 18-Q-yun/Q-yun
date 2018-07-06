#include "folderbroker.h"
#include <QString>


QString FolderBroker::getUserTableName(QString currentLevel,QString userName)
{
    QString levelDirTableName;
    int level=currentLevel.toInt();
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

QList<Folder> FolderBroker::getUserFolder(QString userName,QString currentLevel, QString lastfilename)
{
    QString levelDirTableName=getUserTableName(currentLevel,userName);
    QList<QString> folderNames=selectLevelDir(levelDirTableName,lastfilename);
    QList<Folder> folders;
    for(int i=0;i!=folderNames.size();++i) {
        ;
       Folder folder(folderNames.at(i));
       folders<<folder;
    }
   _folders=folders;
   return folders;
}
void FolderBroker::deleteFolder(QString userName,QString folderName,QString lastFolderName,QString currentLevel)
{
      QString levelDirTableName=getUserTableName(currentLevel,userName);
      deleteLevelDir(levelDirTableName,folderName,lastFolderName);
}

void FolderBroker::addFolder(QString userName,QString folderName,QString lastFolderName,QString currentLevel)
{
   QString levelDirTableName=getUserTableName(currentLevel,userName);
   insertLevelDir(levelDirTableName,folderName,lastFolderName,"D");
}
