TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp
QMAKE_CXXFLAGS += -O2 -Wall -Wextra --save-temps

HEADERS += \
    fib.hpp
