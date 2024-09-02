pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property string fontFamily: "Roboto"
    readonly property font title100: Qt.font({
            "family": fontFamily,
            "bold": true,
            "pixelSize": 12
        })
    readonly property font title200: Qt.font({
            "family": fontFamily,
            "bold": true,
            "pixelSize": 14
        })
    readonly property font title300: Qt.font({
            "family": fontFamily,
            "bold": true,
            "pixelSize": 16
        })
    readonly property font title400: Qt.font({
            "family": fontFamily,
            "bold": true,
            "pixelSize": 20
        })
    readonly property font title500: Qt.font({
            "family": fontFamily,
            "bold": true,
            "pixelSize": 24
        })
}
