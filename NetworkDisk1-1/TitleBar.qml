import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {

    id: mainTitle //创建标题栏
    z: 0
    property int mainWindowX
    property int mainWindowY
    property int xMouse
    property int yMouse
    property int currentActivity: 1

    signal mypanstart
    signal transmitstart
    signal sharestart
    anchors.top: mainWindow.top //对标题栏定位
    anchors.left: mainWindow.left
    anchors.right: mainWindow.right
    width: mainWindow.width
    height: 50

    color: "#F5F5F5" //设置标题栏背景颜色

    Image {
        id: appIcon
        width: 30
        height: 30
        anchors.left: parent.left

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        source: "./图片/yun_icon.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {

            }
        }
    }

    Text {
        id: appName
        anchors.left: appIcon.right
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr("Q-Yun盘")
        font.bold: true
    }

    Rectangle {
        id: mypan
        z: 1
        anchors.left: appName.right
        anchors.leftMargin: 80
        anchors.bottom: parent.bottom
        width: mypantext.width
        height: 30
        color: "#F5F5F5"
        Text {
            id: mypantext
            text: qsTr("我的网盘")
            anchors.centerIn: parent
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: mypantext.color = "#00BBFF"
                onExited: mypantext.color = "black"
                onClicked: {
                    mypantext.color = "#00BBFF"
                    mypanstart()
                    mypanBar.visible = true
                }
            }

            Rectangle {
                id: mypanBar
                width: mypantext.width
                height: 2
                anchors.left: mypantext.left
                anchors.top: mypantext.top
                anchors.topMargin: 20
                visible: false
                color: "#00BBFF"
            }
        }
    }

    Rectangle {
        id: pathList
        z: 1
        anchors.left: mypan.right
        anchors.leftMargin: 50
        anchors.bottom: parent.bottom
        color: "#F5F5F5"
        width: pathListText.width
        height: 30
        Text {
            id: pathListText
            text: qsTr("传输列表")
            anchors.centerIn: parent

            Rectangle {
                id: pathBar
                width: pathListText.width
                height: 2
                anchors.left: pathListText.left
                anchors.top: pathListText.top
                anchors.topMargin: 20
                visible: false
                color: "#00BBFF"
            }
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: pathListText.color = "#00BBFF"
            onExited: {
                pathBar.visible = false
                pathListText.color = "black"
            }
            onClicked: {
                transmitstart()
                pathBar.visible = true
            }
        }
    }

    Text {
        id: shareWithFriend
        z: 1
        text: qsTr("好友分享")
        anchors.left: pathList.right
        anchors.leftMargin: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: shareWithFriend.color = "#00BBFF"
            onExited: {

                shareWithFriend.color = "black"
            }
            onClicked: {
                console.log("share222")
                sharestart()
            }
        }
    }

    Text {
        id: functionBox
        z: 1
        text: qsTr("功能宝箱")
        anchors.left: shareWithFriend.right
        anchors.leftMargin: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: functionBox.color = "#00BBFF"
            onExited: functionBox.color = "black"
        }
    }

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
        normalPath: "./图片/close1.png"
        enterPath: "./图片/close2.png"
        pressPath: "./图片/close3.png"
        releasedPath: "./图片/close4.png"
        onButtonClick: {
            mainWindow.close()
        }
    }
    TitleButton {
        id: maxTitleBar
        anchors.right: closeTitleBar.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        normalPath: "./图片/max1.png"
        enterPath: "./图片/max2.png"
        pressPath: "./图片/max3.png"
        releasedPath: "./图片/max4.png"
        onButtonClick: {
            maxButtonClick()
        }
    }
    TitleButton {
        id: minTitleBar
        anchors.right: maxTitleBar.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        normalPath: "./图片/min1.png"
        enterPath: "./图片/min2.png"
        pressPath: "./图片/min3.png"
        releasedPath: "./图片/min4.png"
        onButtonClick: {
            mainWindow.showMinimized()
        }
    }
}
