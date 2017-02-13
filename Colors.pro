TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consoleinterface.cpp

LIBS += -lGL -lGLU -lglut

HEADERS += \
    consoleinterface.h
