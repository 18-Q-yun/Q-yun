import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
import "./mypan"
import Client 1.0
import Request 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 900
    height: 600
    flags: Qt.Window | Qt.FramelessWindowHint //去标题栏
    property int loginFlag: 0
    property var newFolderName               //新建文件夹的名字
    property var newFolderFlag:false              //新建文件夹的标志值，在Cheif中的信号处理器中改变其值
    property var  dataVector//第一次进入系统时的目录数据
    property int level:1           //标志此刻所处的层次
    property string last:""//表示上一次的文件名
    property var currentDirNameVector     //存储的是所有的当前文件夹名，一个数组，每进入一次目录就会添加一个上层文件夹名，当需要返回页面时再顺序取出
    property var userName                  //用户登录时获取用户的帐号信息
    property string currentDirName:""    //用户当前文件夹
    property var downloadResourceName
    property var  downloadResourceFlag: false
    signal newFolder
    Client {
        id:client
    }
    Request {
        id: request
    }

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

        }

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
        currentDirNameVector=new Array
        currentDirNameVector[1]=""
    }

}
