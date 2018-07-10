import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: userLogin
    width: mainWindow.width
    height: mainWindow.height - 40
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
                    pageLoader.source = "Register.qml"
                }
            }
            Button {
                id: okButton
                width: 50
                height: 30
                text: "登录"
                onClicked: {
                    if(userNameInput.text&&userPasswordInput.text) {
                        mainWindow.userName=userNameInput.text
                        client.request(request.verifyAccount(userNameInput.text, userPasswordInput.text))
                        var loginFlag = client.loginSystem()
                        if(loginFlag === 1) {
                            client.request(request.getUserFolder(userNameInput.text, 1, "/"))
                            var topFolders =  client.getUserFolder()
                            mainWindow.dataVector=topFolders
//                            mainWindow.dataVector  = topFolders
                            pageLoader.source = ""
                            mainWindow.loginFlag=1
                            mainStack.push(myfilepan)
                        }
                    }
                }
            }
        }
    }
}
