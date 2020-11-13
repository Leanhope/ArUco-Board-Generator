#-------------------------------------------------
#
# Project created by QtCreator 2020-10-01T19:42:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArucoBoardGui
TEMPLATE = app
CONFIG += console c++11

SOURCES += main.cpp\
        boardgenerator.cpp

HEADERS  += boardgenerator.h

FORMS    += boardgenerator.ui

# OpenCV
INCLUDEPATH += /usr/local/include/opencv4

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_aruco
LIBS += -lopencv_imgcodecs
