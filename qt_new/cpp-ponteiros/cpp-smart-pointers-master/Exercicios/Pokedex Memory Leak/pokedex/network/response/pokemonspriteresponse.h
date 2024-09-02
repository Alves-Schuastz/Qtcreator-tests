#ifndef POKEMONSPRITERESPONSE_H
#define POKEMONSPRITERESPONSE_H

#include <QString>
#include <QJsonDocument>

class PokemonSpriteResponse {
public:
    explicit PokemonSpriteResponse( QJsonDocument& document );

    QString dsUrlAnimated() const;

private:
    QString _dsUrlAnimated;

    void fromJson( QJsonDocument& document );
};

#endif // POKEMONSPRITERESPONSE_H
