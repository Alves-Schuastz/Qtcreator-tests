import QtQuick 2.15
import theme 1.0

PokemonCardDetailsForm {
    id: root

    signal close

    function handleOnClose() {
        root.close();
    }

    buttonClose.onClicked: handleOnClose()
}
