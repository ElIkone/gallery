import QtQuick 1.1

Rectangle {
    id: topBar

    signal backPressed

    width: parent.width

    height: 60

    opacity: 0.75

    color: "darkgrey"


    BackButton {

        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        onClicked: {
            backPressed()
        }
    }
}
