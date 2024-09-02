#include "pokemonconverter.h"

#include "model/pokemonspritemodel.h"

PokemonModel* PokemonConverter::toModel( const PokemonResponse* pokemonResponse ) {

    PokemonModel* pokemon = new PokemonModel();
    pokemon->setDsName( pokemonResponse->dsName() );
    pokemon->setDsCrieUrl( pokemonResponse->dsCrieUrl() );
    pokemon->setSprite( new PokemonSpriteModel( pokemonResponse->sprite()->dsUrlAnimated() ) );

    return pokemon;

}
