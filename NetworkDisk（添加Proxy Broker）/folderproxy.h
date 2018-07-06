#ifndef FOLDERPROXY_H
#define FOLDERPROXY_H
#include <QString>
#include "folderbroker.h"
class FolderProxy
{
public:
    FolderProxy(){}
    QList<Folder> getUserResource(QString request);
    void deleteFolder(QString request);
    void addFolder(QString request);
};

#endif // FOLDERPROXY_H
