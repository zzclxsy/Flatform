import QtQuick 2.0
import QtQuick.Controls 2.5
import JHRollCallMachine 1.0

Item {
    id: item0
    visible: true

    property point scanPos:Qt.point(0,0)
    property bool startCanPaint: false
    property string studentName
    signal buttonClicked()
    Rectangle {
        id:recttop
        anchors.fill: parent

        Rectangle{
            id:rect2
            height: parent.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50

            JHScannerItem{
                id:trg
                anchors.fill: parent
            }

            Rectangle {
                id: button
                width: 100
                height: 50
                radius:10
                anchors.centerIn: parent
                Text {
                    id: buttonText
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Microsoft Yahei"
                    font.pixelSize: 20
                    font.bold: true
                    text: qsTr("开始点名")
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if (buttonText.text == "开始点名"){
                            buttonClicked()
                            trg.startScan()
                            buttonText.text = "停止点名"
                            startCanPaint = false
                            canvas.requestPaint()

                        }else{
                            trg.stopScan()
                            buttonText.text = "开始点名"
                            var tmp = trg.getScanPoint()
                            scanPos = Qt.point(tmp.x, tmp.y + rect2.y)
                            startCanPaint = true
                            canvas.requestPaint()
                        }
                    }
                }
            }

        }
        Canvas{
            id:canvas
            parent: recttop
            anchors.fill: parent
            onPaint: {
                var ctx = getContext("2d")
                ctx.clearRect(0,0,parent.width,parent.height)
                 if (startCanPaint)
                 {
                     var gradient=ctx.createRadialGradient(scanPos.x,scanPos.y,0,scanPos.x,scanPos.y,200)
                     gradient.addColorStop(0.0, Qt.rgba(0,178,142,0.1))
                     gradient.addColorStop(0.4, Qt.rgba(0,178,142,0.3))
                     gradient.addColorStop(0.8, Qt.rgba(0,178,142,0.3))
                     gradient.addColorStop(1.0, Qt.rgba(0,178,142,0.1))
                     ctx.lineWidth = 1

                     ctx.beginPath(parent.width/2 - parent.width/3,150)
                     ctx.fillStyle = "#000000";
                     var lenght = (parent.width/3 * 2 - 60)/studentName.length
                     var fontsize =parseInt(lenght) + "px sans-serif"
                     ctx.font = fontsize;

                     ctx.fillText(studentName,
                                  parent.width/2 - lenght*studentName.length/2,
                                  150+ lenght/3)
                     ctx.globalCompositeOperation ="destination-over"
                     ctx.ellipse(parent.width/2 - parent.width/3,
                                 150 - parent.width/5,
                                 parent.width/3*2,
                                 parent.width/5*2)

                     ctx.fillStyle = "#000099CC"
                     ctx.fill()


                     ctx.strokeStyle = "#500099CC";
                     ctx.stroke()

                     ctx.fillStyle = Qt.rgba(0,178,142,0.1);


                     ctx.moveTo(scanPos.x - 10,scanPos.y)

                     ctx.lineTo(parent.width/2 - parent.width/3,150)
                     ctx.lineTo(parent.width/2 + parent.width/3,150)
                     ctx.lineTo(scanPos.x +  10,scanPos.y)
                     ctx.lineTo(scanPos.x -  10,scanPos.y)

                     ctx.fill()

                     ctx.strokeStyle = "transparent";
                     ctx.stroke()

                 }else{
                     ctx.clearRect(0,0,parent.width,parent.height)
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
