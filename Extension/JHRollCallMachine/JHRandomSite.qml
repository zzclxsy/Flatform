import QtQuick 2.0
import QtQuick.Controls 2.5
import JHRollCallMachine 1.0
Item {
    id: item1

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
            text: "随机点名"
        }
    }

    Slider {
        id: slider
        x: 45
        y: 442
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 20
        anchors.leftMargin: 50
        value: 2
        from :0
        to:4

        onMoved:{
            if (value > 1.75 && value < 2.25){
                value = 2
            }
        }

        background: Rectangle {
            x: slider.leftPadding
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: 200
            implicitHeight:8
            width: slider.availableWidth
            height:implicitHeight
            radius: 2
            color: "#bdbebf"


            Rectangle {
                width: slider.visualPosition * parent.width
                height: parent.height
                color: "#3399FF"
                radius: 2
            }
            Rectangle{
                anchors.centerIn: parent
                width: parent.implicitHeight - 2
                height: parent.implicitHeight - 2
                radius:(parent.implicitHeight - 2)/2
                color: "#333333"
            }
        }

        handle: Rectangle {
            x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
            y: slider.topPadding + slider.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 13
            color: slider.pressed ? "#999999" : "#CCCCCC"
            border.color: "#969696"
        }
    }

    JHRollPage{
        id:rollpage
        width:parent.width/4
        anchors.top: tb1.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter

        onButtonClicked: {
            var sliderPos = slider.position;
            var lenght = 3.0;
            var cut1 = lenght/3.0,cut2 = lenght/3.0 * 2.0;
            //----1--2--
            if (sliderPos > 0.5){
                var space = sliderPos - 0.5
                cut1 = cut1 + (lenght/3.0 * 2.0)*(space / 0.5)
                cut2 = cut1 + (lenght - cut1)/2.0
            }else  if (sliderPos < 0.5){
                space = 0.5 - sliderPos
                cut2 = cut2 - (lenght/3.0 * 2.0)*(space / 0.5)
                cut1 =  cut2/2.0
            }

            var rand = Math.random()*3
            if (rand <= cut1){
                studentName = "张三"
            }else if (rand > cut1 && rand < cut2){
                studentName = "李四不想"
            }else if (rand >= cut2){
                studentName = "不差钱"
            }
        }
    }

    Text {
        id: text1
        x: 45
        y: 411
        anchors.bottom: slider.top
        anchors.bottomMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 23
        layer.smooth: true
        font.wordSpacing: 0
        font.family: "Microsoft Yahei"
        font.pixelSize: 25
        text: qsTr("权重:")
    }

    Text {
        id: text2

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 25
        anchors.right: slider.left

        layer.smooth: true
        font.wordSpacing: 0
        font.family: "Microsoft Yahei"
        font.pixelSize: 15
        text: "差"
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.left: slider.right
        anchors.leftMargin: 10

        layer.smooth: true
        font.wordSpacing: 0
        font.family: "Microsoft Yahei"
        font.pixelSize: 15
        text: "好"
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
