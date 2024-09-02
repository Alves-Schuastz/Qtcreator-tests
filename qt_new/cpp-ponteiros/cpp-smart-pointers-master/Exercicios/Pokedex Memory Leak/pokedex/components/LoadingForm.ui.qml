import QtQuick 2.15
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.15

Item {
    property alias canvas: canvas

    ColumnLayout {
        anchors.fill: parent

        Canvas {
            id: canvas

            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width
            antialiasing: true
        }
    }
}
