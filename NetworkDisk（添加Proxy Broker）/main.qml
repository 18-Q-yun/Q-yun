import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import DataBase 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 640
    flags: Qt.Window | Qt.FramelessWindowHint //去标题栏
    property var level: "123firstDir"
    property var last: "/"
    DataBase {
        id: myData
    }
    Loader {
        id: pageLoader
    }
    StackView {
        id: dirPageStack
        anchors.fill: parent
    }

    Connections {
        target: dirPageStack.currentItem
        onDirClicked: {

            mainWindow.last = currentDirName
            console.log(currentDirName)
            mainWindow.level = "123secondDir"

            dirPageStack.push(page)
        }
    }
    Component.onCompleted: {
        pageLoader.source = "Login.qml"
        myData.initDataBase()
    }
    Component {
        id: page
        Dir {
        }
    }
}
