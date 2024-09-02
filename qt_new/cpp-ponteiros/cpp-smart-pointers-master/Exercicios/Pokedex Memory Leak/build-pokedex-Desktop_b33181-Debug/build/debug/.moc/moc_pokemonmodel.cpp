/****************************************************************************
** Meta object code from reading C++ file 'pokemonmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../pokedex/model/pokemonmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pokemonmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PokemonModel_t {
    QByteArrayData data[9];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PokemonModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PokemonModel_t qt_meta_stringdata_PokemonModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PokemonModel"
QT_MOC_LITERAL(1, 13, 13), // "dsNameChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "dsCrieUrlChanged"
QT_MOC_LITERAL(4, 45, 13), // "spriteChanged"
QT_MOC_LITERAL(5, 59, 6), // "dsName"
QT_MOC_LITERAL(6, 66, 9), // "dsCrieUrl"
QT_MOC_LITERAL(7, 76, 6), // "sprite"
QT_MOC_LITERAL(8, 83, 19) // "PokemonSpriteModel*"

    },
    "PokemonModel\0dsNameChanged\0\0"
    "dsCrieUrlChanged\0spriteChanged\0dsName\0"
    "dsCrieUrl\0sprite\0PokemonSpriteModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PokemonModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00495903,
       6, QMetaType::QString, 0x00495903,
       7, 0x80000000 | 8, 0x0049590b,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void PokemonModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PokemonModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dsNameChanged(); break;
        case 1: _t->dsCrieUrlChanged(); break;
        case 2: _t->spriteChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PokemonModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PokemonModel::dsNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PokemonModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PokemonModel::dsCrieUrlChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PokemonModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PokemonModel::spriteChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PokemonSpriteModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PokemonModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->dsName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->dsCrieUrl(); break;
        case 2: *reinterpret_cast< PokemonSpriteModel**>(_v) = _t->sprite(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<PokemonModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDsName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDsCrieUrl(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSprite(*reinterpret_cast< PokemonSpriteModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject PokemonModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PokemonModel.data,
    qt_meta_data_PokemonModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PokemonModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PokemonModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PokemonModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PokemonModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PokemonModel::dsNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PokemonModel::dsCrieUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PokemonModel::spriteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
