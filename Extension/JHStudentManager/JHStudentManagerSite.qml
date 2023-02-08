import QtQuick 2.0
import QtQuick.Controls 1.2
import JHQmlControls 1.0
import QtQml 2.12
import QtGraphicalEffects 1.12
import JHFramework 1.0
import QtQuick.Controls 2.5
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

        Row{
            anchors.top: parent.top
            anchors.bottom: content.top
            anchors.left: parent.left
            anchors.right: addstudentRect.left
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            anchors.topMargin: 12
            anchors.bottomMargin: 5
            spacing: 10

            Rectangle{
                width: 110
                height: parent.height

                JHButton2{
                    id:button1
                    anchors.fill: parent
                    selectColor:"#99CCFF"
                    imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                    text: "成绩总览"
                    onButtonClicked: {
                        setColor(selectColor)
                        content.currentIndex = 0
                        button2.selected =false
                        button2.clearColor()
                    }

                    Component.onCompleted: {
                        selected = true
                        setColor(selectColor)
                    }
                }
            }

            Rectangle{
                width: 110
                height: parent.height
                JHButton2{
                    id:button2
                    anchors.fill: parent
                    imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                    text: "成绩登入"
                    selectColor:"#99CCFF"
                    onButtonClicked: {
                        setColor(selectColor)
                        content.currentIndex = 1
                        button1.selected =false
                        button1.clearColor()
                    }
                }
            }
        }

        Rectangle{
            id:addstudentRect
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 12
            anchors.bottom:content.top
            anchors.bottomMargin: 5
            width: 110
            height: 40
            JHButton2{
                anchors.fill: parent
                imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                text: "添加学生"
                property bool modelInit: false
                onButtonClicked: {
                    selected = false
                    addStudent.width = conent.width/4*3
                    addStudent.height = conent.height/5*4
                    addStudent.showPage()
                    if (modelInit === false){
                        addStudent.init()
                        modelInit = true
                    }
                }
            }
        }


        SwipeView{
            id: content
            anchors.fill: parent
            anchors.margins: 20
            anchors.topMargin: 60
            interactive:false
            spacing: 20
            JHStudentListView{
                id:listview
            }
            JHStudentListView{
                id:listview3
            }
        }
    }

    Component.onCompleted: {

    }
}
