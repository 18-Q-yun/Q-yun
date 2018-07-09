import QtQuick 2.0

Rectangle {
    width: 30
    height: 30
    color: "#F5F5F5"
    //    radius: 10 //设置圆角半径
    property string normalPath
    //按钮正常和鼠标离开按钮区后的图片路径
    property string enterPath
    //鼠标进入按钮区域时的图片路径
    property string pressPath
    //鼠标按下时的图片路径
    property string releasedPath

    //鼠标释放后的图片路径
    signal buttonClick
    property bool windowStatus: true
    //鼠标点击时发送此信号
    Image {
        id: background
        anchors.fill: parent
        source: normalPath
        MouseArea {
            //处理鼠标事件
            anchors.fill: parent
            hoverEnabled: true //处理没有按下时的鼠标事件
            onClicked: buttonClick() //点击按钮时发送buttonClick信号
            onEntered: background.source = enterPath //鼠标进入按钮区
            onPressed: background.source = pressPath //鼠标按下
            onExited: background.source = normalPath //鼠标离开按钮区
            onReleased: background.source = releasedPath //鼠标释放
        }
    }
    function maxButtonClick() {
        if (windowStatus) {

            //检查此时窗口的状态
            //windowStatus=true说明窗口此时处于正常大小
            windowStatus = false //改变窗口状态

            mainWindow.showMaximized() //将窗口最大化

            //重新加载窗口最大化后的最大化按钮图标
            normalPath = "./图片/TitleBar图片/restore1.png"
            enterPath = "./图片/TitleBar图片/restore2.png"
            pressPath = "./图片/TitleBar图片/restore3.png"
            releasedPath = "./图片/TitleBar图片/restore4.png"
        } else {

            //windowStatus=false说明窗口此时处于最大化
            windowStatus = true

            mainWindow.showNormal() //将窗口改为正常大小

            normalPath = "./图片/TitleBar图片/max1.png"
            enterPath = "./图片/TitleBar图片/max2.png"
            pressPath = "./图片/TitleBar图片/max3.png"
            releasedPath = "./图片/TitleBar图片/max4.png"
        }
    }
}
