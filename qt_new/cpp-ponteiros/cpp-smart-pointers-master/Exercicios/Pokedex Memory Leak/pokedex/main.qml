import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import PokemonAbstractModel 1.0
import "components"
import theme 1.0

ApplicationWindow {
    color: Colors.gray200
    height: 800
    visible: true
    width: 800

    footer: Footer {
        vNrPokemons: pokemonsGridView.count
    }
    header: Header {
    }

    Component {
        id: pokemonCardDetailsComponent

        PokemonCardDetails {
        }
    }

    PopupManager {
        id: popupManager

        anchors.fill: parent
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        FiltersRow {
            function handleOnCheckChanged() {
                pokemonsGridView.vIsAnimated = switchAnimated.checked;
            }

            switchAnimated.onCheckedChanged: handleOnCheckChanged()
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.topMargin: Metrics.margin.m8
            color: Colors.gray200

            GridView {
                id: pokemonsGridView

                property bool vIsAnimated: false

                anchors.fill: parent
                cellHeight: 200
                cellWidth: 200
                clip: true
                enabled: !pokemonAbstractModel.isFetching

                delegate: PokemonCard {
                    id: pokemonCard

                    function handleOnSelected(pokemonModel) {
                        popupManager.doPush(pokemonCardDetailsComponent, pokemonModel);
                    }

                    vIsAnimated: pokemonsGridView.vIsAnimated

                    onSelected: pokemonCard.handleOnSelected(pokemonModel)
                }
                model: PokemonAbstractModel {
                    id: pokemonAbstractModel

                }
            }

            Loading {
                anchors.centerIn: parent
                height: 300
                visible: pokemonAbstractModel.isFetching
                width: 300
            }
        }
    }
}
