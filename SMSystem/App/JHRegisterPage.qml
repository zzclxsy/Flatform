import QtQuick 2.12
import JHQmlControls 1.0
import QtQuick.Controls 1.4
JHDialog{
    id:dialog
    label:"注册账号"
    property string errorText
    signal dialigFinish()
    JHMessagePopup{
        id:popup
    }

    handle: Rectangle{
        anchors.fill: parent

        Column{
            width: 360
            height: 460
            anchors.top: parent.top
            anchors.topMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 0

            Image{
                width: implicitWidth/2
                height: implicitHeight/2
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:/image/Image/login/xiaoyuan.svg"
            }

            Item{
                width: parent.width
                height: 16
            }

            Text{
                width: parent.width -8
                height: 40
                text: "注册账号"
                font.family: "Microsoft Yahei"
                font.pixelSize: 26
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                color: "#234E97"
                fontSizeMode: Text.Fit
            }

            Item{
                width: parent.width
                height: 34
            }

            TextField{
                id: inputUsername
                width: 300
                height: 42
                anchors.horizontalCenter: parent.horizontalCenter
                placeholderText: "Username"
                focus: true
                validator: RegExpValidator { regExp: (/^[A-Za-z0-9]+$/) }
                font.family: "Microsoft Yahei"
            }

            Item{
                width: parent.width
                height: 28
            }

            TextField{
                id: inputPassword
                width: 300
                height: 42
                anchors.horizontalCenter: parent.horizontalCenter
                placeholderText: "Password"
                font.family: "Microsoft Yahei"
                validator: RegExpValidator { regExp: (/^[A-Za-z0-9]+$/) }
                Keys.onEnterPressed: {
                    register();
                }
                Keys.onReturnPressed: {
                    register();
                }
            }

            Item{
                width: parent.width
                height: 52

                Text{
                    anchors.centerIn: parent
                    color: "red"
                    text: dialog.errorText
                }
            }

            Rectangle{
                width: 300
                height: 42
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#1E90FF"
                radius: 5
                Text {
                    anchors.fill: parent
                    font.letterSpacing: 5
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    layer.smooth: true
                    font.wordSpacing: 0
                    font.family: "Microsoft Yahei"
                    font.pixelSize: 20
                    font.bold: true
                    color: "#ffffff"
                    text: qsTr("注册")
                }
                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        register();
                    }

                    onEntered: {
                        parent.color = "#0066CC"
                        cursorShape = Qt.PointingHandCursor
                    }
                    onExited: {
                        parent.color = "#1E90FF"
                        cursorShape = Qt.ArrowCursor
                    }

                    Keys.onEnterPressed: {
                        register();
                    }
                    Keys.onReturnPressed: {
                        register();
                    }
                }
            }
     }
    }

    function hideRegisterPage(){
        hide()
    }

    function register(){
        if (inputUsername.text === ""||  inputPassword.text == ""){
            popup.warnMessage("请设置账号或密码")
            return
        }

        var ret = SMApi.AccountManager.registerAccount(inputUsername.text, inputPassword.text)
        if (ret !== "succeed"){
            popup.errorMessage(ret)
        }else{
            popup.informMessage("注册成功",hideRegisterPage)
        }
    }
}

