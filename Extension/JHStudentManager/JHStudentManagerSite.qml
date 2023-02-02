import QtQuick 2.0
import QtQuick.Controls 1.2
import JHQmlControls 1.0
import QtQml 2.12
import QtGraphicalEffects 1.12
import JHFramework 1.0
Item {
    Item{
        id: tb1
        width: parent.width
        height: 60
        anchors.top: parent.top

        Text{
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.pixelSize: 20
            font.family: "Microsoft Yahei"
            text: "学生信息总览"
        }
    }

    JHAddStudentDialog{
        id:addStudent
        width: 700
        height: 400
    }

    Rectangle{
        id:conent
        anchors.fill: parent
        anchors.topMargin: 60

        Rectangle{
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom:listview.top
            anchors.bottomMargin: 10
            width: 110
            height: 40
            JHButton2{
                anchors.fill: parent
                imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                text: "添加学生"

                onButtonClicked: {
                    addStudent.showPage()
                    addStudent.width = conent.width/4*3
                    addStudent.height = conent.height/5*4

                   // addStudent.listmodel = null
                    addStudent.listmodel = SMApi.studentModel
                }
            }
        }

        JHStudentListView{
            id:listview
            anchors.fill: parent
            anchors.margins: 20
            anchors.topMargin: 60
        }
    }

    Component.onCompleted: {
//        var index = 0
//        for (var i = 0; i <50 * 6; i+=6)
//        {
//            listmodel.append(setData(i,"张"+i,i+2,i+3,i+4,"gdfg","gdfg",index))
//            index++
//        }
//        console.log(listmodel.count)
    }

    function setData(a,b,c,d,e,f,g,index){
        var data = {"chinese":a,"name":b,"mathematics":c,"english":d,"score":e,"remark":f,"sex":1,"index":index}
        return data
    }

}
