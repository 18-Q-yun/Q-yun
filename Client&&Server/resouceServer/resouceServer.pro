TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    resourceserver.cpp \
    resourcetransmission.cpp \
    action.cpp \
    localfolder.cpp \
    resource.cpp

QMAKE_LFLAGS += -lboost_system -lboost_thread -lpthread

HEADERS += \
    resourceserver.h \
    resourcetransmission.h \
    action.h \
    localfolder.h \
    resource.h
