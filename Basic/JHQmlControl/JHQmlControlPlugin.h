#ifndef JHQMLCONTROLPLUGIN_H
#define JHQMLCONTROLPLUGIN_H

#include <QQmlExtensionPlugin>

class JHQmlControlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // JHQMLCONTROLPLUGIN_H
