import QtQuick 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.12
import JHFramework 1.0
import JHQmlControls 1.0
import QtQml 2.12

Item {
    id: login0
    width: 800
    height: 470
    JHMessagePopup{
        id:messagepopup
    }

    JHRegisterPage{
        id:registerPage
        width: 800
        height: 520
    }
    JHMessagePopup{
        id:popup
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

    Rectangle{
        width: lp1.width+rp2.width
        height: rp2.height
        anchors.centerIn: parent
        color: "transparent"
        Image {
            id: lp1
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/image/Image/login/left.png"


            Text {
                id: verion
                anchors.left: parent.left
                anchors.leftMargin: 24
                anchors.top: parent.top
                anchors.topMargin: 390
                font.family: "Microsoft Yahei"
                font.pixelSize: 14
                font.bold: true
                color: "#ffffff"
                text:"Version: Rev0.0.5"
            }

        }

        Rectangle{
            id: rp2
            width: 380
            height: 480
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter

            Column{
                width: 360
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.horizontalCenter: rp2.horizontalCenter
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
                    width: rp2.width -20
                    height: 40
                    text: "智慧课堂"
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
                    selectByMouse: true;
                    placeholderText: "Username"
                    focus: true
                    font.family: "Microsoft Yahei"
                    validator: RegExpValidator { regExp: (/^[A-Za-z0-9]+$/) }
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
                    selectByMouse: true;
                    placeholderText: "Password"
                    echoMode: TextField.Password
                    font.family: "Microsoft Yahei"
                    validator: RegExpValidator { regExp: (/^[A-Za-z0-9]+$/) }
                    Keys.onEnterPressed: {
                        login();
                    }
                    Keys.onReturnPressed: {
                        login();
                    }
                }

                Item{
                    width: parent.width
                    height: 52

                    Text{
                        anchors.centerIn: parent
                        color: "red"
                        text: login0.errorText
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
                        text: qsTr("登录")
                    }
                    MouseArea{
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            login();
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

            Rectangle{
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                width: 80
                height: 30

                Text{
                    id:regText
                    anchors.fill: parent
                    anchors.bottomMargin: 5
                    anchors.rightMargin: 5
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignBottom
                    text: "注册账号"
                    color: "#80000000"
                }
                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        regText.color = "#000000"
                        cursorShape = Qt.PointingHandCursor
                    }
                    onExited: {
                        regText.color = "#80000000"
                        cursorShape = Qt.ArrowCursor
                    }
                    onClicked: {
                        registerPage.showPage()
                    }
                }
            }
        }

        DropShadow {
            anchors.fill: rp2
            horizontalOffset: 0
            verticalOffset: 0
            radius: 8
            samples: 17
            color: "#888888"
            source: rp2
        }
    }


    JHMessageClient{
        id:client
        domainID: "Login"
    }


    property string errorText: ""

    function login() {

        JHApp.AppData.addShareData("UserName",inputUsername.text)

        if (inputUsername.text === ""||  inputPassword.text == ""){
            popup.warnMessage("请输入账号或密码")
            return
        }

        var ret = SMApi.AccountManager.loginAccount(inputUsername.text, inputPassword.text)
        if (ret !== "succeed"){
            popup.errorMessage(ret)
        }else{
            var data = {}
            data["loginState"] = "logged"
            data["url"] = "qrc:/JHClassSelect.qml"
 //           data["url"] = "qrc:/SMSystemUI.qml"
            client.domainData = data
        }
    }

    function setUsername(username) {

    }

    Component.onCompleted: {

    }
}
