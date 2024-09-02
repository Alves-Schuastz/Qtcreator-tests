import QtQuick 2.15
import QtQuick.Controls 2.15
import theme 1.0

StackView {
    id: root

    /*!
       \qmlmethod PopupManager::doPop()

       \brief Essa função remove o ultimo elemento da stack, caso so exista um elemento na stack, faz o clear.
       Essa função deve ser chamada apenas internamente no PopupManager, quando o close do currentItem é disparado.
     */

    function doPop() {
        if (root.depth === 1) {
            root.clear();
            return;
        }
        root.pop();
    }

    /*!
       \qmlmethod PopupManager::doPush(popupComponent, properties)

       \a popupComponent - Component que vai ser exibido como primeiro elemento na stack

       \a properties - Propriedades do component, variaveis que ele tem a nivel de root

       \brief Essa função insere um novo component na stack
     */

    function doPush(popupComponent, properties) {
        var popup = root.push(popupComponent, properties);
        popup.close.connect(function handleOnClose() {
                popup.onClose.disconnect(handleOnClose);
                root.doPop();
            });
    }

    parent: Overlay.overlay
    visible: !root.empty

    background: Rectangle {
        color: Colors.gray100
        opacity: 0.5

        MouseArea {
            anchors.fill: parent
        }
    }
}
