import QtQuick 2.0
import QtQuick.Window 2.12
import QtGraphicalEffects 1.12
import QtQml 2.12
import JHQmlControls 1.0
import JHFramework 1.0
import QtQuick.Controls 2.5

Item {
    id: main1

    property var navData: []
    property int currentIndex: 0

    Rectangle{
        id:navBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 110

        JHNavBarV{
            id:navBarV
            anchors.fill: parent
            modelData:navData

            onReqSwitchPage: {
                main1.currentIndex = pageIndex;
            }

            onReqOpenPage: {
                main1.currentIndex = pageIndex;
            }
        }
    }


    SwipeView{
        id: content2
        anchors.left: navBar.right
        anchors.right: parent.right
        height: parent.height
        clip: true
        interactive: false
        currentIndex: main1.currentIndex
    }

    Rectangle{
        anchors.top: parent.top
        anchors.topMargin: 60
        width: content2.width
        anchors.horizontalCenter: content2.horizontalCenter
        height: 6
        clip: true

        Rectangle{
            id: spliter
            width: parent.width
            height: 1
            color: "#FFFFFF"
        }

        DropShadow {
            anchors.fill: spliter
            horizontalOffset: 0
            verticalOffset: 0
            radius: 8
            samples: 17
            color: "#333333"
            source: spliter
        }
    }


    Timer{
        id:initTimer
        running: false
        interval: 100
        repeat: false
        onTriggered: {

            var t = []
            t.push(JHApp.objectManager.getElementInfo("JH.JHStudentManager"))
            t.push(JHApp.objectManager.getElementInfo("JH.RollCallMachine.Random"))

            navData = t;
        }

    }
    Component{
        id: factory

        Loader{
            id: pageLoader1
            asynchronous: true
            property int pageIndex: 0
            property bool isActivePage: pageIndex === content2.currentIndex
            property string pageSource: ""
            property string pageName: ""
            property real sysMenuSize: 280

            source:pageLoader1.pageSource /*{
                console.log("****************************")
                return pageLoader1.isActivePage ? pageLoader1.pageSource : ""
            }*/
        }
    }

    onNavDataChanged: {
        while (content2.count < navData.length){
            content2.addItem(factory.createObject(content2, {}));
        }
        for (var i = 0; i < navData.length; ++i){
            var page = content2.itemAt(i);
            page.pageIndex = i;
            page.pageSource = navData[i].url;
            page.pageName = navData[i].typeCode;
        }
    }

    Component.onCompleted: {

        initTimer.start()
    }
}
