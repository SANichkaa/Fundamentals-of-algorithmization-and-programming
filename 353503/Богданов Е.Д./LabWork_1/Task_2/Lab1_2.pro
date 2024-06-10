QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ellips.cpp \
    eught_star.cpp \
    fife_star.cpp \
    krug.cpp \
    main.cpp \
    mainwindow.cpp \
    poligonchik.cpp \
    rectic.cpp \
    scenka.cpp \
    six_star.cpp \
    squart.cpp \
    tri_pram.cpp \
    tri_ravn_bedr.cpp \
    tri_ravn_stor.cpp

HEADERS += \
    ellips.h \
    eught_star.h \
    fife_star.h \
    krug.h \
    mainwindow.h \
    poligonchik.h \
    rectic.h \
    scenka.h \
    six_star.h \
    squart.h \
    tri_pram.h \
    tri_ravn_bedr.h \
    tri_ravn_stor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
