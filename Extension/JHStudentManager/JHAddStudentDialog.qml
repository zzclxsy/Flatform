import QtQuick 2.0
import JHQmlControls 1.0
import QtQuick.Controls 2.4
JHDialog {
    label:"添加学生"
    function init(){
        listview.switchover()
    }

    handle:Rectangle {
        anchors.fill: parent

        Row{
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            height: 40
            spacing: 20

            Rectangle{
                width: 110
                height: 40
                JHButton2{
                    imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                    text: "添加学生"

                    onButtonClicked: {
                        listview.addStudent();
                    }
                }
            }

            Rectangle{
                width: 110
                height: 40
                JHButton2{
                    imageSource: "qrc:/JHStudentManager/image/delete.svg"
                    text: "删除学生"

                    onButtonClicked: {
                        listview.deleteStudent();
                    }
                }
            }
        }
        JHAddStudentListView{
            id:listview
            anchors.fill: parent
            anchors.margins: 10
            anchors.topMargin: 60
        }

    }
}
