#include "Framework.h"
#include "ObjectMgr.h"
#include <QQmlEngine>
#include "AppData/JHMessageClient.h"
#include <QGuiApplication>
#include "JHDataModel/JHListViewModel.h"
static Framework* g_app = nullptr;
QString Framework::applicationDirPath()
{
    return qApp->applicationDirPath();
}

Framework::Framework()
{
    m_manager = new ObjectMgr();
    g_app = this;
}


Framework *Framework::getApp()
{
    return g_app;
}

int Framework::initialize()
{
    qmlRegisterType<JHMessageClient>("JHFramework",1,0,"JHMessageClient");
    qmlRegisterType<JHListViewModel>("JHFramework",1,0,"JHListViewModel");
    qmlRegisterType<JHListModel>("JHFramework",1,0,"JHListModel");

    getObjectManager()->addFactory("JHAppDataServer",new X_FACTORY_NAME(JHAppData));
    m_appData = m_manager->getXService<JHAppData>("JHAppDataServer");
    return 0;
}

void Framework::addModule(IModule *module)
{
    if (m_modules.find(module) == m_modules.end()){
        m_modules.insert(module);
        module->initialize(m_manager);
    }
}

void Framework::unloadModule(IModule *module)
{
    if (m_modules.find(module) == m_modules.end()){
        module->terminal();
        m_modules.erase(module);
    }
}

bool Framework::loadPlugin(const std::string &filePath)
{
    if (m_handleMap.find(filePath) != m_handleMap.end()){
        return true;
    }

    HANDLE hLib = ::LoadLibraryA(filePath.c_str());
    if (!hLib){
        return false;
    }
    m_handleMap.insert(std::make_pair(filePath, hLib));

    std::string pluginName = this->fileNameFromPath(filePath);
    if (pluginName.empty()){
        return false;
    }

    std::string entryName = pluginName + "_main";
    PLUGIN_ENTRY entry = (PLUGIN_ENTRY)::GetProcAddress((HMODULE)hLib, entryName.c_str());
    if (entry) {
        IModule * plugin = entry();
        plugin->initialize(m_manager);
        m_pluginMap.insert(std::make_pair(filePath, plugin));
        return true;
    }
    return false;
}

void Framework::unloadPlugin(const std::string &filePath)
{
    auto it1 = m_pluginMap.find(filePath);
    if (it1 != m_pluginMap.end()){
        it1->second->terminal();
        delete it1->second;
        m_pluginMap.erase(it1);
    }
    auto it2 = m_handleMap.find(filePath);
    if (it2 != m_handleMap.end()){
        ::FreeLibrary((HMODULE)it2->second);
        m_handleMap.erase(it2);
    }
}

std::string Framework::fileNameFromPath(const std::string &filePath)
{
    size_t p1 = filePath.find_last_of("/");
    size_t p2 = filePath.find_last_of(".");

    if (p1 != std::string::npos
            && p2 != std::string::npos
            && p2 > p1){
        return filePath.substr(p1 + 1, p2 - p1 - 1);
    }
    return std::string();
}


ObjectMgr *Framework::getObjectManager() const
{
    return m_manager;
}

void Framework::setObjectManager(ObjectMgr *newObjectManager)
{
    if (m_manager == newObjectManager)
        return;
    m_manager = newObjectManager;
    emit objectManagerChanged();
}

JHAppData *Framework::getAppData() const
{
    return m_appData;
}

void Framework::setAppData(JHAppData *newAppData)
{
    if (m_appData == newAppData)
        return;
    m_appData = newAppData;
    emit appDataChanged();
}
