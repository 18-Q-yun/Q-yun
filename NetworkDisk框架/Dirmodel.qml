import QtQuick 2.0
import DataBase 1.0

ListModel {
    id: mymodel
    property string levelDirName
    property string lastFileName
    function readAllDir() {
        var result = myData.selectLevelDir(levelDirName, lastFileName)

        for (var i = 0; i !== result.length; ++i) {

            mymodel.append({
                               filename: result[i],
                               fileicon: "./图片/Icon图片/dir_icon.png"
                           })
            console.log(result[i])
        }
    }
}
