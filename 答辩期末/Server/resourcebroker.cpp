#include "resourcebroker.h"
#include <QDebug>

QString ResourceBroker::verifyResourceType(QString resourceName)
{
    QList<QString> resourceTypeDoc,resourceTypeMusic,resourceTypeMv;
    int index=-1;
    int i=0;
    resourceTypeMv<<"avi"<<"rmvb"<<"f4v"<<"rm"<<"asf"<<"divx"<<"mpg"<<"mpeg"<<"mpe"<<"wmv"<<"mp4"<<"mkv"<<"vob";
   while(i!=resourceTypeMv.size()){
       index=resourceName.indexOf(resourceTypeMv[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
       i++;
       if(index!=-1){
        return QString("V");
       }
   }
   index=-1;
   i=0;
    resourceTypeDoc<<"txt"<<"doc"<<"wps"<<"xls"<<"ppt"<<"pdf"<<"fla"<<"cpp"<<"h"<<"o";

   while(i!=resourceTypeDoc.size()){
      index=resourceName.indexOf(resourceTypeDoc[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
       i++;
      if(index!=-1){
       return QString("W");
      }
   }
   index=-1;
   i=0;
   resourceTypeMusic<<"mp3"<<"wma"<<"wav"<<"mod"<<"cd"<<"md"<<"asf"<<"aac"<<"mpspro"<<"vqf"<<"flac"<<"ape"<<"mid"<<"m4a"<<"ogg";
  while(i!=resourceTypeMusic.size()){
     index=resourceName.indexOf(resourceTypeMusic[i],Qt::CaseInsensitive);//匹配不区分大小写的资源后缀名
      i++;
      if(index!=-1){

       return QString("M");
      }
  }
   return QString("O");

}

QList<Resource> ResourceBroker::getUserResource(QString userName,int currentLevel, QString currentDirName)
{
    QString levelDirTableName=getUserTableName(currentLevel,userName);
    QList<QString> resourceNames=selectLevelDir(levelDirTableName,currentDirName);
    QList<Resource> resources;
    for(int i = resourceNames.size() - 1;i != -1; --i) {
        Resource resource(resourceNames.at(i));
        resources << resource;
    }
    _resources=resources;
    return _resources;
}

void ResourceBroker::addResource(QString userName, QString resourceName, QString currentDirName, QString currentLevel)
{
  int level=currentLevel.toInt();
  QString resourceType=verifyResourceType(resourceName);
  qDebug()<<"add resource";
  insertLevelDir(level,userName,resourceName,currentDirName,resourceType);
    qDebug()<<"add resource2";





}
QString ResourceBroker::getUserTableName(int level,QString userName)
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
