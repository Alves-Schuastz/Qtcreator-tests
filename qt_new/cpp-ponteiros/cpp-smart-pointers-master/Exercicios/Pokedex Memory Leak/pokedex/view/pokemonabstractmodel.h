#ifndef POKEMONABSTRACTMODEL_H
#define POKEMONABSTRACTMODEL_H

#include <QQmlEngine>
#include <QAbstractListModel>

#include "model/pokemonmodel.h"

class PokemonAbstractModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY( bool isFetching READ isFetching WRITE setIsFetching NOTIFY isFetchingChanged FINAL )
public:
    explicit PokemonAbstractModel( QObject* parent = nullptr );

    enum Roles {
        vNameRole = Qt::UserRole,
        vCrieUrl,
        vSprite
    };

    int rowCount( const QModelIndex& parent ) const override;

    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;

    QHash<int, QByteArray> roleNames() const override;

    bool isFetching() const;
    void setIsFetching( bool isFetching );

signals:
    void isFetchingChanged();

protected:
    bool canFetchMore( const QModelIndex& parent ) const override;
    void fetchMore( const QModelIndex& parent ) override;
private:
    int _nrOffSet;
    bool _isFetching;
    QList<PokemonModel*> _pokemons;
};

#endif // POKEMONABSTRACTMODEL_H
