QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app
CONFIG += link_pkgconfig c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    textbutton.cpp \
    algorithm.cpp   

HEADERS  += mainwindow.h \
    textbutton.h \
    algorithm.h   

RESOURCES += \
    resources.qrc
