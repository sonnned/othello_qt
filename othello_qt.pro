TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    game.cpp \
        main.cpp \
        matriz.cpp \
    player.cpp

HEADERS += \
    game.h \
    macros.h \
    matriz.h \
    player.h
