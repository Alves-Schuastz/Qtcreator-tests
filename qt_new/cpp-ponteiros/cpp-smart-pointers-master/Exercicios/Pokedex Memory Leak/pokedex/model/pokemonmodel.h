#ifndef POKEMONMODEL_H
#define POKEMONMODEL_H

#include <QObject>

#include "pokemonspritemodel.h"

class PokemonModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString dsName READ dsName WRITE setDsName NOTIFY dsNameChanged FINAL )
    Q_PROPERTY( QString dsCrieUrl READ dsCrieUrl WRITE setDsCrieUrl NOTIFY dsCrieUrlChanged FINAL )
    Q_PROPERTY( PokemonSpriteModel * sprite READ sprite WRITE setSprite NOTIFY spriteChanged FINAL )
public:
    PokemonModel();

    QString dsName() const;
    void setDsName( const QString& DsName );

    QString dsCrieUrl() const;
    void setDsCrieUrl( const QString& dsCrieUrl );

    PokemonSpriteModel* sprite() const;
    void setSprite( PokemonSpriteModel* sprite );

signals:
    void dsNameChanged();
    void dsCrieUrlChanged();
    void spriteChanged();

private:
    QString _dsName;
    QString _dsCrieUrl;
    PokemonSpriteModel* _sprite;
};

#endif // POKEMONMODEL_H
