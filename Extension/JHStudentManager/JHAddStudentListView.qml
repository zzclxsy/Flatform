import QtQuick 2.0
import JHQmlControls 1.0
import QtQuick.Controls 2.4
import QtQml 2.12
Rectangle {
    function switchover(){
        dataListView.model = null
        dataListView.model = SMApi.studentModel
    }

    function addStudent()
    {
        dataListView.focus = true
        var data = {"chinese":-1,"name":"","mathematics":-1,"english":-1,"score":0,"remark":"","sex":0}

        SMApi.studentModel.addStudent(data)
        dataListView.positionViewAtEnd()
    }
    function deleteStudent()
    {
        if (modelCurrentIndex >= dataListView.count)
            return

        SMApi.studentModel.deleteStudent(modelCurrentIndex)
    }

    property int modelCurrentIndex: 0

    Connections{
        target: SMApi.studentModel
        onRemoveData:{
            switchover()
            dataListView.positionViewAtIndex(modelCurrentIndex,ListView.Center)
        }
    }

    Flickable{
        id:slotFlick
        clip: true
        anchors.fill: parent
        contentWidth: headerD.width
        contentHeight: slotFlick.height
        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.HorizontalFlick
        ScrollBar.horizontal: ScrollBar {minimumSize: 0.1 }


        JHTableHeader{
            id:headerD

            miniWidth: slotFlick.width
            roleMap: {
                "A": "index",
                "B": "name",
                "C": "sex",
                "D": "remark",
            }

            roleNameMap: {
                "index": "序号",
                "name": "姓名",
                "sex": "性别",
                "remark": "备注",
            }
            roleSizeMap: {
                "index": 50,
                "name": 150,
                "sex": 70,
                "remark": "auto"
            }
            miniSizeMap: {
                "index": 50,
                "name": 150,
                "sex": 70,
                "remark": 100,
            }
            height: 50
            JHTableColumn{
                id:columnA
                tagName:"A"
                resizable:false
            }

            JHTableColumn{
                id:columnB
                tagName:"B"
                resizable:true
            }
            JHTableColumn{
                id:columnC
                tagName:"C"
                resizable:false
            }
            JHTableColumn{
                id:columnD
                tagName:"D"
                resizable:true
            }
            JHTableColumn{
                id:columnE
                tagName:"E"
                resizable:false
            }

            JHTableColumn{
                id:columnF
                tagName:"F"
                resizable:false
            }

            JHTableColumn{
                id:columnG
                tagName:"G"
            }

            JHTableColumn{
                id:columnH
                tagName:"H"
            }

            JHTableColumn{
                id:columnI
                tagName:"I"
            }

            JHTableColumn{
                id:columnJ
                tagName:"J"
            }

            JHTableColumn{
                id:columnK
                tagName:"K"
            }

            JHTableColumn{
                id:columnL
                tagName:"L"
            }

            JHTableColumn{
                id:columnM
                tagName:"M"
            }

            JHTableColumn{
                id:columnN
                tagName:"N"
            }


            JHTableColumn{
                id:columnO
                tagName:"O"
            }

            JHTableColumn{
                id:columnP
                tagName:"P"
            }

            JHTableColumn{
                id:columnQ
                tagName:"Q"
            }


            onPressed: {
                slotFlick.interactive = false;
                dataListView.interactive = false;
            }

            onReleased: {
                slotFlick.interactive = true;
                dataListView.interactive = true;
            }
        }

        JHTableView {
            id: dataListView
            anchors.fill: parent
            headerItem:headerD
            property var isSelectItem: null

            delegate: JHTableRow{
                id:row
                width: headerD.width
                color: "white"
                height: 50
                selectState:(modelCurrentIndex === index)?true:false
                JHTableCell {
                    id: cellA
                    tagName: columnA.tagName
                    width:columnA.width
                    visible: columnA.visible
                    Rectangle{
                        anchors.fill: parent
                        color: selectState?"#CDD1CF":"#E6E6E8"
                        Text{
                            anchors.fill: parent
                            anchors.centerIn: parent
                            clip: true
                            font.family: "黑体"
                            font.pixelSize: 15
                            font.weight: Font.Bold
                            color: "black"
                            text: model.index
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment:Text.AlignVCenter
                        }
                    }
                }
                JHTableCell {
                    id: cellB

                    tagName: columnB.tagName
                    width:   columnB.width
                    visible: columnA.visible

                    TextField{
                        id:textB
                        anchors.fill: parent
                        horizontalAlignment: TextInput.AlignHCenter
                        text: model.data.name
                        placeholderText:"输入姓名"
                        font.family:"宋体"
                        font.bold:true
                        font.pixelSize:20
                        selectByMouse:true
                        selectionColor:"#D0E6FC"
                        background: Rectangle{
                            anchors.fill: parent
                            anchors.margins: 1
                            color:  parent.focus?"white":"transparent"
                            radius: 5
                            border.width: 1
                            border.color:parent.focus? "#C0C0C6":"transparent"
                        }
                        onEditingFinished: {
                            focus = false
                            cellBm.width = cellB.width

                            if (model.data.name === text)
                                return

                            SMApi.studentModel.updataStudentInfo(index,headerD.roleMap[columnB.tagName],text)
                        }
                    }
                    Rectangle{
                        id:cellBm
                        anchors.top: parent.top
                        anchors.left: parent.Left
                        anchors.bottom: parent.bottom
                        width: parent.width
                        color: "transparent"
                        MouseArea{
                            anchors.fill: parent
                            onDoubleClicked: {
                                textB.focus = true
                                cellBm.width = 1
                            }
                            onPressed: {
                                dataListView.isSelectItem = row
                                modelCurrentIndex = index
                            }
                        }
                    }
                }
                JHTableCell {
                    id: cellC

                    tagName: columnC.tagName
                    width: columnC.width
                    visible: columnA.visible
                    property int comboxIndex: model.data.sex

                    ComboBox{
                        anchors.fill: parent
                        currentIndex:cellC.comboxIndex
                        property bool initfinished: false
                        flat:true
                        background: Rectangle{
                            anchors.fill: parent
                            color: "transparent"
                        }

                        textRole: "man"
                        model: ListModel {
                            ListElement { man: "空"}
                            ListElement { man: "男"}
                            ListElement { man: "女"}
                        }
                        onCurrentIndexChanged: {
                            if (initfinished == false){
                                initfinished = true
                                return
                            }

                            SMApi.studentModel.updataStudentInfo(index,headerD.roleMap[cellC.tagName],currentIndex)
                        }
                        onPressedChanged: {
                            if (pressed == true){
                                dataListView.isSelectItem = row
                                modelCurrentIndex = index
                            }
                        }
                    }
                }
                JHTableCell {
                    id: cellD
                    tagName: columnD.tagName
                    width: columnD.width
                    visible: columnA.visible
                    TextField{
                        id:textD
                        anchors.fill: parent
                        horizontalAlignment: TextInput.AlignHCenter
                        text: model.data.remark
                        placeholderText:"该学生备注"
                        font.family:"宋体"
                        font.bold:true
                        font.pixelSize:20
                        selectByMouse:true
                        selectionColor:"#D0E6FC"
                        property bool isedit: false
                        background: Rectangle{
                            anchors.fill: parent
                            anchors.margins: 1
                            color:  parent.focus?"white":"transparent"
                            radius: 5
                            border.width: 1
                            border.color:parent.focus? "#C0C0C6":"transparent"
                        }
                        onEditingFinished: {
                            focus = false
                            cellDm.width = cellD.width

                            if (model.data.remark === text)
                                return

                            SMApi.studentModel.updataStudentInfo(index,headerD.roleMap[columnD.tagName],text)
                        }
                    }

                    Rectangle{
                        id:cellDm
                        anchors.top: parent.top
                        anchors.left: parent.Left
                        anchors.bottom: parent.bottom
                        width: parent.width
                        color: "transparent"
                        MouseArea{
                            anchors.fill: parent
                            onDoubleClicked: {
                                textD.focus = true
                                cellDm.width = 1
                            }
                            onPressed: {
                                dataListView.isSelectItem = row
                                modelCurrentIndex = index
                            }
                        }
                    }

                }


                onClicked: {
                    dataListView.isSelectItem = row
                    modelCurrentIndex = index
                }
            }
        }
    }


    Rectangle{
        anchors.fill: parent
        color: "transparent"
        border.width: 1
        border.color: "#C0C0C6"
    }
}

