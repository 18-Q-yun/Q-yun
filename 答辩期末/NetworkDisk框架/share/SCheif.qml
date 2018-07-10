import QtQuick 2.0

Rectangle {
    id: share
    width: 900
    height: 600
    color: "#e61515"
    Text {
        id: text
        anchors.centerIn: parent
        text: qsTr("This is a scene about share with friends.")
    }
}
