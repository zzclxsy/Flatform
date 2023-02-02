import QtQuick 2.0
import JHRollCallMachine 1.0
import QtQml 2.12
import JHFramework 1.0

JHRollCallMachinePlugin{
    id:plugin
    property var elements: Object()

    Component.onCompleted:{
        plugin.elements={
            "JH.RollCallMachine.Random":{
                "typeCode":"JH.RollCallMachine.Random",
                "name":"随机点名",
                "url":"qrc:/JHRollCallMachine/JHRandomSite.qml",
                "icon":"qrc:/JHRollCallMachine/icon/Roll.png",
                "description":"随机点名页面"
            }
        }

        for (var typeCode in plugin.elements){
            JHApp.objectManager.registerUIElement(typeCode, elements[typeCode]);
        }
    }
}

