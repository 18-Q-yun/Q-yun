import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Window 2.2

Rectangle {
    id: leftScene
    signal allFileDisplay

    width: Screen.desktopAvailableWidth / 15
    height: (Screen.desktopAvailableHeight * 4) / 5

    //    color: "lightblue"
    Rectangle {
        id: allFile
        width: parent.width
        height: parent.height / 16
        //        color: "white"
        Text {
            id: textAllFile
            anchors.centerIn: parent
            text: qsTr("全部文件")
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                allFile.color = "#F5F5F5"
                textAllFile.color = "#0044BB"
            }
            onExited: {
                textAllFile.color = "black"
                allFile.color = "white"
            }
            onClicked: {
                textAllFile.color = "#0044BB"
                allFile.color = "#77DDFF"
                allFileDisplay()
            }
        }
    }

    Rectangle {
        id: picture
        width: parent.width
        height: parent.height / 16
        anchors.top: allFile.bottom
        color: "white"
        Text {
            id: textPic
            anchors.fill: parent
            text: qsTr("图片")
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                picture.color = "#F5F5F5"
                textPic.color = "#0044BB"
            }
            onExited: {
                textPic.color = "black"
                picture.color = "white"
            }
            onClicked: {
                textPic.color = "#0044BB"
                picture.color = "#77DDFF"
                allFileDisplay()
            }
        }
    }

    Rectangle {
        id: linear
        width: 2
        height: parent.height
        color: "#F5F5DC"
        anchors.left: allFile.right
    }
}
