import QtQuick 2.0
import JHQmlControls 1.0
import QtGraphicalEffects 1.12
import QtQml 2.12
JHPopup {
    id: page
    focus: true
    visible: true
    opacity: 0
    showMask: true
    animationType:"size"
    anchors.centerIn: parent
    property alias label: labelText.text
    property Item handle: Rectangle{
        anchors.fill: parent
        color: "green"
    }

    function showPage(){
        save()
        show()
    }

    Rectangle{
        id:main0
        anchors.fill: parent
        color: "#ffffff"

        Rectangle{
            id:close
            anchors.top: parent.top
            anchors.right: parent.right
            width: 30
            height: 30

            JHButton{
                anchors.fill: parent
                imageFillMode:Image.PreserveAspectFit
                anchors.margins: 3
                imageSource: "qrc:/image/Image/system/close.svg"
                imageNormColor:"#CCCCCC"
                imageHoverColor: "#ffffffff"
                imagePressColor: "#ffffffff"
                onButtonEntered: {
                    close.color="#ff0000"
                }
                onButtonPressed: {
                    close.color="#cc0000"
                }

                onButtonExited: {
                    close.color="transparent"
                }
                onButtonReleased: {
                    page.hide()
                }
            }

        }

        Rectangle{
            id:dialoglabel
            anchors.top: parent.top
            anchors.left: parent.left
            height: 30
            width: parent.width - close.width
            Text {
                id: labelText
                anchors.fill: parent
                anchors.leftMargin: 5
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.family: "Microsoft Yahei"
                font.pixelSize: 15
                font.letterSpacing: 3
                text: qsTr("")
            }
        }

        Rectangle{
            id:spliteRect
            anchors.top: parent.top
            anchors.topMargin: 30
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
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
        Rectangle{
            id:block
            anchors.top: spliteRect.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            children:[page.handle]
        }
    }

    DropShadow {
        anchors.fill: main0
        horizontalOffset: 0
        verticalOffset: 0
        radius: 5
        samples: 10
        color: "#000000"
        source: main0
    }
    Component.onCompleted: {
        page.visible = false
        page.opacity = 1;
    }
}
