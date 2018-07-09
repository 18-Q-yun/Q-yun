#ifndef RESOURCE_H
#define RESOURCE_H

#include <QString>
#include <iostream>

class Resource
{
public:
    Resource();

private:
    QString _resourceName;
    QString _resourceType;
    QString _resourcePath;
};

#endif // RESOURCE_H
