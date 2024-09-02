import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import theme 1.0

Item {
    id: root

    property alias buttonClose: buttonClose
    property string vNameRole
    property var vSprite

    Rectangle {
        id: rectangleDetails

        anchors.centerIn: parent
        color: Colors.white100
        height: 400
        radius: Metrics.radius.r4
        width: 300

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: Metrics.margin.m16

            Text {
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                color: Colors.blue500
                font: Fonts.title500
                horizontalAlignment: Text.AlignLeft
                text: root.vNameRole
            }

            Rectangle {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredHeight: 160
                Layout.preferredWidth: 160
                color: Colors.gray200
                radius: 360

                AnimatedImage {
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit
                    height: 60
                    playing: true
                    source: root.vSprite.dsUrlAnimated
                    width: 60
                }
            }

            Button {
                id: buttonClose

                Layout.alignment: Qt.AlignBottom
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                font: Fonts.title300
                palette.buttonText: Colors.white100
                text: qsTr("Fechar")

                background: Rectangle {
                    color: Colors.blue500
                    radius: Metrics.radius.r4
                }
            }
        }
    }
}
