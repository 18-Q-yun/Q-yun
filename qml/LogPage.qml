import QtQuick 2.0

Item {
    Column {
        Row {
            id: account
            Text {
                id: userAccountLabel
                text: qsTr("帐号")
            }
            TextEdit {
                id: userAccount
            }
        }
        Row {
            id: password
            Text {
                id: userPasswordLabel
                text: qsTr("密码")
            }
            TextEdit {
                id: userPassword
            }
        }
    }
}
