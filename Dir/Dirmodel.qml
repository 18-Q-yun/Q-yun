import QtQuick 2.0
import DataBase 1.0

ListModel {
    id: mymodel
    property string levelDirName
    property string lastFileName
    function readAllDir() {
        var result = mydata.selectLevelDir(levelDirName, lastFileName)
        console.log("sdfgh")
        for (var i = 0; i !== result.length; ++i) {
            console.log("hello")

            mymodel.append({
                               filename: result[i],
                               fileicon: "./图片/file.svg"
                           })
        }
    }
}
