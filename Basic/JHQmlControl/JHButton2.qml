import QtQuick 2.0
import QtGraphicalEffects 1.12
Rectangle{
    anchors.fill: parent
    radius: 4
    border.color: "#C0C0C6"
    border.width: 1
    property bool selected:false
    property string selectColor:"transparent"
    property alias imageSource: image.source
    property alias text: showtext.text
    signal buttonClicked()
    signal buttonPressed()
    signal buttonReleased()
    signal buttonDoubleClicked()
    signal buttonEntered()
    signal buttonExited()

    function clearColor(){
        color="transparent"
    }
    function setColor(vet){
        color = (vet)
    }

    Image {
        id:image
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 5
        width:height
    }

    ColorOverlay{
        id:imagecolor
        anchors.fill: image
        source: image
        color: "transparent"
    }

    Text {
        id:showtext
        anchors.fill: parent
        anchors.left: image.right
        anchors.leftMargin: 30
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "宋体"
        text: qsTr("")
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            parent.color="#99CCFF"
            imagecolor.color="white"
            buttonEntered()
        }
        onExited: {
            imagecolor.color = "transparent"

            if ( selected ===false){
              parent.color = "transparent"
            }

            buttonExited()
        }
        onClicked: {
            selected = true
            buttonClicked()
        }
        onPressed: {
            buttonPressed()
        }
        onReleased: {
            buttonReleased()
        }
        onDoubleClicked: {
            buttonDoubleClicked()
        }
    }
}
