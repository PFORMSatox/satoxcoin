/****************************************************************************
** Meta object code from reading C++ file 'mnemonicdialog.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/mnemonicdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mnemonicdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MnemonicDialog1_t {
    QByteArrayData data[7];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MnemonicDialog1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MnemonicDialog1_t qt_meta_stringdata_MnemonicDialog1 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MnemonicDialog1"
QT_MOC_LITERAL(1, 16, 27), // "updateMainWindowStackWidget"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 3), // "ind"
QT_MOC_LITERAL(4, 49, 23), // "on_acceptButton_clicked"
QT_MOC_LITERAL(5, 73, 25), // "on_walletNewRadio_clicked"
QT_MOC_LITERAL(6, 99, 25) // "on_walletOldRadio_clicked"

    },
    "MnemonicDialog1\0updateMainWindowStackWidget\0"
    "\0ind\0on_acceptButton_clicked\0"
    "on_walletNewRadio_clicked\0"
    "on_walletOldRadio_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MnemonicDialog1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MnemonicDialog1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MnemonicDialog1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMainWindowStackWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_acceptButton_clicked(); break;
        case 2: _t->on_walletNewRadio_clicked(); break;
        case 3: _t->on_walletOldRadio_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MnemonicDialog1::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MnemonicDialog1::updateMainWindowStackWidget)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MnemonicDialog1::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_MnemonicDialog1.data,
    qt_meta_data_MnemonicDialog1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MnemonicDialog1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MnemonicDialog1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MnemonicDialog1.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int MnemonicDialog1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MnemonicDialog1::updateMainWindowStackWidget(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MnemonicDialog2_t {
    QByteArrayData data[8];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MnemonicDialog2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MnemonicDialog2_t qt_meta_stringdata_MnemonicDialog2 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MnemonicDialog2"
QT_MOC_LITERAL(1, 16, 27), // "updateMainWindowStackWidget"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 3), // "ind"
QT_MOC_LITERAL(4, 49, 17), // "allCloseRequested"
QT_MOC_LITERAL(5, 67, 23), // "on_acceptButton_clicked"
QT_MOC_LITERAL(6, 91, 21), // "on_backButton_clicked"
QT_MOC_LITERAL(7, 113, 25) // "on_generateButton_clicked"

    },
    "MnemonicDialog2\0updateMainWindowStackWidget\0"
    "\0ind\0allCloseRequested\0on_acceptButton_clicked\0"
    "on_backButton_clicked\0on_generateButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MnemonicDialog2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MnemonicDialog2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MnemonicDialog2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMainWindowStackWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->allCloseRequested(); break;
        case 2: _t->on_acceptButton_clicked(); break;
        case 3: _t->on_backButton_clicked(); break;
        case 4: _t->on_generateButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MnemonicDialog2::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MnemonicDialog2::updateMainWindowStackWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MnemonicDialog2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MnemonicDialog2::allCloseRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MnemonicDialog2::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_MnemonicDialog2.data,
    qt_meta_data_MnemonicDialog2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MnemonicDialog2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MnemonicDialog2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MnemonicDialog2.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int MnemonicDialog2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void MnemonicDialog2::updateMainWindowStackWidget(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MnemonicDialog2::allCloseRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_MnemonicDialog3_t {
    QByteArrayData data[7];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MnemonicDialog3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MnemonicDialog3_t qt_meta_stringdata_MnemonicDialog3 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MnemonicDialog3"
QT_MOC_LITERAL(1, 16, 27), // "updateMainWindowStackWidget"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 3), // "ind"
QT_MOC_LITERAL(4, 49, 17), // "allCloseRequested"
QT_MOC_LITERAL(5, 67, 23), // "on_acceptButton_clicked"
QT_MOC_LITERAL(6, 91, 21) // "on_backButton_clicked"

    },
    "MnemonicDialog3\0updateMainWindowStackWidget\0"
    "\0ind\0allCloseRequested\0on_acceptButton_clicked\0"
    "on_backButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MnemonicDialog3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MnemonicDialog3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MnemonicDialog3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMainWindowStackWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->allCloseRequested(); break;
        case 2: _t->on_acceptButton_clicked(); break;
        case 3: _t->on_backButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MnemonicDialog3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MnemonicDialog3::updateMainWindowStackWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MnemonicDialog3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MnemonicDialog3::allCloseRequested)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MnemonicDialog3::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_MnemonicDialog3.data,
    qt_meta_data_MnemonicDialog3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MnemonicDialog3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MnemonicDialog3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MnemonicDialog3.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int MnemonicDialog3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MnemonicDialog3::updateMainWindowStackWidget(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MnemonicDialog3::allCloseRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_MnemonicDialog_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MnemonicDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MnemonicDialog_t qt_meta_stringdata_MnemonicDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MnemonicDialog"
QT_MOC_LITERAL(1, 15, 23), // "onChangeWindowRequested"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "index"
QT_MOC_LITERAL(4, 46, 15) // "closeMainDialog"

    },
    "MnemonicDialog\0onChangeWindowRequested\0"
    "\0index\0closeMainDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MnemonicDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void MnemonicDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MnemonicDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onChangeWindowRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->closeMainDialog(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MnemonicDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_MnemonicDialog.data,
    qt_meta_data_MnemonicDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MnemonicDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MnemonicDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MnemonicDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MnemonicDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
