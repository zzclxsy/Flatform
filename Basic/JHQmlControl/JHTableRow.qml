import QtQuick 2.12

Rectangle {
    id: tr0
    height: 40
    color: "#D0E6FC"
    property real spacing: 0

    property var cells: []
    property int selectState: 0

    signal pressed(var c, var evt)
    signal released(var c, var evt)
    signal clicked(var c, var evt)

    implicitWidth: {
        var w = 0;
        for (var i = 0; i < cells.length; ++i){
            w += cells[i].width;
        }

        return w;
    }

    Rectangle{
        width: 1
        height: parent.height
        z: 999
        anchors.left: parent.left
        color: "#C0C0C6"
    }

    Rectangle{
        width: 1
        height: parent.height
        z: 999
        anchors.right: parent.right
        color: "#C0C0C6"
    }

    onChildrenChanged: {

        var tcs = [];
        for (var i = 0; i < tr0.children.length; ++i){
            if (tr0.children[i].tableCell === true && tr0.children[i].visible === true)
            {
                tcs.push(tr0.children[i]);
                tr0.children[i].z = tr0.children.length - i;
            }

        }
        for (var j = 1; j < tcs.length; ++j){
            tcs[j].prevCell = tcs[j - 1];
            tcs[j - 1].nextCell = tcs[j];
        }
        if (tcs.length > 0){
            tcs[0].prevCell = null;
            tcs[tcs.length - 1].nextCell = null;
        }
        tr0.cells = tcs;
    }
}
