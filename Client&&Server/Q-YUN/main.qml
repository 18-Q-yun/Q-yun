import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
import Client 1.0

ApplicationWindow {
    id: aw
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Client {
        id: client
    }
    FileDialog {

        id: fileDialog
        signal completeChoose
        title: "Please choose a file"
        selectMultiple: true //多选文件

        onAccepted: {
            console.log(fileDialog.fileUrls.length)
            completeChoose()
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    Rectangle {
        id: upload
        color: "red"
        width: 70
        height: 35

        x: download.x + download.width + 50
        y: download.y

        Text {
            text: "上传"
            anchors.centerIn: upload
        }

        MouseArea {
            anchors.fill: upload
            onClicked: {
                fileDialog.visible = true
            }
        }
        Connections {
            target: fileDialog
            onCompleteChoose: {
                for(var i = 0; i !== fileDialog.fileUrls.length; i++)
                    client.setResource(fileDialog.fileUrls[i])
                client.coutResource()
                client.setFlag(1)
                client.selectWay()
            }
        }
    }

    Rectangle {
        id: download
        color: "blue"
        width: 70
        height: 35
        x: (aw.width + download.width) / 2
        y: (aw.height - download.height) / 2

        Text {
            text: "下载"
            anchors.centerIn: download
        }

        MouseArea {
            anchors.fill: download
            onClicked: {
                //                client.setResource("/root/YUN/传输素材/爱的代价.mp3")
                client.setFlag(0)
                client.selectWay()
            }
        }
    }
}
