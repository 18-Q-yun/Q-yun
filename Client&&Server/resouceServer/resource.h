#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <iostream>

class Resource
{
public:
    Resource();

private:
    std::string _resourceName;
    std::string _resourceType;
    std::string _resourcePath;
};

#endif // RESOURCE_H
