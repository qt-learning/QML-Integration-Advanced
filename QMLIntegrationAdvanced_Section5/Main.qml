import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls.Basic
import QMLIntegrationAdvanced

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Integration Advanced")

    footer: Button {
        text: qsTr("Call Q_INVOKABLE method to reset ellipse's properties")
        onClicked: {
            slider.value = 25
            ellipse.setProperties(slider.value, "blue")
        }
    }

    header: Column {
        width: parent.width

        Button {
            width: parent.width
            text: qsTr("Select ellipse's color")
            onClicked: { colorDialog.open() }
        }

        Label {
            width: parent.width
            text: qsTr("Resize ellipse's border")
        }

        Slider {
            id: slider

            width: parent.width
            value: 25
            from: 0
            to: Math.min(ellipse.width, ellipse.height) / 2
        }
    }

    EllipseExtended {
        id: ellipse

        anchors.centerIn: parent
        width: 200
        height: 200
        color: "blue"
        border: slider.value
        name: "My ellipse"

        onColorChanged: {
            ellipseInfo()
            console.log("Name: " + name)
        }
    }

    ColorDialog {
        id: colorDialog

        selectedColor: ellipse.color
        onAccepted: ellipse.color = selectedColor
    }
}
