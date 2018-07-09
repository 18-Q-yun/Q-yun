import QtQuick 2.0
ListModel {
    id: mymodel
    //    property string levelDirName
    property string lastFileName
    property var dirData
    property var  level
    function readAllDir() {
        mymodel.clear()
        if(mainWindow. level==1  ){
            dirData=mainWindow. dataVector

            for (var i = 0; i !==dirData.length; ++i) {

                mymodel.append({
                                   filename: dirData[i],
                                   fileicon: "./图片/Icon图片/dir_icon.png"
                               })
            }
        }else{
            client.request(request.getUserFolder(mainWindow.userName,mainWindow.level,mainWindow.last))
            dirData=client.getUserFolder()

            for (var i = 0; i !==dirData.length; ++i) {

                mymodel.append({
                                   filename: dirData[i],
                                   fileicon: "./图片/Icon图片/dir_icon.png"
                               })
                console.log("element2"+dirData[i])
            }
        }
    }

}


