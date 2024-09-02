#include "pokemonabstractmodel.h"

#include "utils/synctask.h"

#include "controller/pokemoncontroller.h"

namespace {
constexpr uint8_t NR_ITENS_PAGE = 30;
}

PokemonAbstractModel::PokemonAbstractModel( QObject* parent ) :
    QAbstractListModel( parent ),
    _nrOffSet( 0 ),
    _isFetching( false ),
    _pokemons( {} ) {}

int PokemonAbstractModel::rowCount( const QModelIndex& parent ) const {

    if ( parent.isValid() ) {
        return 0;
    }

    return _pokemons.size();
}

QVariant PokemonAbstractModel::data( const QModelIndex& index, int role ) const {

    if ( !index.isValid() ) {
        return QVariant();
    }

    const PokemonModel* pokemon = _pokemons.at( index.row() );

    switch ( role ) {
        case Roles::vNameRole:
            return pokemon->dsName();
        case Roles::vCrieUrl:
            return pokemon->dsCrieUrl();
        case Roles::vSprite:
            return QVariant::fromValue( pokemon->sprite() );
        default:
            return QVariant();
    }

}

QHash<int, QByteArray> PokemonAbstractModel::roleNames() const {

    static QHash<int, QByteArray> mapping {
        { Roles::vNameRole, "vNameRole" },
        { Roles::vCrieUrl, "vCrieUrl" },
        { Roles::vSprite, "vSprite" }
    };

    return mapping;
}

bool PokemonAbstractModel::canFetchMore( const QModelIndex& parent ) const {

    if ( parent.isValid() || _isFetching ) {
        return false;
    }

    return true;

}

void PokemonAbstractModel::fetchMore( const QModelIndex& parent ) {

    Q_UNUSED( parent )

    setIsFetching( true );

    QList<PokemonModel*> pokemons = {};

    QThread* mainThread = QThread::currentThread();

    SyncTask::runSync( [&]() {
        pokemons = PokemonController().findByPagination( _nrOffSet, NR_ITENS_PAGE );

        for ( PokemonModel* pokemon : qAsConst( pokemons ) ) {
            pokemon->moveToThread( mainThread );
            pokemon->sprite()->moveToThread( mainThread );
        }
    } );

    beginInsertRows( QModelIndex(), _pokemons.size(), _pokemons.size() + NR_ITENS_PAGE - 1 );

    _pokemons.append( pokemons );

    endInsertRows();

    _nrOffSet += NR_ITENS_PAGE;

    setIsFetching( false );

}

bool PokemonAbstractModel::isFetching() const {
    return _isFetching;
}

void PokemonAbstractModel::setIsFetching( bool isFetching ) {

    if ( _isFetching == isFetching ) {
        return;
    }

    _isFetching = isFetching;
    emit isFetchingChanged();
}
