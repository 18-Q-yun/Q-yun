import QtQuick 2.0

Rectangle {

    property int mainWindowX
    //用来存储主窗口x坐标
    property int mainWindowY
    //存储窗口y坐标
    property int xMouse
    //存储鼠标x坐标
    property int yMouse
    id: mainTitle //创建标题栏
    anchors.top: mainWindow.top //对标题栏定位
    anchors.left: mainWindow.left
    anchors.right: mainWindow.right
    height: 40 //设置标题栏高度
    width: mainWindow.width
    color: "lightblue" //设置标题栏背景颜色

    Image {
        id: appIcon
        width: 30
        height: 30
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        source: "./图片/Icon图片/yun_icon.png"
    }
    Text {
        id: appName
        anchors.left: appIcon.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        text: qsTr("Q-Yun盘")
        font.bold: true
    }
    //    Row {
    //        anchors.left: appName.right
    //        anchors.leftMargin: 40
    //        anchors.bottom: parent.bottom
    //        anchors.bottomMargin: 5
    //        spacing: 50
    //        Text {
    //            id: myNetLabel

    //            text: qsTr("我的网盘")
    //            font.bold: true
    //        }
    //        Text {
    //            id: transeferListLabel

    //            text: qsTr("传输列表")
    //            font.bold: true
    //        }
    //        Text {
    //            id: friendSharelabel

    //            text: qsTr("好友分享")
    //            font.bold: true
    //        }
    //        Text {
    //            id: importantlabel

    //            text: qsTr("功能宝箱")
    //            font.bold: true
    //        }
    //    }
    MouseArea {
        //为窗口添加鼠标事件
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        onPressed: {
            //接收鼠标按下事件
            xMouse = mouseX
            yMouse = mouseY
            mainWindowX = mainWindow.x
            mainWindowY = mainWindow.y
        }
        onPositionChanged: {
            //鼠标按下后改变位置
            mainWindow.x = mainWindowX + (mouseX - xMouse)
            mainWindow.y = mainWindowY + (mouseY - yMouse)
        }
    }

    TitleButton {
        id: closeTitleBar
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        normalPath: "./图片/TitleBar图片/close1.png"
        enterPath: "./图片/TitleBar图片/close2.png"
        pressPath: "./图片/TitleBar图片/close3.png"
        releasedPath: "./图片/TitleBar图片/close4.png"
        onButtonClick: {
            mainWindow.close()
        }
    }
    TitleButton {
        id: maxTitleBar
        anchors.right: closeTitleBar.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        normalPath: "./图片/TitleBar图片/max1.png"
        enterPath: "./图片/TitleBar图片/max2.png"
        pressPath: "./图片/TitleBar图片/max3.png"
        releasedPath: "./图片/TitleBar图片/max4.png"
        onButtonClick: {
            maxButtonClick()
        }
    }
    TitleButton {
        id: minTitleBar
        anchors.right: maxTitleBar.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        normalPath: "./图片/TitleBar图片/min1.png"
        enterPath: "./图片/TitleBar图片/min2.png"
        pressPath: "./图片/TitleBar图片/min3.png"
        releasedPath: "./图片/TitleBar图片/min4.png"
        onButtonClick: {
            mainWindow.showMinimized()
        }
    }
}
