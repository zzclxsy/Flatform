#include "JHDatabaseModule.h"
#include "Framework/ObjectMgr.h"
X_FACTORY_DECL(JHSystemSqliteAccessServer)
X_FACTORY_IMPL(JHSystemSqliteAccessServer)


JHDatabaseModule::JHDatabaseModule()
{

}

bool JHDatabaseModule::initialize(IManager *m)
{
    ObjectMgr *obj = static_cast<ObjectMgr *>(m);
    obj->addFactory("JHSystemSqliteAccessServer",new X_FACTORY_NAME(JHSystemSqliteAccessServer));
    obj->getService("JHSystemSqliteAccessServer");

    return true;
}

void JHDatabaseModule::terminal()
{

}

bool JHSystemSqliteAccessServer::initialize()
{
    mp_sysSqlite = new JHSystemSqliteAccess("./system.db");
    return true;
}

void JHSystemSqliteAccessServer::terminal()
{

}

JHSystemSqliteAccess *JHSystemSqliteAccessServer::systemSqlApi()
{
    return mp_sysSqlite;
}
