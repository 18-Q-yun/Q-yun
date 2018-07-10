#ifndef RESOURCEBROKER_H
#define RESOURCEBROKER_H
#include <QList>
#include <QString>
#include "resource.h"
#include "database.h"
class ResourceBroker:public dataBase
{
public:
    ResourceBroker(){}
     QString getUserTableName(int level, QString userName);
    QString verifyResourceType(QString resourceName);
    QList<Resource> getUserResource(QString userName,int currentLevel,QString currentDirName);
    void addResource(QString userName, QString resourceName, QString currentDirName, QString currentLevel);
private:
    QList<Resource> _resources;
};

#endif // RESOURCEBROKER_H
