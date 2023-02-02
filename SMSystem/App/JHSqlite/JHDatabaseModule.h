#ifndef JHDATABASEMODULE_H
#define JHDATABASEMODULE_H
#include "Framework/Interface/IModule.h"
#include "Framework/Interface/IService.h"
#include "Framework/Interface/IFactory.h"
#include "Framework/Interface/BObject.h"

#include "JHSystemSqliteAccess.h"
class JHDatabaseModule:public IModule
{
public:
    JHDatabaseModule();
    virtual bool initialize(IManager * m);
    virtual void terminal();
};

class JHSystemSqliteAccessServer:
        public BObject
{
public:
    virtual bool initialize();
    virtual void terminal();
    JHSystemSqliteAccess *systemSqlApi();

private:
    JHSystemSqliteAccess* mp_sysSqlite;
};



#endif // JHDATABASEMODULE_H
