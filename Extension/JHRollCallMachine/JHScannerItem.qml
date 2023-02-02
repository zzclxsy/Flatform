import QtQuick 2.0
import QtQuick.Controls 2.5
import JHRollCallMachine 1.0
Item {

    function getScanPoint(){
        var result = scannerItem.scanResult()
        return result
    }

    function startScan(){
        scannerItem.start()
    }

    function stopScan(){
        scannerItem.stop()
    }

    Rectangle{
        anchors.fill: parent

        ScannerItem{
            id:scannerItem
            anchors.fill: parent
        }
    }
}
