#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T18:15:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capzoid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webcaminput.cpp

HEADERS  += mainwindow.h \
    webcaminput.h

FORMS    += mainwindow.ui

# for linux
unix {
    INCLUDEPATH += /usr/local/include/opencv
    LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio
}
