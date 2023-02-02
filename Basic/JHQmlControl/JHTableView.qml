import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQml 2.12

ListView {
    id: listView
    clip: true
    header: headerView

    headerPositioning: ListView.OverlayHeader
    flickableDirection:Flickable.VerticalFlick
    contentWidth:headerItem.width


    ScrollBar.vertical: ScrollBar { minimumSize: 0.1}
    ScrollBar.horizontal: ScrollBar {minimumSize: 0.1 }
    property int headerHeight: headerItem.height
    property Item headerItem
    Component{
        id:headerView
        Rectangle{
            width: contentWidth
            height: headerHeight
            z:900
            children: headerItem
        }
    }
    section.property: "index"
    section.delegate: Rectangle{
        width: contentWidth
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#EEEEEE"
    }
    footer: Rectangle{
        width: contentWidth
        height: 1
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#EEEEEE"
    }

}
