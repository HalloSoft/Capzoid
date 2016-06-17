#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T18:15:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capzoid
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    webcaminput.cpp \
    controlwidget.cpp \
    aboutbox.cpp \
    triggerwidget.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    webcaminput.h \
    controlwidget.h \
    aboutbox.h \
    triggerwidget.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    controlwidget.ui \
    aboutbox.ui \
    triggerwidget.ui \
    settingsdialog.ui

VERSION_MAJOR = 3
VERSION_MINOR = 0
VERSION_REVISION = 0
VERSION_BUILD = 4
DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
           "VERSION_MINOR=$$VERSION_MINOR"\
           "VERSION_REVISION=$$VERSION_REVISION"\
           "VERSION_BUILD=$$VERSION_BUILD"
VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_REVISION}.$${VERSION_BUILD}

# for linux
unix {
#    INCLUDEPATH += /usr/include/opencv
#    LIBS += -L/usr/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio
    LIBS += -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
}

RESOURCES += \
    pixmaps.qrc
