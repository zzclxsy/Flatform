import QtQuick 2.12

JHTableCell {
    id: th0
    width: th0.visible ? th0.contentWidth : 0
    visible: tblHeader ? tblHeader.roleMap.hasOwnProperty(th0.tagName) : true
    text: tblHeader ? tblHeader.roleNameMap[roleName] || "" : ""

    property JHTableHeader tblHeader: parent
    property bool resizable: true

    property string roleName: tblHeader ? tblHeader.roleMap[th0.tagName] || "" : ""

    property real contentWidth: {
        if (!tblHeader){
            return 0;
        }
        var roleSize = tblHeader.roleSizeMap[roleName];
        if (roleSize === "auto"){
            return tblHeader.autoSize;
        }
        return Number(roleSize);
    }

    property real miniWidth: Number(tblHeader && tblHeader.miniSizeMap) ? Number(tblHeader.miniSizeMap[roleName]) || 0 : 40


    property point pressedpoint: Qt.point(0, 0)

    MouseArea{
        width: 6
        height: parent.height
        anchors.horizontalCenter: parent.right
        hoverEnabled: true
        visible: parent.resizable
        z:999
        onEntered: {
            cursorShape = Qt.SizeHorCursor;
        }

        onPressed: {
            pressedpoint = Qt.point(mouse.x, mouse.y);
            if (th0.parent && th0.parent.pressed){
                th0.parent.pressed(th0, mouse);
            }
        }

        onPositionChanged: {
            if (!(mouse.buttons & Qt.LeftButton)){
                return;
            }
            var w = parent.width + mouse.x - pressedpoint.x;
            parent.contentWidth = Math.max(w, th0.miniWidth);
            if (tblHeader && roleName){
                tblHeader.updateRoleSize(roleName, Math.max(w, th0.miniWidth));
            }else{
                parent.contentWidth = Math.max(w, th0.miniWidth);
            }
        }

        onReleased: {
            if (th0.parent && th0.parent.released){
                th0.parent.released(th0, mouse);
            }
        }
    }
}
