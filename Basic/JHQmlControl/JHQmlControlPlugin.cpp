#include "JHQmlControlPlugin.h"
#include <qqml.h>
#include "JHQmlControls.h"
void JHQmlControlPlugin::registerTypes(const char *uri)
{
//    // @uri JHQmlControls
    qmlRegisterType<JHQmlControls>(uri, 1, 0, "JHQmlControlPlugin");

//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHNavBarV.qml"),uri,1,0,"JHNavBarV");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHButton.qml"),uri,1,0,"JHButton");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHMessagePopup.qml"),uri,1,0,"JHMessagePopup");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHPopup.qml"),uri,1,0,"JHPopup");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHMask.qml"),uri,1,0,"JHMask");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHDialog.qml"),uri,1,0,"JHDialog");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHTableView.qml"),uri,1,0,"JHTableView");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHTableHeader.qml"),uri,1,0,"JHTableHeader");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHTableRow.qml"),uri,1,0,"JHTableRow");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHTableColumn.qml"),uri,1,0,"JHTableColumn");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHTableCell.qml"),uri,1,0,"JHTableCell");
//    qmlRegisterType(QUrl("qrc:/JHQmlControl/JHButton2.qml"),uri,1,0,"JHButton2");
}

