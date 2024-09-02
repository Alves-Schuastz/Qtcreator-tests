#ifndef POKEMONCONTROLLER_H
#define POKEMONCONTROLLER_H

#include "network/endpoint/pokemonendpoint.h"

#include "network/response/pokemonreferenceresponse.h"

#include "model/pokemonmodel.h"

class PokemonController {
public:
    QList<PokemonModel*> findByPagination( const int offset, const int limit ) const;
    QList<PokemonModel*> findByUrl( const QList<QString>& urls ) const;
private:
    QList<QString> findReferences( const int offset, const int limit ) const;
    PokemonEndpoint _pokemonEndpoint;
};

#endif // POKEMONCONTROLLER_H
