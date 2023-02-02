#ifndef JHROLLCALLMACHINEPLUGIN_H
#define JHROLLCALLMACHINEPLUGIN_H

#include <QQmlExtensionPlugin>

class JHRollCallMachinePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // JHROLLCALLMACHINEPLUGIN_H
