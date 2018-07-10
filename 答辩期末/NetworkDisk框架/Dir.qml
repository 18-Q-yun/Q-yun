import QtQuick 2.0
import QtQuick.Controls 1.4
GridView {
    id: dirGridView
    signal dirClick(var currentDirName)
    property var newFolder: mainWindow.newFolderFlag
    signal  newFolderGrid               //在新建文件夹时发射该信号则定位当前页面
    model: Dirmodel {
        id: mymodel
    }
    delegate:Column {
        id: dirDelegate
        property string currentFileName: fileText.text //保存当前文件夹名
        property var  imageIcon: name.source
        Image {
            id: name
            source: fileicon
            width: 30
            height: 30
            MouseArea {
                anchors.fill: parent

                onDoubleClicked: {                  
                        dirDelegate.GridView.view.currentIndex = index
                      var imageSource =dirDelegate.GridView.view.currentItem.imageIcon
                    console.log(imageSource)
                       if(imageSource == "qrc:/图片/Icon图片/dir_icon.png"){
                        mainWindow.level++
                        var clickDirName= dirDelegate.GridView.view.currentItem.currentFileName
                        mainWindow.currentDirNameVector[level]= dirDelegate.GridView.view.currentItem.currentFileName
                                                   dirClick(clickDirName)

                      }else{
                          mainWindow.downloadResourceName=dirDelegate.GridView.view.currentItem.currentFileName
                           mainWindow.downloadResourceFlag=true
                       }

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
            newFolderGrid()  //发射信号代表在新建文件夹
            if(mainWindow.newFolderFlag){                          //在其他stackView的页面该条件不成立则不会添加新的文件夹，在当前stackView中的当前页面条件成立，则添加新的文件夹
                mymodel.append({
                                   filename: mainWindow.newFolderName,
                                   fileicon: "./图片/Icon图片/dir_icon.png"
                               })
                mainWindow.newFolderFlag=false
            }

        }
    }

}



