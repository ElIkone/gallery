import QtQuick 1.1

Rectangle {
    id: imageViewer

    property bool barsVisible: true
    property alias source: image.source

    signal requestClose

    anchors.fill: parent

    color: "black"

    MouseArea {
        id: mouseEater

        anchors.fill: parent

        property int sX
        property int sY

        onClicked: {
        }

        onDoubleClicked: {

        }

        onPressed: {
            sX = mouseX
            sY = mouseY
        }

        onMouseXChanged: {
            if (image.width>imageViewer.width){

            }
            console.log("Image width: "+image.width)
            console.log("Image height: "+image.height)
            console.log("Image painted width: "+image.paintedWidth)
            console.log("Image painted height: "+image.paintedHeight)
        }

        onMouseYChanged: {
        }

        onReleased: {
        }

        onCanceled: {
        }
    }

    //    Flickable {

    //        anchors.fill: parent

    //        contentHeight: image.height
    //        contentWidth: image.width

    Image {
        id: image

        clip: true
        anchors.fill: parent

        asynchronous: true

        fillMode: Image.PreserveAspectCrop
    }

    //    }


    TopBar {
        id: topBar

        anchors.top: parent.top

        visible: barsVisible

        onBackPressed: {
            requestClose()
        }
    }

    BottomBar {
        id: bottomBar

        anchors.bottom: parent.bottom

        visible: barsVisible
    }
}
