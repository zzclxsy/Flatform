import QtQuick 2.0

JHTableRow {
    id:th0
    property real autoSize: 100
    Rectangle{
        width: parent.width
        height: 1
        z: 999
        anchors.top: parent.top
        color: "#C0C0C6"
    }

    property real miniWidth: 1000
    property var roleMap: {
        "A": "COLA",
        "B": "COLB",
        "C": "COLC",
        "D": "COLD",
        "E": "COLE",
        "F": "COLF"
    }

    property var roleNameMap: {
        "COLA": "COLUMN A",
        "COLB": "COLUMN B",
        "COLC": "COLUMN C",
        "COLD": "COLUMN D",
        "COLE": "COLUMN E",
        "COLF": "COLUMN F"
    }
    property var roleSizeMap: {
        "COLA": 100,
        "COLB": 100,
        "COLC": 100,
        "COLD": 100,
        "COLE": 100,
        "COLF": 100
    }
    property var miniSizeMap: {
        "COLA": 40,
        "COLB": 40,
        "COLC": 40,
        "COLD": 40,
        "COLE": 40,
        "COLF": 40
    }
    function getRoleName(role){
        var roleName = roleMap[role];
        if (roleName){
            return roleNameMap[roleName] || 0;
        }
        return 0;
    }

    onWidthChanged: {
        updateAutoRoleSize();
    }

    onMiniWidthChanged: {
        updateTableWidth();
    }

    onRoleMapChanged: {
        updateTableWidth();
        updateAutoRoleSize();
    }

    onRoleSizeMapChanged: {
        updateTableWidth();
        updateAutoRoleSize();
    }

    function updateTableWidth(){
        var totalWidth = 0;
        for(var p in roleMap){
            var roleName = roleMap[p];
            var roleSize = roleSizeMap[roleName] || 0;
            if (roleSize === "auto"){
                roleSize = miniSizeMap[roleName] || 0;
            }
            totalWidth += Number(roleSize);
        }
        th0.width = Math.max(th0.miniWidth, totalWidth);
    }

    function updateAutoRoleSize(){
        var usedSize = 0;
        var autoCount = 0;
        for(var p in roleMap){
            var roleName = roleMap[p];
            var roleSize = roleSizeMap[roleName] || 0;
            if (roleSize === "auto"){
                autoCount += 1;
            }else{
                usedSize += Number(roleSize);
            }
        }
        var v = autoCount > 0 ? (th0.width - usedSize) / autoCount : 0;

        autoSize = Math.max(v, 0);
    }

    function updateRoleSize(role, size){
        var t = {};
        for (var p in roleSizeMap){
            t[p] = roleSizeMap[p];
        }
        t[role] = size;
        roleSizeMap = t;
    }
}
