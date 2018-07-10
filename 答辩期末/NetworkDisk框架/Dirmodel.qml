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

                var sumString =dirData[i].split(":")
                var imageSource

                if (sumString [1]==="D")  {
                    imageSource=   "./图片/Icon图片/dir_icon.png"

                }else if(sumString[1]==="W") {
                    imageSource= "./图片/Icon图片/doc_icon.png"

                }else if(sumString[1]==="V") {
                    imageSource="./图片/Icon图片/mv_icon.png"
                }else if(sumString[1]==="M") {
                    imageSource="./图片/Icon图片/music_icon.png"
                }else{
                    imageSource="./图片/Icon图片/other_icon.png"
                }
                mymodel.append({
                                   filename:sumString [0],
                                   fileicon: imageSource,


                               })

            }

        }else{
            client.request(request.getUserFolder(mainWindow.userName,mainWindow.level,mainWindow.last))
            dirData=client.getUserFolder()

            for (var i = 0; i !==dirData.length; ++i) {

                var sumString2 =dirData[i].split(":")
                var imageSource2
                if (sumString2[1]==="D")  {
                    imageSource2=   "./图片/Icon图片/dir_icon.png"

                }else if(sumString2[1]==="W") {
                    imageSource2= "./图片/Icon图片/doc_icon.png"
                }else if(sumString2[1]==="V") {
                    imageSource2="./图片/Icon图片/mv_icon.png"
                } else if(sumString2[1]==="M") {
                    imageSource2="./图片/Icon图片/music_icon.png"
                }else{
                    imageSource2="./图片/Icon图片/other_icon.png"
                }
                mymodel.append({
                                   filename:sumString2 [0],
                                   fileicon: imageSource2,


                               })

            }
        }
    }
}


