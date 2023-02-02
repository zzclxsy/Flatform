import QtQuick 2.0
import QtGraphicalEffects 1.12
import JHQmlControls 1.0
import QtQml 2.12
import JHFramework 1.0

Item {

    JHMessageClient{
        id:client
        filter: ["gg"]
        domainID: "Login"
    }

    Image {
        id: bk
        anchors.fill: parent
        smooth: true
        visible: false
        source: "qrc:/image/Image/login/splash.png"
    }

    Rectangle {
        id: mask
        anchors.fill: parent
        radius: 5
        visible: false
    }
    OpacityMask {
        anchors.fill: parent
        source: bk
        maskSource: mask
    }

    JHCreateClssDialog{
        id:createClass
        width: 500;
        height: 400
        onDialogFinished: {
            console.log(JSON.stringify(data))
            listmodel.append(data)
            noclaass.visible = false
            hasClass.visible = true
        }
    }

    Rectangle{
        id:conent
        anchors.centerIn: parent
        width: 400
        height:600

        Rectangle{
            id:hasClass
            anchors.fill: parent

            Rectangle {
                id: rectangle
                height: 200
                color: "#ffffff"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                Image{
                    width: implicitWidth/2
                    height: implicitHeight/2
                    anchors.top: parent.top
                    anchors.topMargin: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "qrc:/image/Image/login/xiaoyuan.svg"
                }

                Text {
                    height: 71
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.topMargin: 100
                    font.pixelSize: parent.width/10
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    lineHeight: 2.1
                    wrapMode: Text.WordWrap
                    anchors.rightMargin: 20
                    anchors.leftMargin: 20
                    text: qsTr("选择您的班级")
                }
            }

            ListView{
                anchors.fill: parent
                anchors.topMargin: 200
                clip:true
                model: ListModel{
                    id: listmodel
                }
                delegate:Rectangle{
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: parent.width/4*3
                    height: 50
                    radius: 5
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            parent.color = "#500099CC"
                        }
                        onExited: {
                            parent.color = "transparent"
                        }
                        onClicked: {
                            JHApp.AppData.getShareData("grade",model["grade"])
                            JHApp.AppData.getShareData("class",model["class"])
                            JHApp.AppData.addShareData("classID",model["classID"])
                            SMApi.studentModel.initialize()

                            var data = {}
                            data["loginState"] = "logged"
                            data["url"] = "qrc:/SMSystemUI.qml"
                            client.domainData = data
                        }
                    }

                    Text {
                        id: gradeText
                        anchors.left: parent.left
                        anchors.leftMargin: 50
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        width: parent.width/2-20
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        layer.smooth: true
                        font.wordSpacing: 0
                        font.family: "Microsoft Yahei"
                        font.pixelSize: 20
                        font.bold: true
                        text: model["grade"]
                    }
                    Text {
                        anchors.left: gradeText.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        width: parent.width/2
                        layer.smooth: true
                        font.wordSpacing: 0
                        font.family: "Microsoft Yahei"
                        font.pixelSize: 20
                        font.bold: true
                        text: model["class"] + " 班"
                    }
                }
            }

        }


        Rectangle{
            id:noclaass
            anchors.fill: parent
            Image{
                width: implicitWidth/2
                height: implicitHeight/2
                anchors.top: parent.top
                anchors.topMargin: 30
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:/image/Image/login/xiaoyuan.svg"
            }

            Text {
                id: text1
                text: qsTr("您似乎还没自己的班级,请点击下方加号进行创建")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: 50
                font.pixelSize: parent.width/20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                lineHeight: 2.1
                wrapMode: Text.WordWrap
                anchors.rightMargin: 20
                anchors.leftMargin: 20
                height: 301
            }

            Rectangle{
                anchors.top: text1.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom

                Rectangle{
                    id:addbtn
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    width: 100
                    height: 100

                    JHButton{
                        anchors.fill: addbtn
                        itemMargins:5
                        imageFillMode:Image.PreserveAspectFit
                        imageSource: "qrc:/image/Image/system/add.svg"
                        imageNormColor:"#CCCCCC"
                        imageHoverColor: "#8a8a8a"
                        imagePressColor: "#8a8a8a"
                        onButtonClicked: {
                            createClass.showPage()
                        }
                    }
                }
            }


        }

    }

    DropShadow {
        anchors.fill: conent
        horizontalOffset: 0
        verticalOffset: 0
        radius: 8
        samples: 17
        color: "#888888"
        source: conent
    }

    Component.onCompleted: {
        var userName = JHApp.AppData.getShareData("UserName")
        var totallCalss= SMApi.AccountManager.getUeserTotalClass(userName);
        if (totallCalss.length  == 0){
            noclaass.visible = true
            hasClass.visible = false
            return
        }else{
            noclaass.visible = false
            hasClass.visible = true
        }

        for (var i = 0; i < totallCalss.length;i++)
        {
            listmodel.append(totallCalss[i])
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
