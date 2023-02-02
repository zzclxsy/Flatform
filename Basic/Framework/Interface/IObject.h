#ifndef IOBJECT_H
#define IOBJECT_H

class IManager;

class IObject
{
public:
    IObject(){}
    virtual ~IObject(){}

    virtual void setManager(IManager * m) = 0;
    virtual bool initialize() = 0;
    virtual void terminal() = 0;
};


#endif // IOBJECT_H
