TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    resourceserver.cpp \
    folder.cpp \
    resourcetransmission.cpp \
    clientmember.cpp

QMAKE_LFLAGS += -lboost_system -lboost_thread -lpthread

HEADERS += \
    resourceserver.h \
    folder.h \
    resourcetransmission.h \
    clientmember.h
