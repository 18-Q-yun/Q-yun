import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Window 2.2

Rectangle {
    id: cheifScene
    LeftfunctionList {
        id: leftScene
        onAllFileDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(allfile)
        }
        onPictureDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(pic)
        }
        onVideoDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(vid)
        }
        onDocumentDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(doc)
        }
        onMusicDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(mus)
        }

        onOtherDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(oth)
        }
    }

    Rectangle {
        id: rigthScene
        anchors.left: leftScene.right
        anchors.leftMargin: 10
        anchors.bottom: leftScene.bottom
        width: 900 - Screen.desktopAvailableWidth / 15
        height: (Screen.desktopAvailableHeight * 4) / 5
        Column {
            id: twoRect
            anchors.top: parent.top
            anchors.topMargin: 50
            spacing: 50
            Rectangle {
                width: mainWindow.width - leftScene.width
                height: 1
                color: "#D3D3D3"
            }
            Rectangle {
                width: mainWindow.width - leftScene.width
                height: 1
                color: "#D3D3D3"
            }
        }
        Row {
            anchors.top: parent.top
            anchors.topMargin: 10
            spacing: 40
            Rectangle {
                id: uploadRec
                color: "white"
                width: 50
                height: 30
                Row {
                    spacing: 10
                    Image {
                        id: uploadIcon
                        source: "../图片/Icon图片/upload_icon.png"
                        width: 15
                        height: 15
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }
                    Text {
                        id: uploadText
                        text: qsTr("上传")
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        uploadRec.color = "#F5FFFA"
                        uploadRec.opacity = 0.4
                        uploadText.color = "#00BBFF"
                    }
                    onExited: {
                        uploadRec.opacity = 1
                        uploadText.color = "black"
                        uploadRec.color = "white"
                    }
                    onClicked: {

                    }
                }
            }
            Rectangle {
                id: downloadRec
                color: "white"
                width: 70
                height: 30
                Row {
                    spacing: 10
                    Image {
                        id: downloadIcon
                        source: "../图片/Icon图片/down_icon.png"
                        width: 15
                        height: 15
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }
                    Text {
                        id: downloadText
                        text: qsTr("下载")
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        downloadRec.color = "#F5FFFA"
                        downloadRec.opacity = 0.4
                        downloadText.color = "#00BBFF"
                    }
                    onExited: {
                        downloadRec.opacity = 1
                        downloadText.color = "black"
                        downloadRec.color = "white"
                    }
                    onClicked: {

                    }
                }
            }
            Rectangle {
                id: shareRec
                color: "white"
                width: 50
                height: 30
                Row {
                    spacing: 10
                    Image {
                        id: shareIcon
                        source: "../图片/Icon图片/share_icon.png"
                        width: 15
                        height: 15
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }
                    Text {
                        id: shareText
                        text: qsTr("分享")
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        shareRec.color = "#F5FFFA"
                        shareRec.opacity = 0.4
                        shareText.color = "#00BBFF"
                    }
                    onExited: {
                        shareRec.opacity = 1
                        shareText.color = "black"
                        shareRec.color = "white"
                    }
                    onClicked: {

                    }
                }
            }
            Rectangle {
                id: deleteRec
                color: "white"
                width: 50
                height: 30
                Row {
                    spacing: 10
                    Image {
                        id: deleteIcon
                        source: "../图片/Icon图片/delete_icon.png"
                        width: 15
                        height: 15
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }
                    Text {
                        id: deleteText
                        text: qsTr("删除")
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        deleteRec.color = "#F5FFFA"
                        deleteRec.opacity = 0.4
                        deleteText.color = "#00BBFF"
                    }
                    onExited: {
                        deleteRec.opacity = 1
                        deleteText.color = "black"
                        deleteRec.color = "white"
                    }
                    onClicked: {

                    }
                }
            }
            Rectangle {
                id: newfolderRec
                color: "white"
                width: 80
                height: 30
                Row {
                    spacing: 10
                    Image {
                        id: newFolderIcon
                        source: "../图片/Icon图片/newfolder_icon.png"
                        width: 15
                        height: 15
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }
                    Text {
                        id: newFolderText
                        text: qsTr("新建文件夹")
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        newfolderRec.color = "#F5FFFA"
                        newfolderRec.opacity = 0.4
                        newFolderText.color = "#00BBFF"
                    }
                    onExited: {
                        newfolderRec.opacity = 1
                        newFolderText.color = "black"
                        newfolderRec.color = "white"
                    }
                    onClicked: {

                    }
                }
            }
            Rectangle {
                id: moreRec
                color: "white"
                width: 50
                height: 30
                Row {
                    spacing: 10
                    Image {
                        id: moreIcon
                        source: "../图片/Icon图片/more_icon.png"
                        width: 15
                        height: 15
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {

                            }
                        }
                    }
                    Text {
                        id: moreText
                        text: qsTr("更多")
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        moreRec.color = "#F5FFFA"
                        moreRec.opacity = 0.4
                        moreText.color = "#00BBFF"
                    }
                    onExited: {
                        moreRec.opacity = 1
                        moreText.color = "black"
                        moreRec.color = "white"
                    }
                    onClicked: {

                    }
                }
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
                source: "../图片/Icon图片/back_icon2.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {


                        //                        if (dirPageStack.depth > 0) {
                        //                            dirPageStack.pop()
                        //                            console.log("the depth is" + dirPageStack.depth)
                        //                        }
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
            anchors.topMargin: 60

            anchors.right: twoRect.right
            anchors.rightMargin: 20
            width: 200
            height: 30
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
    }
    Rectangle {
        width: rigthScene.width
        height: rigthScene.height - 100
        anchors.top: rigthScene.top
        anchors.topMargin: 120
        anchors.left: rigthScene.left
        anchors.leftMargin: 20
        StackView {
            id: rStackView
            anchors.fill: parent
        }
    }

    Component {
        id: allfile
        Rectangle {
        }
    }
    Component {
        id: pic
        Rectangle {
        }
    }
    Component {
        id: vid
        Rectangle {
        }
    }
    Component {
        id: doc
        Rectangle {
        }
    }
    Component {
        id: mus
        Rectangle {
        }
    }
    Component {
        id: oth
        Rectangle {
        }
    }
}
