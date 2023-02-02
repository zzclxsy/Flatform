import QtQuick 2.0

Item {
    property alias radius: item0.radius
    Rectangle{
        id: item0
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        Rectangle {
            id: rectangle
            x: 194
            y: 61
            width: 200
            height: 200
            color: "#633b3b"
        }

        Rectangle {
            id: rectangle1
            x: 194
            width: 200
            height: 200
            color: "#7a1f1f"
            anchors.top: rectangle.bottom
            anchors.topMargin: 19
        }



    }
}
