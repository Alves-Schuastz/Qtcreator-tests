import QtQuick 2.15
import QtQuick.Controls 2.15
import theme 1.0

ToolBar {
    required property int vNrPokemons

    height: 60

    background: Rectangle {
        color: Colors.white100
    }

    Text {
        anchors.centerIn: parent
        color: Colors.gray600
        font.family: Fonts.fontFamily
        font.pixelSize: 14
        text: qsTr(`Voce descobriu <b> ${vNrPokemons} </b> Pokemons`)
    }

    Rectangle {
        anchors.top: parent.top
        color: Colors.gray300
        height: 1
        width: parent.width
    }
}
