#ifndef JHSTUDENTMANAGER_PLUGIN_H
#define JHSTUDENTMANAGER_PLUGIN_H

#include <QQmlExtensionPlugin>

class JHStudentManagerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // JHSTUDENTMANAGER_PLUGIN_H
