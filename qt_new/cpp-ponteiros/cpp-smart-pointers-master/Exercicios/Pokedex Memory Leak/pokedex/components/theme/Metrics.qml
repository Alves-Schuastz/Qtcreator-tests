pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property QtObject margin: QtObject {
        readonly property int m12: 12
        readonly property int m16: 16
        readonly property int m4: 4
        readonly property int m8: 8
    }
    readonly property QtObject radius: QtObject {
        readonly property int r4: 4
    }
}
