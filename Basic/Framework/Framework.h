#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "./Interface/IManager.h"
#include "./Interface/IModule.h"
#include <map>
#include <set>
#include <windows.h>
#include "ObjectMgr.h"
#include "AppData/JHAppData.h"
class Framework:public QObject
{
    Q_OBJECT
    Q_PROPERTY(ObjectMgr * objectManager READ getObjectManager WRITE setObjectManager NOTIFY objectManagerChanged)
    Q_PROPERTY(JHAppData * AppData READ getAppData WRITE setAppData NOTIFY appDataChanged)

public:
    Q_INVOKABLE QString applicationDirPath();

public:
    Framework();

    static Framework* getApp();

    int initialize();


    typedef IModule * (WINAPI * PLUGIN_ENTRY)();

    void addModule(IModule * module);
    void unloadModule(IModule * module);

    bool loadPlugin(const std::string& filePath);
    void unloadPlugin(const std::string& filePath);


    ObjectMgr *getObjectManager() const;
    void setObjectManager(ObjectMgr *newObjectManager);

    JHAppData *getAppData() const;
    void setAppData(JHAppData *newAppData);

signals:
    void objectManagerChanged();
    void appDataChanged();

protected:
    std::string fileNameFromPath(const std::string& filePath);

protected:
    ObjectMgr* m_manager;
    JHAppData *m_appData;
    std::set<IModule *> m_modules;

    std::map<std::string, HANDLE> m_handleMap;
    std::map<std::string, IModule *> m_pluginMap;
};

#endif // FRAMEWORK_H
