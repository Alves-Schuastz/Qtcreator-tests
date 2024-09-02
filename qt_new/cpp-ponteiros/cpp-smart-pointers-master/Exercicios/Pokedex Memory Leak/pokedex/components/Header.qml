import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import theme 1.0

ToolBar {
    height: 70

    background: Rectangle {
        color: Colors.white100
    }

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 8

            Image {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight: 32
                Layout.preferredWidth: 32
                fillMode: Image.PreserveAspectFit
                source: "../resources/images/pokeball.png"
            }

            Text {
                color: Colors.gray600
                font: Fonts.title500
                text: qsTr("Pokedex")
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Colors.gray300
        }
    }
}
