#ifndef IMANAGER_H
#define IMANAGER_H


#include "IFactory.h"
#include "IObject.h"
#include <string>
#include <map>


class IManager
{
public:
    virtual void addFactory(const std::string& tc, IFactory * f) = 0;
    virtual IFactory * removeFactory(const std::string& tc) = 0;

    virtual IObject * create(const std::string& tc) = 0;
    virtual IObject * getService(const std::string& tc) = 0;
    virtual void removeService(const std::string& tc) = 0;
};

#endif // IMANAGER_H
