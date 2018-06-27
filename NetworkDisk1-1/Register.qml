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
        id: registerTitle
        anchors.top: titleBar.bottom
        anchors.topMargin: 20
        anchors.left: titleBar.left
        anchors.leftMargin: 300
        text: qsTr("注册")
        font.pointSize: 60
        font.bold: true
    }
    Column {
        anchors.top: registerTitle.bottom
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 200
        spacing: 30

        //用户名称
        Row {
            spacing: 30
            Text {
                text: "输入帐号:"
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
                text: "输入密码:"
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
            spacing: 30
            Text {
                text: "确认密码:"
                font.pointSize: textSize
            }
            TextField {
                id: userPasswordInputAgain
                echoMode: TextInput.Password
                focus: true
                font.pointSize: textSize
            }
        }
        Row {
            spacing: 150
            Button {
                id: registerButton
                width: 50
                height: 30
                text: "注册"
                onClicked: {
                    if (userPasswordInput.text !== userPasswordInputAgain.text) {

                    }
                    if (userNameInput.text && userPasswordInput.text
                            && userPasswordInputAgain.text) {
                        myData.insertUserInfo(userNameInput.text,
                                              userPasswordInput.text)
                        pageLoader.source = "Login.qml"
                    }
                }
            }
            Button {
                id: cancelButton
                width: 50
                height: 30
                text: "取消"
                onClicked: {
                    mainWindow.close()
                }
            }
        }
    }
}
