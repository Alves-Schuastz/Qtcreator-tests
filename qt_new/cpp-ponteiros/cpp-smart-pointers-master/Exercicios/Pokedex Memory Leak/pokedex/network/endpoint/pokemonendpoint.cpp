#include "pokemonendpoint.h"

namespace {
constexpr const char* BASE_URL = "https://pokeapi.co/api/v2/pokemon";
}

PokemonEndpoint::PokemonEndpoint() :
    _httpRequestManager() {}

PokemonReferenceResponse* PokemonEndpoint::findByPagination( const int offset, const int limit ) const {
    const QString url = HttpRequestManager::toQuerys( BASE_URL, {
        QString( "limit=%0" ).arg( limit ),
        QString( "offset=%0" ).arg( offset ),
    } );
    return _httpRequestManager.get<PokemonReferenceResponse>( url );
}

PokemonResponse* PokemonEndpoint::findByUrl( const QString& url ) const {
    return _httpRequestManager.get<PokemonResponse>( url );
}
