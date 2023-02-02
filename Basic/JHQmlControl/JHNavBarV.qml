import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQml 2.12

Rectangle {
    id: navbar2
    color: "transparent"

    property var modelData: []

    property int currentIndex: 0

    signal reqSwitchPage(var pageIndex)
    signal reqOpenPage(var pageIndex)

    Image{
        anchors.fill: parent
        fillMode: Image.Stretch
        source: "qrc:/image/Image/system/nav_blue.jpg"
    }

    ListView{
        width: navbar2.width
        height: navbar2.height - 40
        anchors.verticalCenter: parent.verticalCenter
        orientation: ListView.Vertical
        interactive: false
        spacing:40
        model: ListModel{
            id: navmodel2
        }

        delegate: MouseArea{
            id: navitem3
            width: navbar2.width
            height: icon2.height || 66
            hoverEnabled: true
            opacity: {
                if (navbar2.currentIndex === model.index){
                    return 1.0;
                }
                if (navitem3.containsMouse){
                    return 1.0;
                }
                return 0.6;
            }

            onClicked: {
                if (mouse.modifiers & Qt.ControlModifier){
                    navbar2.reqOpenPage(model.index);
                }else{
                    navbar2.reqSwitchPage(model.index);
                }
                currentIndex = model.index
            }

            Image{
                id: icon2
                width: implicitWidth
                height: implicitHeight
                anchors.horizontalCenter: parent.horizontalCenter
                source: model.icon
            }

            ToolTip{
                id: tt3
                delay: 500
                text: model.name
                visible: navitem3.containsMouse
                topPadding: 8
                bottomPadding: 8
                leftPadding: 12
                rightPadding: 12

                contentItem: Text{
                    text: tt3.text
                }
            }
        }
    }

    onModelDataChanged: {
        navmodel2.clear();
        for (var i = 0; i < modelData.length; ++i){
            navmodel2.append(modelData[i]);
        }
    }

    Component.onCompleted: {

    }
}
