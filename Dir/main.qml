import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import DataBase 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int dirLevelFlag: 1 //目录层次标志值
    property string currentDir: currentDirName.text

    DataBase {
        id: mydata
    }
    Row {
        Text {
            id: recover
            text: "返回上一级"
            color: dirLevelFlag > 1 ? "blue" : "black"
            MouseArea {
                anchors.fill: parent
                onClicked: {

                    if (dirLevelFlag >= 2) {

                        mymodel.clear()
                        mymodel.levelDirName = "123firstDir"
                        mymodel.lastFileName = "/"
                        mymodel.readAllDir()
                    }
                }
            }
        }
        Text {

            text: qsTr("|")
        }
        Text {
            text: "全部文件"
            color: "blue"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mymodel.clear()
                    mymodel.levelDirName = "123firstDir"
                    mymodel.lastFileName = "/"
                    mymodel.readAllDir()
                }
            }
        }
        Text {
            id: currentFigure
            text: ""
        }
        Text {
            id: currentDirName
            text: ""
            color: "black"
            MouseArea {
                anchors.fill: parent
            }
        }
    }
    GridView {
        x: 0
        y: 30
        id: dirGridView
        width: 300
        height: 200
        model: Dirmodel {
            id: mymodel
        }
        delegate: Column {
            id: dirDelegate
            property string currentFileName: fileText.text //保存当前文件夹名
            Image {
                id: name
                source: fileicon
                width: 30
                height: 30
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mydata.insertLevelDir("123secondDir", "文件", "mymv")
                        dirLevelFlag++

                        dirDelegate.GridView.view.currentIndex = index
                        currentDirName.text = dirDelegate.GridView.view.currentItem.currentFileName
                        currentFigure.text = ">"
                        mymodel.clear()
                        mymodel.levelDirName = "123secondDir"
                        mymodel.lastFileName = "mymv"
                        mymodel.readAllDir()
                    }
                }
            }
            Text {
                id: fileText
                text: filename
                color: dirDelegate.GridView.isCurrentItem ? "blue" : "black"
            }
        }

        highlightFollowsCurrentItem: true
        focus: true
    }

    Component.onCompleted: {
        mydata.initDataBase()
        mymodel.levelDirName = "123firstDir"
        mymodel.lastFileName = "/"
        mymodel.readAllDir()
    }
}
