#include "pokemonspriteresponse.h"

PokemonSpriteResponse::PokemonSpriteResponse( QJsonDocument& document ) :
    _dsUrlAnimated( "" ) {
    fromJson( document );
}

QString PokemonSpriteResponse::dsUrlAnimated() const {
    return _dsUrlAnimated;
}

void PokemonSpriteResponse::fromJson( QJsonDocument& document ) {
    _dsUrlAnimated = document["sprites"]["versions"]["generation-v"]["black-white"]["animated"]["front_default"].toString();
}
