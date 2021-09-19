#-------------------------------------------------
#
# Project created by QtCreator 2021-09-17T20:09:18
#
#-------------------------------------------------

QT       += core gui opengl

LIBS += -lopengl32\
         -lGLU32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOpenGL
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include ($$PWD/Material/Material.pri)
include ($$PWD/Texture/Texture.pri)
include ($$PWD/particleSystem/particleSystem.pri)
include ($$PWD/Camera/Camera.pri)
include ($$PWD/Skybox/Skybox.pri)
include ($$PWD/Maps/Maps.pri)
SOURCES += \
        main.cpp \
        gamemain.cpp

HEADERS += \
        gamemain.h

FORMS += \
        gamemain.ui

RESOURCES += \
    resources.qrc

SUBDIRS += \
    ../../../QOpenGlDemo/lesson16/lesson16.pro
