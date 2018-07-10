import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.0
import ".."
Rectangle {
    id: cheifScene
    LeftfunctionList {
        id: leftScene
        //        onAllFileDisplay: {
        //            if (rStackView.depth > 1)
        //                rStackView.clear()
        //            rStackView.push(page)
        //        }
        //        onPictureDisplay: {
        //            if (rStackView.depth > 1)
        //                rStackView.clear()
        //            rStackView.push(pic)
        //        }
        //        onVideoDisplay: {
        //            if (rStackView.depth > 1)
        //                rStackView.clear()
        //            rStackView.push(vid)
        //        }
        //        onDocumentDisplay: {
        //            if (rStackView.depth > 1)
        //                rStackView.clear()
        //            rStackView.push(doc)
        //        }
        //        onMusicDisplay: {
        //            if (rStackView.depth > 1)
        //                rStackView.clear()
        //            rStackView.push(mus)
        //        }

        //        onOtherDisplay: {
        //            if (rStackView.depth > 1)
        //                rStackView.clear()
        //            rStackView.push(oth)
        //        }
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
                        fileDialog.visible = true
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
                        opacity: if(mainWindow.downloadResourceFlag==false){
                                     0.3
                                 }else{
                                     1
                                 }

                    }
                    Text {
                        id: downloadText
                        text: qsTr("下载")
                        opacity: if(mainWindow.downloadResourceFlag==false){
                                     0.3
                                 }else{
                                     1
                                 }
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    enabled: mainWindow.downloadResourceFlag
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
                        mainWindow.downloadResourceFlag=false
                        client.setDownloadResource(mainWindow.downloadResourceName)
                        client.downloadRequest(request.downloadResource(mainWindow.userName))
                        client.downloadResource()
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
                        pageLoader.source="../Warning.qml"
                        //mainWindow.newFolderFlag=true
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
                    onEntered: {

                        backIcon.opacity = 0.4

                    }
                    onExited: {
                        backIcon.opacity = 1
                    }
                    onClicked: {

                        if ( rStackView.depth > 0) {
                            rStackView.pop()
                            if(mainWindow.level!=1){
                                mainWindow.level--
                            }
                            currentDirNameText.text= mainWindow.currentDirNameVector[mainWindow.level]//改变当前目录，从数组中获得

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
                MouseArea {
                    anchors.fill: parent
                    onEntered: {
                        frontIcon.color = "#F5FFFA"
                        frontIcon.opacity = 0.4

                    }
                    onExited: {
                        frontIcon.opacity = 1

                        frontIcon.color = "white"
                    }
                    onClicked: {

                    }
                }
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
                id: currentDirNameText
                text:""
                color: "black"
                //                MouseArea {
                //                    anchors.fill: parent
                //                    onClicked: {
                //                    console.log( )
                //                    }
                //                }
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
        id:stackRec
        width: rigthScene.width
        height: rigthScene.height - 100
        anchors.top: rigthScene.top
        anchors.topMargin: 120
        anchors.left: rigthScene.left
        anchors.leftMargin: 20
        StackView {
            id: rStackView
            delegate: StackViewDelegate {
                function transitionFinished(properties)
                {
                    properties.exitItem.opacity = 1
                }

                pushTransition: StackViewTransition {
                    PropertyAnimation {
                        target: enterItem
                        property: "opacity"
                        from: 0
                        to: 1
                        duration: 50
                    }
                    PropertyAnimation {
                        target: exitItem
                        property: "opacity"
                        from: 1
                        to: 0
                        duration:50
                    }
                }
            }

            anchors.fill: parent

            initialItem: Dir{

            }
        }
    }
    Connections {
        target:rStackView.currentItem
        onDirClick: {

            currentDirNameText.text= mainWindow.currentDirNameVector[mainWindow.level]
            mainWindow.last = currentDirNameText.text
            rStackView.push(page)

        }
    }
    Connections{
        target: rStackView.currentItem                     //该信号是与stackView中当前项有关的，与其他页面无关
        onNewFolderGrid:{                                         //该信号处理器改变newFolderFlag的值
            mainWindow.newFolderFlag=true
        }
    }



    FileDialog {//上传文件的选择本地文件框
        id: fileDialog
        signal completeChoose
        title: "请选择需要上传的文件！"
        selectMultiple: true //多选文件

        onAccepted: {
            console.log(fileDialog.fileUrls.length)
            completeChoose()
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    Connections {
        target: fileDialog
        onCompleteChoose: {
            for(var i = 0; i !== fileDialog.fileUrls.length; i++)
                client.setUploadResource(fileDialog.fileUrls[i])
            if(mainWindow.level === 1) {
                client.uploadRequest(request.uploadResource(mainWindow.userName, mainWindow.level, "/", client.getResourcesName(fileDialog.fileUrls)))
                client.uploadResource()
            } else {
                client.uploadRequest(request.uploadResource(mainWindow.userName, mainWindow.level, mainWindow.last, client.getResourcesName(fileDialog.fileUrls)))
                client.uploadResource()
            }
        }
    }
    Component {
        id: page
        Dir{
        }
    }
    //    Component {
    //        id: pic
    //        Rectangle {
    //        }
    //    }
    //    Component {
    //        id: vid
    //        Rectangle {
    //        }
    //    }
    //    Component {
    //        id: doc
    //        Rectangle {
    //        }
    //    }
    //    Component {
    //        id: mus
    //        Rectangle {
    //        }
    //    }
    //    Component {
    //        id: oth
    //        Rectangle {
    //        }
    //    }
}
