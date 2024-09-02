#include "pokemoncontroller.h"

#include "utils/retrytask.h"

#include "converter/pokemonconverter.h"

QList<PokemonModel*> PokemonController::findByPagination( const int offset, const int limit ) const {

    const QList<QString> urls = findReferences( offset, limit );

    QList<PokemonModel*> pokemons = findByUrl( urls );

    return pokemons;
}

QList<PokemonModel*> PokemonController::findByUrl( const QList<QString>& urls ) const {

    QList<PokemonModel*> pokemons = {};

    for ( const QString& dsUrl : urls ) {

        RetryTask::exec( [&]() {

            PokemonResponse* pokemonResponse = _pokemonEndpoint.findByUrl( dsUrl );

            if ( !pokemonResponse || !pokemonResponse->isSuccess() ) {
                return false;
            }

            pokemons.append( PokemonConverter::toModel( pokemonResponse ) );

            return true;
        } );
    }

    return pokemons;
}

QList<QString> PokemonController::findReferences( const int offset, const int limit ) const {
    return _pokemonEndpoint.findByPagination( offset, limit )->urlByName().values();
}
