import QtQuick 2.0
import JHQmlControls 1.0
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.12
Rectangle {
    JHStudentListView{
        id:listview
        anchors.fill: parent
        anchors.bottomMargin: 50
    }

    Rectangle{
        id:dateselect
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: listview.bottom
        anchors.topMargin: 10
        anchors.bottom:parent.bottom
        anchors.bottomMargin:0
        width: 180
        JHButton2{
            id:dateShow
            anchors.fill: parent
            imageSource: "qrc:/JHStudentManager/image/date.svg"
            text: "登记日期选择"
            property bool isshow: false
            onButtonClicked: {
                daterect.visible=!isshow
                isshow=!isshow
            }
        }
    }

    Rectangle{
        id:fresh
        anchors.right: parent.right
        anchors.rightMargin: 100
        anchors.leftMargin: 0
        anchors.top: listview.bottom
        anchors.topMargin: 10
        anchors.bottom:parent.bottom
        anchors.bottomMargin: 0
        width: 90
        JHButton2{
            anchors.fill: parent
            imageSource: "qrc:/JHStudentManager/image/date.svg"
            text: "刷新"
            property bool isshow: false
            onButtonClicked: {

            }
        }
    }
    Rectangle{
        id:save
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.top: listview.bottom
        anchors.topMargin: 10
        anchors.bottom:parent.bottom
        anchors.bottomMargin: 0
        width: 90
        JHButton2{
            anchors.fill: parent
            imageSource: "qrc:/JHStudentManager/image/date.svg"
            text: "保存"
            property bool isshow: false
            onButtonClicked: {

            }
        }
    }




   DropShadow {
        anchors.fill: daterect
        visible: daterect.visible
        horizontalOffset: 0
        verticalOffset: 0
        radius: 8
        samples: 17
        color: "#333333"
        source: daterect
    }

   Rectangle{
       id:daterect
       width:400
       height: 400
       anchors.bottom: dateselect.top
       anchors.bottomMargin: 3
       anchors.left: dateselect.left
       visible: false
       Calendar{
            anchors.fill: parent
            onClicked: {
                dateShow.text=date.getFullYear()+"/"+(date.getMonth()+1)+"/"+date.getDate()
                daterect.visible=!dateShow.isshow
                dateShow.isshow=!dateShow.isshow
            }
       }
   }



}
