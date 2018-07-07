import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import "./mypan"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 900
    height: 600
    flags: Qt.Window | Qt.FramelessWindowHint //去标题栏
    property var loginFlag: 0
    TitleBar {
        id: titleBar
        //        visible: false
        onMypanstart: {

            if (mainStack.depth > 1)
                mainStack.clear()
            mainStack.push(myfilepan)
        }
        onTransmitstart: {
            if (mainStack.depth > 1)
                mainStack.clear()
            mainStack.push(trans)
        }
        onSharestart: {
            if (mainStack.depth > 1)
                mainStack.clear()
            mainStack.push(share)
        }
    }

    Rectangle {
        id: mainInterface
        y: titleBar.height + 5
        width: parent.width
        height: parent.height - titleBar.height

        StackView {
            id: mainStack
            anchors.fill: parent
            //            initialItem: Item {
            //                id: mypan
            //                Mypan {
            //                }
            //            }
        }
        //        Text {
        //            id: centerText
        //            anchors.centerIn: parent
        //            text: "depth " + mainStack.depth
        //        }
        //        Text {
        //            id: center
        //            anchors.top: centerText.bottom
        //            anchors.topMargin: 50
        //            anchors.left: centerText.left
        //            text: "index " + mainStack.status
        //        }
    }
    Loader {
        id: pageLoader
    }

    Component {
        id: myfilepan
        Mypan {
        }
    }

    Component {
        id: trans
        Transmit {
        }
    }

    Component {
        id: share
        Share {
        }
    }
    Component.onCompleted: {
        pageLoader.source = "Login.qml"
    }
}
