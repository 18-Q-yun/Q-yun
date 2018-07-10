#ifndef RESOURCE_H
#define RESOURCE_H
#include <QString>
#include <string>
#include <QDebug>
using std::string;
class Resource
{
public:
    Resource(){}
    Resource(QString resourceName):
        _resourceName{resourceName}
    {}
    QString getResourceName(){
        return _resourceName;
    }
    QString getResourceTypeByName(QString resourceName)
    {
             string sresourceType=resourceName.section('.',1,1).trimmed().toStdString();
             QString qresourceType=QString::fromStdString(sresourceType);
             return  qresourceType;

    }

private:
    QString _resourceName;

};

#endif // RESOURCE_H
