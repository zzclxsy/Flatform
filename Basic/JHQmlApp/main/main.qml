import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import QtGraphicalEffects 1.12
import JHQmlControls 1.0
import JHFramework 1.0
import an.window 1.0
FramelessWindow {
    id: window0
    visible: true
    width: 1280
    height: 760
    minimumWidth: 1280
    minimumHeight: 760

    title: qsTr("Hello World")

    color: "transparent"
    property int windowRadius: (window0.visibility == Window.Windowed) ? 4 : 0
    property int contentMargin: (window0.visibility == Window.Windowed) ? 8 : 0
    property string contentUrl: "111"
    property bool resizable: true


    JHPluginLoader{

    }

    Rectangle{
        id: bk0
        anchors.fill: parent
        anchors.margins: window0.contentMargin
        radius: window0.windowRadius
        color: "#888888"
    }

    DropShadow {
        anchors.fill: bk0
        horizontalOffset: 0
        verticalOffset: 0
        radius: window0.contentMargin
        samples: 17
        color: "#000000"
        source: bk0
    }

    Rectangle{
        id:groundFloor
        anchors.fill: parent
        radius: window0.windowRadius
        anchors.margins: window0.contentMargin

        Loader{
            id:loader
            anchors.fill: parent
            source: "qrc:/JHLoginView.qml"
        }
    }

    JHMessageClient{
        domainID: "Login"
        filter: ["loginState","url"]
        onHasDomainData: {
            if (domainData["loginState"] === "logged"){
                loader.source = domainData["url"]
            }
        }
    }

    Rectangle{
        id:statusBar
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        width: windowOperButton.width
        height: 50
        color: "transparent"
        Row{
            id:windowOperButton

            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 150
            spacing: 10
            Rectangle{
                id:minWinWindow
                height: parent.height
                width: 40
                radius: window0.windowRadius
                color: "transparent"
                JHButton{
                    anchors.fill: parent
                    itemMargins:5
                    imageFillMode:Image.PreserveAspectFit
                    imageSource: "qrc:/image/Image/system/minwin.svg"
                    imageNormColor:"#CCCCCC"
                    imageHoverColor: "#CCCCCC"
                    imagePressColor: "#CCCCCC"
                    onButtonEntered: {
                        minWinWindow.color="#50CCCCCC"
                    }
                    onButtonPressed: {
                        minWinWindow.color="#50B0B0B0"
                    }

                    onButtonExited: {
                        minWinWindow.color="transparent"
                    }
                    onButtonReleased: {
                        window0.visibility = Window.Minimized
                    }
                }
            }

            Rectangle{
                id:maxWinWindow
                height: parent.height
                width: 40
                radius: window0.windowRadius
                color: "transparent"
                JHButton{
                    anchors.fill: parent
                    itemMargins:8
                    imageFillMode:Image.PreserveAspectFit
                    imageSource: "qrc:/image/Image/system/smallWin.svg"
                    imageNormColor:"#CCCCCC"
                    imageHoverColor: "#CCCCCC"
                    imagePressColor: "#CCCCCC"
                    onButtonEntered: {
                        maxWinWindow.color="#50CCCCCC"
                    }
                    onButtonPressed: {
                        maxWinWindow.color="#50B0B0B0"
                    }

                    onButtonExited: {
                        maxWinWindow.color="transparent"
                    }
                    onButtonReleased: {
                        if (window0.visibility === Window.Maximized){
                            window0.visibility = Window.Windowed
                            imageSource= "qrc:/image/Image/system/smallWin.svg"
                        }else{
                            window0.visibility = Window.Maximized
                            imageSource = "qrc:/image/Image/system/largeWin.svg"
                        }
                    }
                }
            }

            Rectangle{
                id:closeWindow
                height: parent.height
                width: 40
                radius: window0.windowRadius
                color: "transparent"
                JHButton{
                    anchors.fill: parent
                    itemMargins:8
                    imageFillMode:Image.PreserveAspectFit
                    imageSource: "qrc:/image/Image/system/close.svg"
                    imageNormColor:"#CCCCCC"
                    imageHoverColor: "#ffffffff"
                    imagePressColor: "#ffffffff"
                    onButtonEntered: {
                        closeWindow.color="#ff0000"
                    }
                    onButtonPressed: {
                        closeWindow.color="#cc0000"
                    }

                    onButtonExited: {
                        closeWindow.color="transparent"
                    }
                    onButtonClicked: {
                        window0.close()
                    }
                }
            }
        }
    }


    Component.onCompleted: {

    }

}
