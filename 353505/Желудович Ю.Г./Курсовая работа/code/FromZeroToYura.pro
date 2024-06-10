QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    casino.cpp \
    character.cpp \
    clothes.cpp \
    food.cpp \
    happiness.cpp \
    health.cpp \
    housing.cpp \
    job.cpp \
    linearcongruentialgenerator.cpp \
    main.cpp \
    mainwindow.cpp \
    relationship.cpp \
    rotableitem.cpp \
    startpage.cpp \
    transport.cpp

HEADERS += \
    casino.h \
    character.h \
    clothes.h \
    food.h \
    happiness.h \
    health.h \
    housing.h \
    job.h \
    linearcongruentialgenerator.h \
    mainwindow.h \
    relationship.h \
    rotableitem.h \
    startpage.h \
    transport.h

FORMS += \
    casino.ui \
    clothes.ui \
    food.ui \
    happiness.ui \
    health.ui \
    housing.ui \
    job.ui \
    mainwindow.ui \
    relationship.ui \
    startpage.ui \
    transport.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
