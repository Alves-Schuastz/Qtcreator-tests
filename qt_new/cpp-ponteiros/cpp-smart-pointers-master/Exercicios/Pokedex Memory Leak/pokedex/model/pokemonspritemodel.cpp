#include "pokemonspritemodel.h"

PokemonSpriteModel::PokemonSpriteModel( const QString& dsUrlAnimated ) :
    _dsUrlAnimated( dsUrlAnimated ) {}

QString PokemonSpriteModel::dsUrlAnimated() const {
    return _dsUrlAnimated;
}

void PokemonSpriteModel::setDsUrlAnimated( const QString& dsUrlAnimated ) {
    if ( _dsUrlAnimated == dsUrlAnimated ) {
        return;
    }
    _dsUrlAnimated = dsUrlAnimated;
    emit dsUrlAnimatedChanged();
}
