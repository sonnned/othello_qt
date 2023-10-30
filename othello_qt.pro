TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board_functions.cpp \
        main.cpp \
        matriz.cpp \
        piece.cpp \
        utilities.cpp

HEADERS += \
    board_functions.h \
    macros.h \
    matriz.h \
    piece.h \
    utilities.h
