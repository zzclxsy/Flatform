#ifndef IMODULE_H
#define IMODULE_H

class IManager;
//一个模块下面拥有多个服务，服务在initialize里面进行初始化，也就是将其添加进ObjectMgr
class IModule
{
public:
    IModule(){}
    virtual ~IModule(){}

    virtual bool initialize(IManager * m) = 0;
    virtual void terminal() = 0;
};

#endif // IMODULE_H
