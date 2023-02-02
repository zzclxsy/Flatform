import QtQuick 2.12
import QtQuick.Window 2.12

MouseArea {
    id: operator
    hoverEnabled: true

    property point startPos: Qt.point(0, 0)

    onPressed: {
        operator.startPos = Qt.point(mouse.x, mouse.y);
    }

    onPositionChanged: {
        if (mouse.buttons & Qt.LeftButton){
            operator.handlePositionChanged(mouse);
        }
    }

    onReleased: {

    }

    function handlePositionChanged(mouse){

    }
}
