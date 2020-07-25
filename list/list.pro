TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    sbg_dlist_test.cpp \
    sbg_list_test.cpp

HEADERS += \
    sbg_dlist.hpp \
    sbg_dlist_test.h \
    sbg_list.hpp \
    sbg_list_tail.hpp \
    sbg_list_test.h
