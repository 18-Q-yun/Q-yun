import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: waringWindow
    x: waringWindowX
    y: waringWindowY
    width: 300
    height: 200
    property string waringTexts
    property int waringWindowX
    property int waringWindowY
    property int xMouse
    //存储鼠标x坐标
    property int yMouse
    border.color: "#F5F5DC"
    radius: 0.1

    Rectangle {
        id: topRec
        width: parent.width
        height: 30
        anchors.top: parent.top
        color: "#F5F5DC"
        Text {
            id: waringTitle
            anchors.top: topRec.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: parent.width / 2.2
            text: "警告"
            color: "blue"
        }
        MouseArea {
            //为窗口添加鼠标事件
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton //只处理鼠标左键
            onPressed: {
                //接收鼠标按下事件
                xMouse = mouseX
                yMouse = mouseY
                waringWindowX = mainWindow.x
                waringWindowY = mainWindow.y
            }
            onPositionChanged: {
                //鼠标按下后改变位置
                mainWindow.x = waringWindowX + (mouseX - xMouse)
                mainWindow.y = waringWindowY + (mouseY - yMouse)
            }
        }
    }

    Text {
        id: waringText
        anchors.top: topRec.bottom
        anchors.topMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 3
        text: waringTexts
    }
    Button {
        id: okButton
        width: 50
        height: 30
        anchors.top: waringText.bottom
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 2.2
        text: "确定"
        onClicked: {
            waringWindow.destroy()
        }
    }
}
