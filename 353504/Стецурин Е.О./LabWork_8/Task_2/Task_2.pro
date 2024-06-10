QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-list-Desktop_Qt_6_6_1_GCC_64bit-Debug/release/ -llistheap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-list-Desktop_Qt_6_6_1_GCC_64bit-Debug/debug/ -llistheap
else:unix: LIBS += -L$$PWD/build-list-Desktop_Qt_6_6_1_GCC_64bit-Debug/ -llistheap

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-arrayheap-Desktop_Qt_6_6_1_GCC_64bit-Debug/release/ -larrayheap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-arrayheap-Desktop_Qt_6_6_1_GCC_64bit-Debug/debug/ -larrayheap
else:unix: LIBS += -L$$PWD/build-arrayheap-Desktop_Qt_6_6_1_GCC_64bit-Debug/ -larrayheap

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''
