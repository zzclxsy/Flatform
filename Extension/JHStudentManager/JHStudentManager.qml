import QtQuick 2.0
import JHStudentManager 1.0
import QtQml 2.12
import JHFramework 1.0

JHStudentManagerPlugin{
    id:plugin
    property var elements: Object()

    Component.onCompleted:{
        plugin.elements={
            "JH.JHStudentManager":{
                "typeCode":"JH.JHStudentManager",
                "name":"学生信息总览",
                "url":"qrc:/JHStudentManager/JHStudentManagerSite.qml",
                "icon":"qrc:/JHStudentManager/icon/studentinfo.svg",
                "description":"管理整体学生相关信息"
            }
        }

        for (var typeCode in plugin.elements){
            JHApp.objectManager.registerUIElement(typeCode, elements[typeCode]);
        }
    }
}

