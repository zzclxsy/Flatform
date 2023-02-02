#ifndef IFACTORY_H
#define IFACTORY_H


#include "IObject.h"

class IFactory
{
public:
    IFactory(){}
    virtual ~IFactory(){}

    virtual IObject * create() = 0;
};


#define X_FACTORY_DECL(ClsName)                 \
    class ClsName##Factory : public IFactory{   \
    public:                                     \
        ClsName##Factory(){}                    \
        virtual ~ClsName##Factory(){}           \
        virtual IObject * create();             \
    };

#define X_FACTORY_IMPL(ClsName)                 \
    IObject * ClsName##Factory::create()        \
    {                                           \
        IObject * p = new ClsName();            \
        return p;                               \
    }

#define X_FACTORY_NAME(ClsName) ClsName##Factory
#endif // IFACTORY_H
