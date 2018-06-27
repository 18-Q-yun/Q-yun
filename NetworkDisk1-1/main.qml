import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import DataBase 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    flags: Qt.Window | Qt.FramelessWindowHint //去标题栏

    DataBase {
        id: myData
    }
    Loader {
        id: pageLoader
    }
    Component.onCompleted: {
        pageLoader.source = "Login.qml"
        myData.initDataBase()
    }
}
