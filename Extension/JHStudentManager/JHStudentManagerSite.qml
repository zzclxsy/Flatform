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
                    selected:true
                    selectColor:"#99CCFF"
                    imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                    text: "成绩总览"
                    onButtonClicked: {
                        selected = true
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
                    selected:false
                    imageSource: "qrc:/JHStudentManager/image/addStudent.svg"
                    text: "成绩登记"
                    selectColor:"#99CCFF"
                    onButtonClicked: {
                        selected = true
                        content.currentIndex = 1
                        button1.selected =false
                        button1.clearColor()
                    }
                }
            }
        }

        Rectangle{
            id:subject
            anchors.right: parent.right
            anchors.rightMargin: 150
            anchors.top: parent.top
            anchors.topMargin: 12
            anchors.bottom:content.top
            anchors.bottomMargin: 5
            width: 130
            height: 40
            JHButton2{
                id:subjectbtn
                anchors.fill: parent
                imageSource: "qrc:/JHStudentManager/image/date.svg"
                text: "学科过滤器"
                property bool isshow: false
                onButtonClicked: {
                    subjectselect.visible=!isshow
                    isshow=!isshow
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

            JHStudentOverview{
                id:overview
            }

            JHStudentScoreEntry{

            }
        }

        DropShadow {
             anchors.fill: subjectselect
             visible: subjectselect.visible
             horizontalOffset: 0
             verticalOffset: 0
             radius: 8
             samples: 17
             color: "#333333"
             source: subjectselect
         }

        Rectangle{
            id:subjectselect
            width:subject.width
            height: 400
            anchors.top: subject.bottom
            anchors.topMargin: 3
            anchors.right: subject.right
            visible: false

            ListView{
                id:sublist
                anchors.fill: parent
                anchors.bottomMargin: 40
                clip:true
                model: ListModel{
                    ListElement{
                        name:"  语文"
                    }
                    ListElement{
                        name:"  数学"
                    }
                    ListElement{
                        name:"  英语"
                    }
                    ListElement{
                        name:"  物理"
                    }
                    ListElement{
                        name:"  化学"
                    }
                    ListElement{
                        name:"  生物"
                    }
                    ListElement{
                        name:"  政治"
                    }
                    ListElement{
                        name:"  历史"
                    }
                    ListElement{
                        name:"  地理"
                    }
                }

                delegate: Rectangle{
                    height: 40
                    width: parent.width
                    CheckBox{
                        anchors.fill: parent
                        text: name
                        onCheckStateChanged: {
                            if (checkState == Qt.Unchecked){
                                overview.overviewList.setVisable(index,false)
                            }else if (checkState == Qt.Checked){
                                overview.overviewList.setVisable(index,true)
                            }
                        }
                        Component.onCompleted: {
                            if(index == 0)
                                checkState = Qt.Checked

                            if(index == 1)
                                checkState = Qt.Checked

                            if(index == 2)
                                checkState = Qt.Checked

                        }
                    }
                }
            }

            Rectangle{
                anchors.right: parent.right
                anchors.rightMargin: 30
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.top: sublist.bottom
                anchors.topMargin: 5
                anchors.bottom:subjectselect.bottom
                anchors.bottomMargin: 5
                radius: 4
                width: parent.width
                border.color: "#C0C0C6"
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "宋体"
                    text: qsTr("关闭")
                }
                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        parent.color="#99CCFF"
                    }
                    onExited: {
                        parent.color ="transparent"
                    }
                    onClicked: {
                        subjectselect.visible=!subjectbtn.isshow
                        subjectbtn.isshow=!subjectbtn.isshow
                    }
                }

            }
        }
    }

    Component.onCompleted: {

    }
}
