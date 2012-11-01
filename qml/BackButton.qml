import QtQuick 1.1

Rectangle {
    id: backButton

    signal clicked

    width: 60
    height: 40

    color: "#00000000"

    border.color: "white"
    border.width: 2

    Text {

        anchors.centerIn: parent
        text: qsTr("Back")
        color: "white"

    }

    MouseArea {

        anchors.fill: parent

        onClicked: {
            backButton.clicked()
        }
    }
}
