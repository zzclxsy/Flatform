#include "JHStudentManagerPlugin.h"

#include "JHStudentManager.h"

#include <qqml.h>

void JHStudentManagerPlugin::registerTypes(const char *uri)
{
    // @uri JHStudentManager
    qmlRegisterType<JHStudentManager>(uri, 1, 0, "JHStudentManagerPlugin");
}

