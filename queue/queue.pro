TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        sbg_circlequeue_test.cpp

HEADERS += \
    sbg_circle_queue.hpp \
    sbg_circlequeue_test.h \
    sbg_queue_list.hpp
