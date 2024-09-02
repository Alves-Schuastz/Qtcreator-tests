/****************************************************************************
** Meta object code from reading C++ file 'templatelistcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "templatelistcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'templatelistcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TemplateListControl_t {
    QByteArrayData data[13];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TemplateListControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TemplateListControl_t qt_meta_stringdata_TemplateListControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TemplateListControl"
QT_MOC_LITERAL(1, 20, 15), // "inteirosChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "textosChanged"
QT_MOC_LITERAL(4, 51, 15), // "decimaisChanged"
QT_MOC_LITERAL(5, 67, 14), // "ordenarValores"
QT_MOC_LITERAL(6, 82, 23), // "carregarValoresIniciais"
QT_MOC_LITERAL(7, 106, 8), // "inteiros"
QT_MOC_LITERAL(8, 115, 10), // "QList<int>"
QT_MOC_LITERAL(9, 126, 6), // "textos"
QT_MOC_LITERAL(10, 133, 14), // "QList<QString>"
QT_MOC_LITERAL(11, 148, 8), // "decimais"
QT_MOC_LITERAL(12, 157, 13) // "QList<double>"

    },
    "TemplateListControl\0inteirosChanged\0"
    "\0textosChanged\0decimaisChanged\0"
    "ordenarValores\0carregarValoresIniciais\0"
    "inteiros\0QList<int>\0textos\0QList<QString>\0"
    "decimais\0QList<double>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TemplateListControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x02 /* Public */,
       6,    0,   43,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, 0x80000000 | 8, 0x0049510b,
       9, 0x80000000 | 10, 0x0049510b,
      11, 0x80000000 | 12, 0x0009510b,

 // properties: notify_signal_id
       0,
       1,
       0,

       0        // eod
};

void TemplateListControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TemplateListControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inteirosChanged(); break;
        case 1: _t->textosChanged(); break;
        case 2: _t->decimaisChanged(); break;
        case 3: _t->ordenarValores(); break;
        case 4: _t->carregarValoresIniciais(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TemplateListControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TemplateListControl::inteirosChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TemplateListControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TemplateListControl::textosChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TemplateListControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TemplateListControl::decimaisChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TemplateListControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<int>*>(_v) = _t->inteiros(); break;
        case 1: *reinterpret_cast< QList<QString>*>(_v) = _t->textos(); break;
        case 2: *reinterpret_cast< QList<double>*>(_v) = _t->decimais(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TemplateListControl *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInteiros(*reinterpret_cast< QList<int>*>(_v)); break;
        case 1: _t->setTextos(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 2: _t->setDecimais(*reinterpret_cast< QList<double>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TemplateListControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TemplateListControl.data,
    qt_meta_data_TemplateListControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TemplateListControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TemplateListControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TemplateListControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TemplateListControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
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
void TemplateListControl::inteirosChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TemplateListControl::textosChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TemplateListControl::decimaisChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
