import QtQuick 1.1

Rectangle {

    property string imgSource: ""

    width: 800
    height: 480

    smooth: true

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#2B2C2D"
        }

        GradientStop {
            position: 1
            color: "#121212"
        }
    }

    Text {
        id: lblTittle

        color: "white"

        text: "Gallery"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 10
    }

    GridView{
        id: gridview

        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: lblTittle.bottom
        anchors.bottom: parent.bottom

        clip: true
        model: imagesModel
        delegate: gridviewDelegate

        cellHeight: 180
        cellWidth: 180

        focus: true
    }

    Component {
        id: gridviewDelegate

        Item {

            width: gridview.cellWidth; height: gridview.cellHeight

            Rectangle {
                id: imgContainer

                color: "#000000"
                border.color: "white"
                border.width: 2
                radius: 5
                anchors.fill: parent
                anchors.margins: 10

                Image {
                    id: image

                    anchors.fill: parent

                    anchors.margins: 5

                    asynchronous: true
                    fillMode: Image.PreserveAspectFit
                    source: "file://"+path
                }

                MouseArea {

                    anchors.fill: parent

                    onClicked: {
                        imgSource = image.source;
                        loader.sourceComponent = imageViewer
                    }
                }
            }
        }
    }

    Loader {
        id: loader

        anchors.fill: parent
    }

    Component {
        id: imageViewer

        ImageViewer {
            source: imgSource

            onRequestClose: {
                loader.sourceComponent = undefined
            }
        }
    }
}
