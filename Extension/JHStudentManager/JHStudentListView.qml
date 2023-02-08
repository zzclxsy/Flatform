import QtQuick 2.0
import JHQmlControls 1.0
import QtQuick.Controls 2.4
import QtQml 2.12
import JHFramework 1.0
Rectangle {
    Connections{
        target: SMApi.studentModel
        onRemoveData:{
            dataListView.model = null
            dataListView.model = SMApi.studentModel
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
                "C": "chinese",
                "D": "mathematics",
                "E": "english",
                "F": "score",
                "G": "remark"
            }

            roleNameMap: {
                "index": "序号",
                "name": "姓名",
                "chinese": "语文",
                "mathematics": "数学",
                "english": "英语",
                "score": "总分",
                "remark": "备注"
            }
            roleSizeMap: {
                "index": 50,
                "name": 100,
                "chinese": 100,
                "mathematics": 100,
                "english": 100,
                "score": 100,
                "remark": "auto"
            }
            miniSizeMap: {
                "index": 50,
                "name": 100,
                "chinese": 100,
                "mathematics": 100,
                "english": 100,
                "score": 100,
                "remark": 100

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
                resizable:false
            }
            JHTableColumn{
                id:columnC
                tagName:"C"
                resizable:false
            }
            JHTableColumn{
                id:columnD
                tagName:"D"
                resizable:false
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
            model:SMApi.studentModel

            delegate: JHTableRow{
                id:row
                width: headerD.width
                color: "white"
                height: 50

                JHTableCell {
                    id: cellA
                    tagName: columnA.tagName
                    width: columnA.width
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
                    width: columnB.width
                    visible: columnB.visible
                    text: model.data.name
                }
                JHTableCell {
                    id: cellC

                    tagName: columnC.tagName
                    width: columnC.width
                    visible: columnC.visible
                    text: model.data.chinese
                }
                JHTableCell {
                    id: cellD

                    tagName: columnD.tagName
                    width: columnD.width
                    visible: columnD.visible
                    text: model.data.mathematics
                }
                JHTableCell {
                    id: cellE

                    tagName: columnE.tagName
                    width: columnE.width
                    visible: columnE.visible
                    text:model.data.english
                }
                JHTableCell {
                    id: cellF

                    tagName: columnF.tagName
                    width: columnF.width
                    visible: columnF.visible
                    text: model.data.score
                }
                JHTableCell {
                    id: cellG

                    tagName: columnG.tagName
                    width: columnG.width
                    visible: columnG.visible

                    TextField{
                        id:beizhu
                        anchors.fill: parent
                        horizontalAlignment: TextInput.AlignHCenter
                        text: model.data.remark
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
                            cellGm.width = cellG.width

                            if (model.data.remark === text)
                                return

                            SMApi.studentModel.updataStudentInfo(index,headerD.roleMap[cellG.tagName],text)
                        }
                        onFocusChanged: {
                            if (focus == true){
                                if (dataListView.isSelectItem !== null){
                                    dataListView.isSelectItem.selectState = false
                                }

                                selectState = true
                                dataListView.isSelectItem = row
                            }
                        }
                    }
                    Rectangle{
                        id:cellGm
                        anchors.top: parent.top
                        anchors.left: parent.Left
                        anchors.bottom: parent.bottom
                        width: parent.width
                        color: "transparent"
                        MouseArea{
                            anchors.fill: parent
                            onDoubleClicked: {
                                beizhu.focus = true
                                cellGm.width = 1
                            }
                            onPressed: {
                                if (dataListView.isSelectItem !== null){
                                    dataListView.isSelectItem.selectState = false
                                }

                                selectState = true
                                dataListView.isSelectItem = row
                            }
                        }
                    }
                }
                onClicked: {
                    if (dataListView.isSelectItem !== null){
                        dataListView.isSelectItem.selectState = false
                    }

                    selectState = true
                    dataListView.isSelectItem = row
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

