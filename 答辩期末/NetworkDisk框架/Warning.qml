import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
Item{
       id:warning
    Rectangle {
        id: warningWindow
        x:( mainWindow.width-300) / 2
        y:( mainWindow.height-200) /2
        width: 300
        height: 200
        property string waringTexts
        property int waringWindowX
        property int waringWindowY
        property int xMouse
        //存储鼠标x坐标
        property int yMouse

        border.color:"#ADD8E6"
        border.width: 5
        radius: 0.1

        Rectangle {
            id: topRec
            width: parent.width
            height: 30
            anchors.top: parent.top
            color: "#ADD8E6"
            Text {
                id: warningTitle
                anchors.top: topRec.top
                anchors.topMargin: 10
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 2.2
                text: "提示"

            }
            MouseArea {
                //为窗口添加鼠标事件
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton //只处理鼠标左键
                onPressed: {
                    //接收鼠标按下事件
                    xMouse = mouseX
                    yMouse = mouseY
                    warningWindowX = mainWindow.x
                    warningWindowY = mainWindow.y
                }
                onPositionChanged: {
                    //鼠标按下后改变位置
                    mainWindow.x = warningWindowX + (mouseX - xMouse)
                    mainWindow.y = warningWindowY + (mouseY - yMouse)
                }
            }
        }

        TextField {
            id: warningText
            anchors.top: topRec.bottom
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: parent.width / 5
            width: 200
            height: 30
            focus: true
            placeholderText: "请输入文件夹名称"
        }
        Button{
            id:cancelButton
            width: 50
            height: 30
            anchors.left: parent.left
            anchors.leftMargin: 60
            anchors.top:warningText.bottom
             anchors.topMargin: 30
             text:"取消"
             onClicked: {
                 pageLoader.source=""
             }
        }

        Button {
            id: okButton
            width: 50
            height: 30
            anchors.top: warningText.bottom
            anchors.topMargin: 30
            anchors.left: cancelButton.right
            anchors.leftMargin: 100
            text: "确定"
            onClicked: {
                pageLoader.source=""
                if(mainWindow.level === 1) {
                    client.request(request.addFolder(mainWindow.userName, mainWindow.level, "/" , warningText.text))
                    client.addFolder();
                          mainWindow.newFolderName=warningText.text

                    mainWindow.newFolder()

                    console.log(mainWindow.newFolderName)
                }else {
                 client.request(request.addFolder(mainWindow.userName, mainWindow.level, mainWindow.currentDirNameVector[mainWindow.level], warningText.text))
                  client.addFolder();
                    mainWindow.newFolderName=warningText.text
                    mainWindow.newFolder()

                }
            }
        }
    }
}
