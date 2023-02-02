import QtQuick 2.0
import JHQmlControls 1.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12
import JHFramework 1.0
JHDialog {
    label:"班级创建"
    signal dialogFinished(var data)
    JHMessagePopup{
        id:popup
    }
    handle: Rectangle{
        anchors.fill: parent
        SwipeView {
           id: swipeView
           anchors.fill: parent
           anchors.bottomMargin: 60
            Rectangle{
                id: rectangle

                Text {
                    id: text1
                    height: 50
                    text: qsTr("请选择年级和班级")
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.italic: false
                    minimumPointSize: 20
                    minimumPixelSize: 31
                    anchors.leftMargin: 5
                    anchors.rightMargin: 5
                    anchors.topMargin: 5
                }

                Text {
                    id: text2
                    width: 71
                    height: 40
                    text: qsTr("年级")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.leftMargin: 50
                }


                ComboBox {
                    id: comboBox
                    y: 192
                    width: 100
                    height: 40
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: text2.right
                    anchors.leftMargin: 10
                    model: ["一年级","二年级","三年级","四年级","五年级","六年级","初一","初二","初三","高一","高二","高三"]
                }



                Text {
                    id: text3
                    width: 71
                    height: 40
                    text: qsTr("班级")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: classText.left
                    font.pixelSize: 22
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.rightMargin: 10
                }

                TextField {
                    id: classText
                    width: 73
                    height: 40
                    text: qsTr("1")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 80
                    validator: RegExpValidator { regExp: (/^[0-9]+$/) }
                }




            }
        }

        Rectangle{
            id:nextBtn
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            width: 150
            radius: 5
            height: 50
            color: "#1E90FF"
            Text {
                text: qsTr("完成")
                font.wordSpacing: 0
                font.family: "Microsoft Yahei"
                font.pixelSize: 20
                font.bold: true
                color: "#ffffff"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    console.log(JHApp.AppData.getShareData("UserName"),comboBox.currentText, classText.text)
                    var ret = SMApi.AccountManager.addNewClassToUser(JHApp.AppData.getShareData("UserName") ,comboBox.currentText, classText.text)
                    if (ret !== "succeed"){
                        popup.errorMessage(ret)
                    }else{
                        var data ={}
                        data["class"] = classText.text
                        data["grade"] = comboBox.currentText
                        dialogFinished(data)
                        hide()
                    }
                }

                onEntered: {
                    parent.color = "#0066CC"
                    cursorShape = Qt.PointingHandCursor
                }
                onExited: {
                    parent.color = "#1E90FF"
                    cursorShape = Qt.ArrowCursor
                }
            }
        }
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
