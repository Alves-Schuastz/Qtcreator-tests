#ifndef POKEMONSPRITEMODEL_H
#define POKEMONSPRITEMODEL_H

#include <QObject>

class PokemonSpriteModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString dsUrlAnimated READ dsUrlAnimated WRITE setDsUrlAnimated NOTIFY dsUrlAnimatedChanged FINAL )
public:
    explicit PokemonSpriteModel( const QString& dsUrlAnimated );

    QString dsUrlAnimated() const;
    void setDsUrlAnimated( const QString& dsUrlAnimated );

signals:
    void dsUrlAnimatedChanged();

private:
    QString _dsUrlAnimated;
};

#endif // POKEMONSPRITEMODEL_H
