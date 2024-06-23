QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkerboard.cpp \
    controller.cpp \
    coordinates.cpp \
    coordinates_database.cpp \
    crown.cpp \
    drawer.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    piece.cpp \
    piece_capture_manager.cpp \
    piece_frontend.cpp \
    piece_movement_manager.cpp \
    piece_promotion_manager.cpp \
    piece_state_manager.cpp \
    pieces_placement.cpp \
    tile.cpp

HEADERS += \
    checkerboard.h \
    common.h \
    controller.h \
    coordinates.h \
    coordinates_database.h \
    crown.h \
    drawer.h \
    game.h \
    gui_config.h \
    mainwindow.h \
    model.h \
    multi_capture_manager.h \
    piece.h \
    piece_capture_manager.h \
    piece_frontend.h \
    piece_movement_manager.h \
    piece_promotion_manager.h \
    piece_state_manager.h \
    pieces_placement.h \
    player_manager.h \
    selected_piece_manager.h \
    tile.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
