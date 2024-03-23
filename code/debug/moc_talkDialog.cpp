/****************************************************************************
** Meta object code from reading C++ file 'talkDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../talkDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'talkDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_talkDialog_t {
    QByteArrayData data[22];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_talkDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_talkDialog_t qt_meta_stringdata_talkDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "talkDialog"
QT_MOC_LITERAL(1, 11, 14), // "SigCloseDialog"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 21), // "sigCheckCurrentStatus"
QT_MOC_LITERAL(4, 49, 11), // "sigEventLog"
QT_MOC_LITERAL(5, 61, 7), // "EventId"
QT_MOC_LITERAL(6, 69, 13), // "sltGetEventId"
QT_MOC_LITERAL(7, 83, 16), // "QList<EventInfo>"
QT_MOC_LITERAL(8, 100, 6), // "idList"
QT_MOC_LITERAL(9, 107, 12), // "sltShowEvent"
QT_MOC_LITERAL(10, 120, 9), // "eventName"
QT_MOC_LITERAL(11, 130, 10), // "sltShowCut"
QT_MOC_LITERAL(12, 141, 7), // "cutName"
QT_MOC_LITERAL(13, 149, 18), // "on_nextBtn_clicked"
QT_MOC_LITERAL(14, 168, 19), // "on_closeBtn_clicked"
QT_MOC_LITERAL(15, 188, 21), // "on_historyBtn_clicked"
QT_MOC_LITERAL(16, 210, 15), // "rightBtnClicked"
QT_MOC_LITERAL(17, 226, 1), // "n"
QT_MOC_LITERAL(18, 228, 20), // "on_optionBtn_clicked"
QT_MOC_LITERAL(19, 249, 21), // "on_optionBtn2_clicked"
QT_MOC_LITERAL(20, 271, 21), // "on_optionBtn3_clicked"
QT_MOC_LITERAL(21, 293, 23) // "on_closeHistory_clicked"

    },
    "talkDialog\0SigCloseDialog\0\0"
    "sigCheckCurrentStatus\0sigEventLog\0"
    "EventId\0sltGetEventId\0QList<EventInfo>\0"
    "idList\0sltShowEvent\0eventName\0sltShowCut\0"
    "cutName\0on_nextBtn_clicked\0"
    "on_closeBtn_clicked\0on_historyBtn_clicked\0"
    "rightBtnClicked\0n\0on_optionBtn_clicked\0"
    "on_optionBtn2_clicked\0on_optionBtn3_clicked\0"
    "on_closeHistory_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_talkDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   89,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,
      18,    0,  104,    2, 0x08 /* Private */,
      19,    0,  105,    2, 0x08 /* Private */,
      20,    0,  106,    2, 0x08 /* Private */,
      21,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void talkDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        talkDialog *_t = static_cast<talkDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigCloseDialog(); break;
        case 1: _t->sigCheckCurrentStatus(); break;
        case 2: _t->sigEventLog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sltGetEventId((*reinterpret_cast< QList<EventInfo>(*)>(_a[1]))); break;
        case 4: _t->sltShowEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sltShowCut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_nextBtn_clicked(); break;
        case 7: _t->on_closeBtn_clicked(); break;
        case 8: _t->on_historyBtn_clicked(); break;
        case 9: _t->rightBtnClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_optionBtn_clicked(); break;
        case 11: _t->on_optionBtn2_clicked(); break;
        case 12: _t->on_optionBtn3_clicked(); break;
        case 13: _t->on_closeHistory_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (talkDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&talkDialog::SigCloseDialog)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (talkDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&talkDialog::sigCheckCurrentStatus)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (talkDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&talkDialog::sigEventLog)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject talkDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_talkDialog.data,
      qt_meta_data_talkDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *talkDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *talkDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_talkDialog.stringdata0))
        return static_cast<void*>(const_cast< talkDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int talkDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void talkDialog::SigCloseDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void talkDialog::sigCheckCurrentStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void talkDialog::sigEventLog(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
