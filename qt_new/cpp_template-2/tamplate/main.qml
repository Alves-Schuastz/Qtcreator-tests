import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import TemplateListControl 1.0

ApplicationWindow {
    id: root

    function _carregarListModel(listModel, valores) {
        listModel.clear();
        for (var i = 0; i < valores.length; i++) {
            listModel.append({
                    "value": valores[i]
                });
        }
    }

    height: 480
    title: "Exercício de templates"
    visible: true
    width: 640

    Item {
        id: container

        anchors.fill: parent

        Component.onCompleted: {
            control.carregarValoresIniciais();
            if (paginaInteiros) {
                pilhaPaginas.push(paginaInteiros);
            }
        }

        ColumnLayout {
            anchors.fill: parent

            TabBar {
                id: tabBar

                Layout.fillWidth: true
                Layout.preferredHeight: 50

                TabButton {
                    text: "Números Inteiros"

                    onClicked: pilhaPaginas.push(paginaInteiros)
                }

                TabButton {
                    text: "Decimais"

                    onClicked: pilhaPaginas.push(paginaDecimais)
                }

                TabButton {
                    text: "Textos"

                    onClicked: pilhaPaginas.push(paginaTextos)
                }
            }

            StackView {
                id: pilhaPaginas

                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                id: btnAtualizar

                Layout.fillWidth: true
                text: "Ordenar"

                onClicked: control.ordenarValores()
            }
        }

        Component {
            id: paginaInteiros

            Page {
                title: "Números Inteiros"

                ListView {
                    id: listViewInteiros

                    anchors.fill: parent
                    model: inteirosModel

                    delegate: Item {
                        height: 40
                        width: container.width

                        Rectangle {
                            border.color: "black"
                            color: "lightblue"
                            height: 40
                            width: parent.width

                            Text {
                                anchors.centerIn: parent
                                text: model.value
                            }
                        }
                    }
                }
            }
        }

        Component {
            id: paginaTextos

            Page {
                title: "Textos"

                ListView {
                    id: listViewTextos

                    anchors.fill: parent
                    model: textosModel

                    delegate: Item {
                        height: 40
                        width: container.width

                        Rectangle {
                            border.color: "black"
                            color: "lightgreen"
                            height: 40
                            width: parent.width

                            Text {
                                anchors.centerIn: parent
                                text: model.value
                            }
                        }
                    }
                }
            }
        }

        Component {
            id: paginaDecimais

            Page {
                title: "Decimais"

                ListView {
                    id: listViewDecimais

                    anchors.fill: parent
                    model: decimaisModel

                    delegate: Item {
                        height: 40
                        width: container.width

                        Rectangle {
                            border.color: "black"
                            color: "red"
                            height: 40
                            width: parent.width

                            Text {
                                anchors.centerIn: parent
                                text: model.value
                            }
                        }
                    }
                }
            }
        }
    }

    ListModel {
        id: inteirosModel

    }

    ListModel {
        id: decimaisModel

    }

    ListModel {
        id: textosModel

    }

    TemplateListControl {
        id: control

        onDecimaisChanged: {
            root._carregarListModel(decimaisModel, control.decimais);
        }
        onInteirosChanged: {
            root._carregarListModel(inteirosModel, control.inteiros);
        }
        onTextosChanged: {
            root._carregarListModel(textosModel, control.textos);
        }
    }
}
