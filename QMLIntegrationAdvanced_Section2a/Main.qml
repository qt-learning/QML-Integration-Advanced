import QtQuick
import QMLIntegrationAdvanced

Window {
    property point2D windowPosition: "Polar"

    title: "QML Integration Advanced"
    width: 640
    height: 480
    visible: true
    x: windowPosition.coordinate1
    y: windowPosition.coordinate2

    Text {
        id: mainText

        anchors.centerIn: parent
    }

    Component.onCompleted: {
        //place the window in the bottom right corner
        windowPosition.coordinate1 = Screen.width - width
        windowPosition.coordinate2 = Screen.height - height
        mainText.text = "Window's initial position: %1".arg(windowPosition.positionInfo(windowPosition.system))
    }
}
