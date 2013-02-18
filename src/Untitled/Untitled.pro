#-------------------------------------------------
#
# Project created by QtCreator 2013-01-10T12:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Untitled
TEMPLATE = app


SOURCES += main.cpp

HEADERS  += \
    AMaterial.h \
    ATexture.h \
    ASprite.h \
    AConfigurable.h \
    AConfiguration.h \
    AFactory.h \
    MaterialManager.h \
    MaterialFactory.h \
    ConfigurationFactory.h \
    AXmlFileParser.h \
    WindowMain.h \
    GraphicsScene.h \
    GraphicsView.h \
    SpritePlayer.h \
    SpriteBrick.h \
    Game.h \
    SpriteFactory.h \
    Map.h

FORMS    += \
    WindowMain.ui

RESOURCES += \
    textures.qrc
