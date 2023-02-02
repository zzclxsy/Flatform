import QtQuick 2.0
import QtQuick.Window 2.12
import QtGraphicalEffects 1.12
import QtQml 2.12
import "./JHQmlControl/"
Item {

    property var navData: []
    Rectangle{
        id: spliter
        width: parent.width
        height: 1
        anchors.top: statusBar.bottom
        anchors.topMargin: -1
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
                var tc = navData[pageIndex];
                console.log("1",tc.index,tc.name)
                navBarV.currentIndex = tc.index
            }

            onReqOpenPage: {
                var tc = navData[pageIndex];
               console.log("3",tc.index,tc.name)
            }
        }
    }

    Rectangle{
        id:statusBar
        anchors.top: parent.top
        anchors.topMargin: window0.contentMargin/2
        anchors.left: navBar.right
        anchors.right: parent.right
        height: 60

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
                color: "#ffffffff"
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
                        minWinWindow.color="#ffffffff"
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
                color: "#ffffffff"
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
                        maxWinWindow.color="#ffffffff"
                    }
                    onButtonReleased: {
                        if (window0.visibility == Window.Maximized){
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
                color: "#ffffffff"
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
                        closeWindow.color="#ffffffff"
                    }
                    onButtonReleased: {
                        window0.close()
                    }
                }
            }
        }
    }
    Component.onCompleted: {
        var t={}
        t["index"] = 0
        t["name"] = "4554"
        console.log(t.name)
        navData.push(t)

        var t2={}
        t2["index"] = 1
        t2["name"] = "eee"
        console.log(t2.name)
        navData.push(t2)

//        navData.push("ew")
//        navData.push("5665")
        navBarV.modelData = navData
    }
}
