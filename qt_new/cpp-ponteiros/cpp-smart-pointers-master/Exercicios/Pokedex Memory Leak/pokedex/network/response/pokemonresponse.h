#ifndef POKEMONRESPONSE_H
#define POKEMONRESPONSE_H

#include <http-request/response/httpstubresponse.h>

#include "pokemonspriteresponse.h"

class PokemonResponse : public HttpStubResponse {
public:
    PokemonResponse();

    void fromJson( QJsonDocument& document ) override;

    QString dsName() const;
    QString dsCrieUrl() const;

    PokemonSpriteResponse *sprite() const;

private:
    QString _dsName;
    QString _dsCrieUrl;
    PokemonSpriteResponse* _sprite;

};

#endif // POKEMONRESPONSE_H
