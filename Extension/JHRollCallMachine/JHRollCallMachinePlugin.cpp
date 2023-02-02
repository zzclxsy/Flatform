#include "JHRollCallMachinePlugin.h"

#include "JHRollCallMachine.h"
#include "ScannerItem.h"
#include <qqml.h>
#include <QDebug>
void JHRollCallMachinePlugin::registerTypes(const char *uri)
{
    qmlRegisterType<JHRollCallMachine>(uri, 1, 0, "JHRollCallMachinePlugin");
    qmlRegisterType<ScannerItem>(uri, 1, 0, "ScannerItem");
}

