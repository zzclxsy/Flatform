import QtQuick 2.0
import QtGraphicalEffects 1.12
Item {
    property string imageSource
    property string buttonText
    property int textSize:30
    property string buttonTextColor:"#ffffff"
    property bool textGlow: false
    property string imageNormColor:"#00F5F5F5"
    property string imageHoverColor:"#39F5F5F5"
    property string imagePressColor:"#39F5F5F5"
    property alias imageFillMode: image.fillMode
    property int itemMargins: 0
    signal buttonClicked()
    signal buttonPressed()
    signal buttonReleased()
    signal buttonDoubleClicked()
    signal buttonEntered()
    signal buttonExited()

    Rectangle {
        id:item0
        anchors.fill: parent
        color: "transparent"
        anchors.margins: itemMargins
        Image {
            id:image
            anchors.fill: parent
            source: imageSource
        }

        ColorOverlay{
            anchors.fill: image
            source: image
            color: imageNormColor

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    buttonClicked()
                }
                onReleased: {
                    buttonReleased()
                }

                onEntered: {
                    parent.color = imageHoverColor
                    buttonEntered()
                }
                onExited: {
                    parent.color = imageNormColor
                    buttonExited()
                }
                onPressed: {
                    parent.color = imagePressColor
                    buttonPressed()
                }
                onDoubleClicked: {
                    buttonDoubleClicked()
                }
            }
        }

        Text {
            id:text
            color: buttonTextColor
            text:buttonText
            anchors.fill: parent
            font.pixelSize: 0
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5}
}
##^##*/
