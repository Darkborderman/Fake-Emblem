#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T19:17:02
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    unit.cpp \
    sword_infantry.cpp \
    spear_infantry.cpp \
    axe_infantry.cpp \
    background.cpp \
    grand_castle.cpp \
    axe_calvery.cpp \
    sword_calvery.cpp \
    spear_calvery.cpp \
    axe_armored.cpp \
    sword_armored.cpp \
    spear_armored.cpp \
    bow_infantry.cpp \
    longbow_infantry.cpp \
    spear_calvery_throwing.cpp \
    axe_calvery_throwing.cpp \
    red_magic_infantry.cpp \
    blue_magic_infantry.cpp \
    green_magic_infantry.cpp \
    sword_infantry_throwing.cpp \
    sword_infantry_lord.cpp \
    spear_calvery_lord.cpp \
    bow_calvery.cpp \
    audio.cpp \
    magic.cpp \
    bomb.cpp \
    account.cpp \
    heal.cpp \
    lightning.cpp

HEADERS  += mainwindow.h \
    unit.h \
    sword_infantry.h \
    spear_infantry.h \
    axe_infantry.h \
    background.h \
    grand_castle.h \
    axe_calvery.h \
    sword_calvery.h \
    spear_calvery.h \
    axe_armored.h \
    sword_armored.h \
    spear_armored.h \
    bow_infantry.h \
    longbow_infantry.h \
    spear_calvery_throwing.h \
    axe_calvery_throwing.h \
    red_magic_infantry.h \
    blue_magic_infantry.h \
    green_magic_infantry.h \
    sword_infantry_throwing.h \
    sword_infantry_lord.h \
    spear_calvery_lord.h \
    bow_calvery.h \
    audio.h \
    magic.h \
    bomb.h \
    account.h \
    heal.h \
    lightning.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
