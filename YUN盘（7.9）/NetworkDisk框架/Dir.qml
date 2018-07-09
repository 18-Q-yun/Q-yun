﻿import QtQuick 2.0
import QtQuick.Controls 1.4
GridView {
    id: dirGridView
    signal dirClick(var currentDirName)
    model: Dirmodel {
        id: mymodel
    }
    delegate:Column {
        id: dirDelegate
        property string currentFileName: fileText.text //保存当前文件夹名
        Image {
            id: name
            source: fileicon
            width: 30
            height: 30
            MouseArea {
                anchors.fill: parent
                onDoubleClicked: {
                    mainWindow.level++
                    dirDelegate.GridView.view.currentIndex = index
                    var clickDirName= dirDelegate.GridView.view.currentItem.currentFileName
                    mainWindow.currentDirNameVector[level]= dirDelegate.GridView.view.currentItem.currentFileName
                    dirClick(clickDirName)
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
    Component.onCompleted: {
        mymodel.level = mainWindow.level
        mymodel.lastFileName =   mainWindow.last
        mymodel.readAllDir()
    }
    Connections{
        target: mainWindow
        onNewFolder:{

            console.log("11"+mainWindow.newFolderName)
            mymodel.append({
                               filename: mainWindow.newFolderName,
                               fileicon: "./图片/Icon图片/dir_icon.png"
                           })
        }
    }

}



