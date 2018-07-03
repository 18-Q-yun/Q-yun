import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Window 2.2

Rectangle {
    id: cheifScene
    LeftfunctionList {
        id: leftScene
        onAllFileDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(allfile)
        }
        onPictureDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(pic)
        }
        onVideoDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(vid)
        }
        onDocumentDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(doc)
        }

        onMusicDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(mus)
        }

        onOtherDisplay: {
            if (rStackView.depth > 1)
                rStackView.clear()
            rStackView.push(oth)
        }
    }

    Rectangle {
        id: rigthScene
        anchors.left: leftScene.right
        anchors.leftMargin: 3
        anchors.bottom: leftScene.bottom
        width: 900 - Screen.desktopAvailableWidth / 15
        height: (Screen.desktopAvailableHeight * 4) / 5

        StackView {
            id: rStackView
            anchors.fill: parent
            initialItem: Item {
                id: aFile
                Rectangle {
                    anchors.fill: parent
                    color: "blue"
                }
            }
            popEnter: Transition {
                NumberAnimation {

                    properties: "opacity"
                    from: 0.7
                    to: 1
                    duration: 20000
                }
            }

            popExit: Transition {
                NumberAnimation {

                    properties: "opacity"
                    from: 1
                    to: 0.7
                    duration: 20000
                }
            }
            pushEnter: Transition {
                NumberAnimation {

                    properties: "opacity"
                    from: 0.7
                    to: 1
                    duration: 20000
                }
            }

            pushExit: Transition {
                NumberAnimation {
                    properties: "opacity"
                    from: 1
                    to: 0.7
                    duration: 20000
                }
            }
        }
    }
    Component {
        id: allfile
        Rectangle {
            opacity: 1
            color: "#99FF99"
        }
    }
    Component {
        id: pic
        Rectangle {
            opacity: 0.8
            color: "#D28EFF"
        }
    }
    Component {
        id: vid
        Rectangle {
            opacity: 0.7
            color: "red"
        }
    }
    Component {
        id: doc
        Rectangle {
            //            opacity: 0.6
            color: "#5555FF"
        }
    }
    Component {
        id: mus
        Rectangle {
            opacity: 0.7
            color: "#FFEE99"
        }
    }
    Component {
        id: oth
        Rectangle {
            //            opacity: 0.6
            color: "red"
        }
    }
}
