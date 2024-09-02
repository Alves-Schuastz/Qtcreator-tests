#include "pokemonresponse.h"

PokemonResponse::PokemonResponse() :
    _dsName( "" ),
    _dsCrieUrl( "" ),
    _sprite( nullptr ) {}

void PokemonResponse::fromJson( QJsonDocument& document ) {
    _dsName = document["name"].toString();
    _dsCrieUrl = document["cries"]["latest"].toString();
    _sprite = new PokemonSpriteResponse( document );
}

QString PokemonResponse::dsName() const {
    return _dsName;
}

QString PokemonResponse::dsCrieUrl() const {
    return _dsCrieUrl;
}

PokemonSpriteResponse* PokemonResponse::sprite() const {
    return _sprite;
}
