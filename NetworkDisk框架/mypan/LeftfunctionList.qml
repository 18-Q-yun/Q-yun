import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Window 2.2

Rectangle {
    id: leftScene
    signal allFileDisplay
    signal pictureDisplay
    signal videoDisplay
    signal documentDisplay
    signal musicDisplay
    signal otherDisplay

    width: Screen.desktopAvailableWidth / 10
    height: (Screen.desktopAvailableHeight * 4) / 5

    Rectangle {
        id: allFile
        width: parent.width
        height: parent.height / 20
        Text {
            id: textAllFile
            anchors.centerIn: parent
            text: qsTr("全部文件")
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                allFile.color = "#F5FFFA"
                allFile.opacity = 0.4
                textAllFile.color = "#00BBFF"
            }
            onExited: {
                allFile.opacity = 1
                textAllFile.color = "black"
                allFile.color = "white"
            }
            onClicked: {
                textAllFile.color = "#00BBFF"
                allFile.color = "#F5FFFA"
                allFile.opacity = 1
                allFileDisplay()
                console.log("all file")
            }
        }
    }

    Rectangle {
        id: picture
        width: parent.width
        height: parent.height / 20
        anchors.top: allFile.bottom
        color: "white"
        Text {
            id: textPic
            anchors.centerIn: parent
            text: qsTr("图片")
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                picture.color = "#F5FFFA"
                picture.opacity = 0.4
                textPic.color = "#00BBFF"
            }
            onExited: {
                picture.opacity = 1
                textPic.color = "black"
                picture.color = "white"
            }
            onClicked: {
                picture.opacity = 1
                textPic.color = "#00BBFF"
                picture.color = "#F5FFFA"
                pictureDisplay()
                console.log("picture")
            }
        }
    }

    Rectangle {
        id: video
        width: parent.width
        height: parent.height / 20
        anchors.top: picture.bottom
        color: "white"
        Text {
            id: textVid
            anchors.centerIn: parent
            text: qsTr("视频")
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                video.color = "#F5FFFA"
                video.opacity = 0.4
                textVid.color = "#00BBFF"
            }
            onExited: {
                video.opacity = 1
                textVid.color = "black"
                video.color = "white"
            }
            onClicked: {
                video.opacity = 1
                textVid.color = "#00BBFF"
                video.color = "#F5FFFA"
                videoDisplay()
                console.log("video")
            }
        }
    }

    Rectangle {
        id: document
        width: parent.width
        height: parent.height / 20
        anchors.top: video.bottom
        Text {
            id: textDoc
            anchors.centerIn: parent
            text: qsTr("文件")
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                document.color = "#F5FFFA"
                document.opacity = 0.4
                textDoc.color = "#00BBFF"
            }
            onExited: {
                document.opacity = 1
                textDoc.color = "black"
                document.color = "white"
            }
            onClicked: {
                document.opacity = 1
                textDoc.color = "#00BBFF"
                document.color = "#F5FFFA"
                documentDisplay()
                console.log("document")
            }
        }
    }

    Rectangle {
        id: music
        width: parent.width
        height: parent.height / 20
        anchors.top: document.bottom
        Text {
            id: textMusic
            anchors.centerIn: parent
            text: qsTr("音乐")
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                music.color = "#F5FFFA"
                music.opacity = 0.4
                textMusic.color = "#00BBFF"
            }
            onExited: {
                music.opacity = 1
                textMusic.color = "black"
                music.color = "white"
            }
            onClicked: {
                music.opacity = 1
                textMusic.color = "#00BBFF"
                music.color = "#F5FFFA"
                musicDisplay()
                console.log("music")
            }
        }
    }

    Rectangle {
        id: other
        width: parent.width
        height: parent.height / 20
        anchors.top: music.bottom
        color: "white"
        Text {
            id: textOth
            anchors.centerIn: parent
            text: qsTr("其它")
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                other.color = "#F5FFFA"
                other.opacity = 0.4
                textOth.color = "#00BBFF"
            }
            onExited: {
                other.opacity = 1
                textOth.color = "black"
                other.color = "white"
            }
            onClicked: {
                other.opacity = 1
                textOth.color = "#00BBFF"
                other.color = "#F5FFFA"
                otherDisplay()
                console.log("other")
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
