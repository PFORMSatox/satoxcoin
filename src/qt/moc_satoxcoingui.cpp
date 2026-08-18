/****************************************************************************
** Meta object code from reading C++ file 'satoxcoingui.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/satoxcoingui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'satoxcoingui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SatoxcoinGUI_t {
    QByteArrayData data[75];
    char stringdata0[1040];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SatoxcoinGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SatoxcoinGUI_t qt_meta_stringdata_SatoxcoinGUI = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SatoxcoinGUI"
QT_MOC_LITERAL(1, 13, 11), // "receivedURI"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "uri"
QT_MOC_LITERAL(4, 30, 16), // "requestedRestart"
QT_MOC_LITERAL(5, 47, 4), // "args"
QT_MOC_LITERAL(6, 52, 17), // "setNumConnections"
QT_MOC_LITERAL(7, 70, 5), // "count"
QT_MOC_LITERAL(8, 76, 16), // "setNetworkActive"
QT_MOC_LITERAL(9, 93, 13), // "networkActive"
QT_MOC_LITERAL(10, 107, 13), // "handleRestart"
QT_MOC_LITERAL(11, 121, 12), // "setNumBlocks"
QT_MOC_LITERAL(12, 134, 9), // "blockDate"
QT_MOC_LITERAL(13, 144, 21), // "nVerificationProgress"
QT_MOC_LITERAL(14, 166, 7), // "headers"
QT_MOC_LITERAL(15, 174, 7), // "message"
QT_MOC_LITERAL(16, 182, 5), // "title"
QT_MOC_LITERAL(17, 188, 5), // "style"
QT_MOC_LITERAL(18, 194, 5), // "bool*"
QT_MOC_LITERAL(19, 200, 3), // "ret"
QT_MOC_LITERAL(20, 204, 24), // "currencySelectionChanged"
QT_MOC_LITERAL(21, 229, 9), // "unitIndex"
QT_MOC_LITERAL(22, 239, 16), // "onCurrencyChange"
QT_MOC_LITERAL(23, 256, 8), // "newIndex"
QT_MOC_LITERAL(24, 265, 12), // "getPriceInfo"
QT_MOC_LITERAL(25, 278, 16), // "getLatestVersion"
QT_MOC_LITERAL(26, 295, 22), // "updateIconsOnlyToolbar"
QT_MOC_LITERAL(27, 318, 19), // "setEncryptionStatus"
QT_MOC_LITERAL(28, 338, 6), // "status"
QT_MOC_LITERAL(29, 345, 11), // "setHDStatus"
QT_MOC_LITERAL(30, 357, 9), // "hdEnabled"
QT_MOC_LITERAL(31, 367, 20), // "handlePaymentRequest"
QT_MOC_LITERAL(32, 388, 18), // "SendCoinsRecipient"
QT_MOC_LITERAL(33, 407, 9), // "recipient"
QT_MOC_LITERAL(34, 417, 19), // "incomingTransaction"
QT_MOC_LITERAL(35, 437, 4), // "date"
QT_MOC_LITERAL(36, 442, 4), // "unit"
QT_MOC_LITERAL(37, 447, 7), // "CAmount"
QT_MOC_LITERAL(38, 455, 6), // "amount"
QT_MOC_LITERAL(39, 462, 4), // "type"
QT_MOC_LITERAL(40, 467, 7), // "address"
QT_MOC_LITERAL(41, 475, 5), // "label"
QT_MOC_LITERAL(42, 481, 9), // "assetName"
QT_MOC_LITERAL(43, 491, 11), // "checkAssets"
QT_MOC_LITERAL(44, 503, 8), // "mnemonic"
QT_MOC_LITERAL(45, 512, 16), // "gotoOverviewPage"
QT_MOC_LITERAL(46, 529, 15), // "gotoHistoryPage"
QT_MOC_LITERAL(47, 545, 20), // "gotoReceiveCoinsPage"
QT_MOC_LITERAL(48, 566, 17), // "gotoSendCoinsPage"
QT_MOC_LITERAL(49, 584, 4), // "addr"
QT_MOC_LITERAL(50, 589, 18), // "gotoSignMessageTab"
QT_MOC_LITERAL(51, 608, 20), // "gotoVerifyMessageTab"
QT_MOC_LITERAL(52, 629, 11), // "openClicked"
QT_MOC_LITERAL(53, 641, 14), // "gotoAssetsPage"
QT_MOC_LITERAL(54, 656, 20), // "gotoCreateAssetsPage"
QT_MOC_LITERAL(55, 677, 20), // "gotoManageAssetsPage"
QT_MOC_LITERAL(56, 698, 24), // "gotoRestrictedAssetsPage"
QT_MOC_LITERAL(57, 723, 14), // "optionsClicked"
QT_MOC_LITERAL(58, 738, 12), // "aboutClicked"
QT_MOC_LITERAL(59, 751, 15), // "showDebugWindow"
QT_MOC_LITERAL(60, 767, 30), // "showDebugWindowActivateConsole"
QT_MOC_LITERAL(61, 798, 16), // "showWalletRepair"
QT_MOC_LITERAL(62, 815, 22), // "showHelpMessageClicked"
QT_MOC_LITERAL(63, 838, 17), // "trayIconActivated"
QT_MOC_LITERAL(64, 856, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(65, 890, 6), // "reason"
QT_MOC_LITERAL(66, 897, 21), // "showNormalIfMinimized"
QT_MOC_LITERAL(67, 919, 13), // "fToggleHidden"
QT_MOC_LITERAL(68, 933, 12), // "toggleHidden"
QT_MOC_LITERAL(69, 946, 14), // "detectShutdown"
QT_MOC_LITERAL(70, 961, 12), // "showProgress"
QT_MOC_LITERAL(71, 974, 9), // "nProgress"
QT_MOC_LITERAL(72, 984, 18), // "setTrayIconVisible"
QT_MOC_LITERAL(73, 1003, 19), // "toggleNetworkActive"
QT_MOC_LITERAL(74, 1023, 16) // "showModalOverlay"

    },
    "SatoxcoinGUI\0receivedURI\0\0uri\0"
    "requestedRestart\0args\0setNumConnections\0"
    "count\0setNetworkActive\0networkActive\0"
    "handleRestart\0setNumBlocks\0blockDate\0"
    "nVerificationProgress\0headers\0message\0"
    "title\0style\0bool*\0ret\0currencySelectionChanged\0"
    "unitIndex\0onCurrencyChange\0newIndex\0"
    "getPriceInfo\0getLatestVersion\0"
    "updateIconsOnlyToolbar\0setEncryptionStatus\0"
    "status\0setHDStatus\0hdEnabled\0"
    "handlePaymentRequest\0SendCoinsRecipient\0"
    "recipient\0incomingTransaction\0date\0"
    "unit\0CAmount\0amount\0type\0address\0label\0"
    "assetName\0checkAssets\0mnemonic\0"
    "gotoOverviewPage\0gotoHistoryPage\0"
    "gotoReceiveCoinsPage\0gotoSendCoinsPage\0"
    "addr\0gotoSignMessageTab\0gotoVerifyMessageTab\0"
    "openClicked\0gotoAssetsPage\0"
    "gotoCreateAssetsPage\0gotoManageAssetsPage\0"
    "gotoRestrictedAssetsPage\0optionsClicked\0"
    "aboutClicked\0showDebugWindow\0"
    "showDebugWindowActivateConsole\0"
    "showWalletRepair\0showHelpMessageClicked\0"
    "trayIconActivated\0QSystemTrayIcon::ActivationReason\0"
    "reason\0showNormalIfMinimized\0fToggleHidden\0"
    "toggleHidden\0detectShutdown\0showProgress\0"
    "nProgress\0setTrayIconVisible\0"
    "toggleNetworkActive\0showModalOverlay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SatoxcoinGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  254,    2, 0x06 /* Public */,
       4,    1,  257,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  260,    2, 0x0a /* Public */,
       8,    1,  263,    2, 0x0a /* Public */,
      10,    1,  266,    2, 0x0a /* Public */,
      11,    4,  269,    2, 0x0a /* Public */,
      15,    4,  278,    2, 0x0a /* Public */,
      15,    3,  287,    2, 0x2a /* Public | MethodCloned */,
      20,    1,  294,    2, 0x0a /* Public */,
      22,    1,  297,    2, 0x0a /* Public */,
      24,    0,  300,    2, 0x0a /* Public */,
      25,    0,  301,    2, 0x0a /* Public */,
      26,    1,  302,    2, 0x0a /* Public */,
      27,    1,  305,    2, 0x0a /* Public */,
      29,    1,  308,    2, 0x0a /* Public */,
      31,    1,  311,    2, 0x0a /* Public */,
      34,    7,  314,    2, 0x0a /* Public */,
      43,    0,  329,    2, 0x0a /* Public */,
      44,    0,  330,    2, 0x0a /* Public */,
      45,    0,  331,    2, 0x08 /* Private */,
      46,    0,  332,    2, 0x08 /* Private */,
      47,    0,  333,    2, 0x08 /* Private */,
      48,    1,  334,    2, 0x08 /* Private */,
      48,    0,  337,    2, 0x28 /* Private | MethodCloned */,
      50,    1,  338,    2, 0x08 /* Private */,
      50,    0,  341,    2, 0x28 /* Private | MethodCloned */,
      51,    1,  342,    2, 0x08 /* Private */,
      51,    0,  345,    2, 0x28 /* Private | MethodCloned */,
      52,    0,  346,    2, 0x08 /* Private */,
      53,    0,  347,    2, 0x08 /* Private */,
      54,    0,  348,    2, 0x08 /* Private */,
      55,    0,  349,    2, 0x08 /* Private */,
      56,    0,  350,    2, 0x08 /* Private */,
      57,    0,  351,    2, 0x08 /* Private */,
      58,    0,  352,    2, 0x08 /* Private */,
      59,    0,  353,    2, 0x08 /* Private */,
      60,    0,  354,    2, 0x08 /* Private */,
      61,    0,  355,    2, 0x08 /* Private */,
      62,    0,  356,    2, 0x08 /* Private */,
      63,    1,  357,    2, 0x08 /* Private */,
      66,    1,  360,    2, 0x08 /* Private */,
      66,    0,  363,    2, 0x28 /* Private | MethodCloned */,
      68,    0,  364,    2, 0x08 /* Private */,
      69,    0,  365,    2, 0x08 /* Private */,
      70,    2,  366,    2, 0x08 /* Private */,
      72,    1,  371,    2, 0x08 /* Private */,
      73,    0,  374,    2, 0x08 /* Private */,
      74,    0,  375,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::Double, QMetaType::Bool,    7,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt, 0x80000000 | 18,   16,   15,   17,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,   16,   15,   17,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Bool, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 37, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   35,   36,   38,   39,   40,   41,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 64,   65,
    QMetaType::Void, QMetaType::Bool,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,   71,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SatoxcoinGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SatoxcoinGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedURI((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->requestedRestart((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setNetworkActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->handleRestart((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 6: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool*(*)>(_a[4]))); break;
        case 7: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 8: _t->currencySelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onCurrencyChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->getPriceInfo(); break;
        case 11: _t->getLatestVersion(); break;
        case 12: _t->updateIconsOnlyToolbar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setEncryptionStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setHDStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: { bool _r = _t->handlePaymentRequest((*reinterpret_cast< const SendCoinsRecipient(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->incomingTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 17: _t->checkAssets(); break;
        case 18: _t->mnemonic(); break;
        case 19: _t->gotoOverviewPage(); break;
        case 20: _t->gotoHistoryPage(); break;
        case 21: _t->gotoReceiveCoinsPage(); break;
        case 22: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->gotoSendCoinsPage(); break;
        case 24: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->gotoSignMessageTab(); break;
        case 26: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->gotoVerifyMessageTab(); break;
        case 28: _t->openClicked(); break;
        case 29: _t->gotoAssetsPage(); break;
        case 30: _t->gotoCreateAssetsPage(); break;
        case 31: _t->gotoManageAssetsPage(); break;
        case 32: _t->gotoRestrictedAssetsPage(); break;
        case 33: _t->optionsClicked(); break;
        case 34: _t->aboutClicked(); break;
        case 35: _t->showDebugWindow(); break;
        case 36: _t->showDebugWindowActivateConsole(); break;
        case 37: _t->showWalletRepair(); break;
        case 38: _t->showHelpMessageClicked(); break;
        case 39: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 40: _t->showNormalIfMinimized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->showNormalIfMinimized(); break;
        case 42: _t->toggleHidden(); break;
        case 43: _t->detectShutdown(); break;
        case 44: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 45: _t->setTrayIconVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->toggleNetworkActive(); break;
        case 47: _t->showModalOverlay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SatoxcoinGUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SatoxcoinGUI::receivedURI)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SatoxcoinGUI::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SatoxcoinGUI::requestedRestart)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SatoxcoinGUI::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SatoxcoinGUI.data,
    qt_meta_data_SatoxcoinGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SatoxcoinGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SatoxcoinGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SatoxcoinGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SatoxcoinGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void SatoxcoinGUI::receivedURI(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SatoxcoinGUI::requestedRestart(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_UnitDisplayStatusBarControl_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnitDisplayStatusBarControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnitDisplayStatusBarControl_t qt_meta_stringdata_UnitDisplayStatusBarControl = {
    {
QT_MOC_LITERAL(0, 0, 27), // "UnitDisplayStatusBarControl"
QT_MOC_LITERAL(1, 28, 17), // "updateDisplayUnit"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 8), // "newUnits"
QT_MOC_LITERAL(4, 56, 15), // "onMenuSelection"
QT_MOC_LITERAL(5, 72, 8), // "QAction*"
QT_MOC_LITERAL(6, 81, 6) // "action"

    },
    "UnitDisplayStatusBarControl\0"
    "updateDisplayUnit\0\0newUnits\0onMenuSelection\0"
    "QAction*\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitDisplayStatusBarControl[] = {

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
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void UnitDisplayStatusBarControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UnitDisplayStatusBarControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateDisplayUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onMenuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UnitDisplayStatusBarControl::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_UnitDisplayStatusBarControl.data,
    qt_meta_data_UnitDisplayStatusBarControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UnitDisplayStatusBarControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitDisplayStatusBarControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnitDisplayStatusBarControl.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int UnitDisplayStatusBarControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
