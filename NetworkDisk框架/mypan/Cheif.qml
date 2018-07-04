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
        //        anchors.bottom: leftScene.bottom
        anchors.top: leftScene.top
        anchors.topMargin: 2
        width: 900 - Screen.desktopAvailableWidth / 15
        height: (Screen.desktopAvailableHeight * 4) / 5
        StackView {
            id: rStackView
            anchors.fill: parent
            initialItem: Item {
                AllFile {
                }
            }
            popEnter: Transition {
                NumberAnimation {
                    properties: "opacity"
                    from: 1
                    to: 1
                    duration: 20000
                }
            }

            popExit: Transition {
                NumberAnimation {

                    properties: "opacity"
                    from: 1
                    to: 1
                    duration: 20000
                }
            }
            pushEnter: Transition {
                NumberAnimation {

                    properties: "opacity"
                    from: 1
                    to: 1
                    duration: 20000
                }
            }

            pushExit: Transition {
                NumberAnimation {
                    properties: "opacity"
                    from: 1
                    to: 1
                    duration: 20000
                }
            }
        }
    }
    Component {
        id: allfile
        AllFile {
        }
    }

    Component {
        id: pic
        Rectangle {
        }
    }
    Component {
        id: vid
        Rectangle {
        }
    }
    Component {
        id: doc
        Rectangle {
        }
    }
    Component {
        id: mus
        Rectangle {
        }
    }
    Component {
        id: oth
        Rectangle {
        }
    }
}
