#ifndef POKEMONCONVERTER_H
#define POKEMONCONVERTER_H

#include "model/pokemonmodel.h"

#include "network/response/pokemonresponse.h"

class PokemonConverter {
public:
    static PokemonModel* toModel( const PokemonResponse* pokemonResponse );
};

#endif // POKEMONCONVERTER_H
