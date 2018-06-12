import VPlayApps 1.0
import QtQuick 2.0

App {
    FontLoader {
        id: normalFont
        source: "../assets/couri.ttf"
    }
    Column {
        x: 200
        y: 200
        Row {
            id: account
            Text {
                id: userAccountLabel
                text: qsTr("帐号")
                font: normalFont.name
            }
            TextInput {
                id: userAccount
                height: 30
                width: 80
                color: "red"
            }
        }
        Row {
            id: password
            Text {
                id: userPasswordLabel
                text: qsTr("密码")
                font: normalFont.name
            }
            TextInput {
                id: userPassword
                height: 30
                width: 80
                color: "red"
                echoMode: TextInput.Password
            }
        }
    }
    Rectangle {
        x: 200
        y: 290
        width: 50
        height: 50

        Text {
            id: register
            text: qsTr("register")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {

                DataBase.insertUserInfo(userAccount.text, userPassword.text)
                console.log("register sucess")
            }
        }
    }
    Rectangle {
        x: 290
        y: 290
        width: 50
        height: 50
        Text {
            id: login
            text: qsTr("login")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (userPassword.text === (DataBase.selectUserInfo(
                                               userAccount.text))) {
                    console.log("log in sucess")
                    var tablename = DataBase.createLevelDirTable(
                                1, userAccount.text)
                    DataBase.insertLevelDir(tablename, "my resource", "/")
                }
            }
        }
    }
    Component.onCompleted: {
        DataBase.initDataBase()
        DataBase.createUserInfoTable()
    }
}
