import QtQuick 2.12

MouseArea {
    id: tc0
    height: parent ? parent.height : 0

    property bool tableCell: true
    property Item prevCell: null
    property Item nextCell: null

    property string tagName: "A"
    property string text: ""

    property bool rowClickEnabled: true

    anchors.left: {
        if (tc0.prevCell){
            return tc0.prevCell.right;
        }
        if (tc0.parent){
            return tc0.parent.left;
        }
        return undefined;
    }
    anchors.leftMargin: tc0.parent ? tc0.parent.spacing || 0 : 0

    onClicked: {
        if (rowClickEnabled && tc0.parent && tc0.parent.clicked){
            tc0.parent.clicked(tc0, mouse);
        }
    }

    Rectangle{
        anchors.fill: parent
        color: {
            if (tc0.parent && tc0.parent.selectState){
                return "#ECF7FE";
            }
            return "transparent";
        }
    }

    onTagNameChanged: {
        if (tc0.decoratorItem
                && tc0.decoratorItem.hasOwnProperty("tagName")){
            tc0.decoratorItem.tagName = tc0.tagName;
        }
    }

    Text{
        id: text1
        width: Math.min(parent.width - 4, text1.implicitWidth)
        anchors.centerIn: parent
        clip: true
//        elide: Text.ElideRight
        font.family: qsTr("宋体")
        font.pixelSize: 15
        font.weight: Font.Bold
        color: "black"
        text: tc0.text
        visible: tc0.text.length > 0
        horizontalAlignment: Text.AlignLeft
    }

    Rectangle{
        width: 1
        height: parent.height
        anchors.horizontalCenter: parent.right
        color: "#EEEEEE"
        z: 99
    }
}
