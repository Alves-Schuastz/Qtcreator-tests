import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import theme 1.0

Rectangle {
    property alias switchAnimated: switchAnimated

    Layout.fillWidth: true
    Layout.leftMargin: 6
    Layout.preferredHeight: 40
    Layout.rightMargin: 6
    Layout.topMargin: Metrics.margin.m8
    color: Colors.white100
    radius: Metrics.radius.r4

    Switch {
        id: switchAnimated

        palette.windowText: Colors.gray600
        text: qsTr("Ativar animação")
    }
}
