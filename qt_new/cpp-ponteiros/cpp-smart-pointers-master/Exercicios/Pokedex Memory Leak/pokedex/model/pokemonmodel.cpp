#include "pokemonmodel.h"

PokemonModel::PokemonModel() :
    _dsName( "" ),
    _dsCrieUrl( "" ),
    _sprite( nullptr ) {}

QString PokemonModel::dsName() const {
    return _dsName;
}

void PokemonModel::setDsName( const QString& dsName ) {

    if ( _dsName == dsName ) {
        return;
    }

    _dsName = dsName;
    emit dsNameChanged();
}

QString PokemonModel::dsCrieUrl() const {
    return _dsCrieUrl;
}

void PokemonModel::setDsCrieUrl( const QString& dsCrieUrl ) {

    if ( _dsCrieUrl == dsCrieUrl ) {
        return;
    }

    _dsCrieUrl = dsCrieUrl;
    emit dsCrieUrlChanged();
}

PokemonSpriteModel* PokemonModel::sprite() const {
    return _sprite;
}

void PokemonModel::setSprite( PokemonSpriteModel* sprite ) {

    if ( _sprite == sprite ) {
        return;
    }

    _sprite = sprite;
    emit spriteChanged();
}
