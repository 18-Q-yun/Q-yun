#ifndef RESOURCEPROXY_H
#define RESOURCEPROXY_H
#include <QString>
#include <QList>
#include "resource.h"
#include "resourcebroker.h"
class ResourceProxy
{
public:
    ResourceProxy(){}
    QList<Resource> getUserResource(QString request);
    void addResource(QString request);

//    void deleteResource(QString request);

};

#endif // RESOURCEPROXY_H
