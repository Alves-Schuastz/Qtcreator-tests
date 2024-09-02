#ifndef POKEMONREFERENCERESPONSE_H
#define POKEMONREFERENCERESPONSE_H

#include <QMap>

#include <http-request/response/httpstubresponse.h>

class PokemonReferenceResponse : public HttpStubResponse {
public:
    PokemonReferenceResponse();

    void fromJson( QJsonDocument& document ) override;

    QMap<QString, QString> urlByName() const;

private:
    QMap<QString, QString> _urlByName;
};

#endif // POKEMONREFERENCERESPONSE_H
