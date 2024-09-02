#ifndef POKEMONENDPOINT_H
#define POKEMONENDPOINT_H

#include <http-request/httprequestmanager.h>

#include "network/response/pokemonreferenceresponse.h"
#include "network/response/pokemonresponse.h"

class PokemonEndpoint {
public:
    PokemonEndpoint();
    PokemonReferenceResponse* findByPagination( const int offset, const int limit ) const;
    PokemonResponse* findByUrl( const QString& url ) const;
private:
    HttpRequestManager _httpRequestManager;
};

#endif // POKEMONENDPOINT_H
