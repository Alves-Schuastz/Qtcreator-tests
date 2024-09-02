#include "pokemonreferenceresponse.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

PokemonReferenceResponse::PokemonReferenceResponse() :
    _urlByName( {} ) {}

void PokemonReferenceResponse::fromJson( QJsonDocument& document ) {

    QJsonArray pokemonsArray = document["results"].toArray();

    for ( const QJsonValue& pokemonJson : pokemonsArray ) {
        _urlByName.insert( pokemonJson["name"].toString(), pokemonJson["url"].toString() );
    }

}

QMap<QString, QString> PokemonReferenceResponse::urlByName() const {
    return _urlByName;
}
