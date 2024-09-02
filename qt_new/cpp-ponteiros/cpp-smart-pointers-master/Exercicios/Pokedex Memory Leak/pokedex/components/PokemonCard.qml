import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.12
import theme 1.0

Item {
    id: root

    required property string vCrieUrl
    required property bool vIsAnimated
    required property string vNameRole
    required property var vSprite

    signal selected(var pokemonModel)

    height: 200
    width: 200

    RectangularGlow {
        id: rectangularGlow

        anchors.fill: rectangle
        color: Colors.gray100
        cornerRadius: Metrics.radius.r4
        glowRadius: 0
        spread: 0.0
    }

    MouseArea {
        anchors.fill: parent

        onClicked: root.selected({vSprite,vNameRole})
    }

    Rectangle {
        id: rectangle

        anchors.centerIn: parent
        anchors.fill: parent
        anchors.margins: Metrics.margin.m8
        color: Colors.white100
        radius: Metrics.radius.r4

        states: [
            State {
                name: "enabled"
                when: root.enabled

                PropertyChanges {
                    opacity: 1
                    target: root
                }

                PropertyChanges {
                    target: rectangularGlow
                    visible: true
                }
            },
            State {
                name: "disabled"
                when: !root.enabled

                PropertyChanges {
                    opacity: 0.5
                    target: root
                }

                PropertyChanges {
                    target: rectangularGlow
                    visible: false
                }
            }
        ]

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: Metrics.margin.m16

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 80

                AnimatedImage {
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit
                    playing: vIsAnimated
                    source: vSprite.dsUrlAnimated
                }
            }

            Text {
                Layout.alignment: Qt.AlignBottom
                color: Colors.blue500
                font: Fonts.title200
                horizontalAlignment: Text.AlignLeft
                text: vNameRole.toUpperCase()
            }
        }
    }
}
