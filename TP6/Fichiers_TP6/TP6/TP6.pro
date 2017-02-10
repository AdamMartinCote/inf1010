#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T00:31:29
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP6
TEMPLATE = app


RESOURCES += \
    images.qrc

SOURCES += main.cpp\
        Gamebay.cpp \
    Menu.cpp \
    ChoixAttaque.cpp \
    Creature.cpp \
    Dresseur.cpp \
    Polyland.cpp \
    ObjetMagique.cpp \
    AffichageInformationCreature.cpp \
    Pouvoir.cpp \
    ExceptionCreatureMorte.cpp

HEADERS  += Gamebay.h \
    Menu.h \
    ChoixAttaque.h \
    Creature.h \
    Dresseur.h \
    Polyland.h \
    Pouvoir.h \
    ObjetMagique.h \
    AffichageInformationCreature.h \
    ExceptionEchecCapture.h \
    ExceptionCreatureMorte.h \
    ExceptionAttaqueEchouee.h \
    Foncteur.h

