import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: userLogin
    width: mainWindow.width
    height: mainWindow.width - 40
    property real textSize: 13
    //设置字体的大小
    TitleBar {
        id: titleBar
        anchors.top: parent.top
    }

    Text {
        id: loginTitle
        anchors.top: titleBar.bottom
        anchors.topMargin: 20
        anchors.left: titleBar.left
        anchors.leftMargin: 300
        text: qsTr("登录")
        font.pointSize: 60
        font.bold: true
    }
    Column {
        anchors.top: loginTitle.bottom
        anchors.bottomMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 200
        spacing: 30
        //用户名称
        Row {
            spacing: 30
            Text {
                text: "用户名称:"
                font.pointSize: textSize
            }
            TextField {
                id: userNameInput

                focus: true
                font.pointSize: textSize
            }
        }

        Row {
            spacing: 30
            Text {
                text: "用户密码:"
                font.pointSize: textSize
            }
            TextField {
                id: userPasswordInput
                echoMode: TextInput.Password
                focus: true
                font.pointSize: textSize
            }
        }
        Row {

            spacing: 150

            Button {
                id: cancelButton
                width: 50
                height: 30
                text: "注册"
                onClicked: {
                    pageLoader.source = ""
                    pageLoader.source = "Register.qml"
                }
            }
            Button {
                id: okButton
                width: 50
                height: 30
                text: "登录"
                onClicked: {
                    if (myData.selectUserInfo(
                                userNameInput.text) === userPasswordInput.text) {
                        console.log("sucess")
                    } else {
                        console.log("fail")
                    }
                }
            }
        }
    }
}
