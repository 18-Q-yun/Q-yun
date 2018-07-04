import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import ".."

Rectangle {
    id: dirPage
    width: Screen.desktopAvailableWidth - (Screen.desktopAvailableWidth / 15 + 3)
    height: Screen.desktopAvailableWidth - 155
    property int dirLevelFlag: 1 //目录层次标志值
    property string currentDir: currentDirName.text
    signal dirClicked(var currentDirName)
    Column {
        id: twoRect
        anchors.top: parent.top
        anchors.topMargin: 50
        spacing: 50
        Rectangle {
            width: parent.width
            height: 1
            color: "#F5F5DC"
        }
        Rectangle {
            width: parent.width
            height: 1
            color: "#F5F5DC"
        }
    }
    Row {
        anchors.top: parent.top
        anchors.topMargin: twoRect.spacing + 15
        spacing: 15
        Image {
            id: backIcon
            width: 10
            height: 10
            source: if (dirPageStack.depth > 1) {
                        "../图片/Icon图片/back_icon2.png"
                    } else {
                        "../图片/Icon图片/back_icon1.png"
                    }

            MouseArea {
                anchors.fill: parent
                onClicked: {

                    if (dirPageStack.depth > 0) {
                        dirPageStack.pop()
                        console.log("the depth is" + dirPageStack.depth)
                    }
                }
            }
        }
        Image {
            id: frontIcon
            width: 10
            height: 10
            source: "../图片/Icon图片/back_icon1.png"
            mirror: true
        }
        Image {
            id: downIcon
            width: 10
            height: 10
            source: "../图片/Icon图片/down_icon.png"
        }
        Image {
            id: refreshIcon
            width: 12
            height: 12
            source: "../图片/Icon图片/refresh_icon.png"
        }
        Text {
            id: departText
            text: "|"
            color: "#7A8B8B"
        }
        Text {
            id: mypanText
            text: "我的网盘"
            MouseArea {
                anchors.fill: parent
                onClicked: {

                    mymodel.clear()
                    mymodel.levelDirName = "123firstDir"

                    mymodel.lastFileName = "/"
                    mymodel.readAllDir()

                    currentDirName.text = ""
                }
            }
        }
        Image {
            id: nextIcon
            width: 10
            height: 10
            source: "../图片/Icon图片/back_icon2.png"
            mirror: true
        }
        Text {
            id: currentDirName
            text: ""
            color: "black"
            MouseArea {
                anchors.fill: parent
            }
        }
    }
    TextField {
        id: searchInput
        anchors.top: parent.top
        anchors.topMargin: twoRect.spacing + 15
        anchors.right: parent.right
        width: 200
        focus: true
        placeholderText: "搜索我的网盘文件 "
    }
    Image {
        id: searchBar
        width: 20
        height: 20
        anchors.right: searchInput.right
        anchors.bottom: searchInput.bottom
        source: "../图片/Icon图片/search_icon.png"
    }

    GridView {
        id: dirGridView
        width: dirPage.width
        height: dirPage.height - 2 * twoRect.spacing
        anchors.top: twoRect.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        model: Dirmodel {
            id: mymodel
        }
        delegate: Column {
            id: dirDelegate
            property string currentFileName: fileText.text //保存当前文件夹名
            Image {
                id: name
                source: fileicon
                width: 30
                height: 30
                MouseArea {
                    anchors.fill: parent
                    onClicked: {

                    }

                    onDoubleClicked: {
                        dirLevelFlag++
                        dirDelegate.GridView.view.currentIndex = index
                        currentDirName.text = dirDelegate.GridView.view.currentItem.currentFileName
                        dirClicked(currentDirName.text)
                    }
                }
            }
            Text {
                id: fileText
                text: filename
                color: dirDelegate.GridView.isCurrentItem ? "blue" : "black"
            }
        }

        highlightFollowsCurrentItem: true
        focus: true
    }
    Component.onCompleted: {

        mymodel.levelDirName = mainWindow.level
        mymodel.lastFileName = mainWindow.last
        mymodel.readAllDir()
    }
}
