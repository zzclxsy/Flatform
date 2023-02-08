import QtQuick 2.0
import JHQmlControls 1.0
import QtQuick.Particles 2.12
Rectangle {
    property alias overviewList: listview

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
        anchors.bottomMargin: 0
        width: 180
        JHButton2{
            anchors.fill: parent
            imageSource: "qrc:/JHStudentManager/image/date.svg"
            text: "日期选择"
            onButtonClicked: {
                daterect.visible=true
            }
        }
    }

   Rectangle{
       id:daterect
       width:dateselect.width
       height: 400
       anchors.bottom: dateselect.top
       anchors.left: dateselect.left
       visible: false

       ListView{
           anchors.fill: parent
           clip:true
           spacing:10
           model: ListModel{
               ListElement{
                   name:"zz"
               }
               ListElement{
                   name:"zz"
               }
               ListElement{
                   name:"zz"
               }
               ListElement{
                   name:"zz"
               }
               ListElement{
                   name:"zz"
               }
               ListElement{
                   name:"zz"
               }
           }

           delegate: Rectangle{
               height: 40
               width: parent.width
               Text {
                   text: name
               }
           }
       }
   }

}
