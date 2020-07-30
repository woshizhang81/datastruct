TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        net_rb_treetest.cpp \
        sbg_tree_test.cpp \
        test_tree.cpp

HEADERS += \
    sbg_avl_tree.hpp \
    sbg_queue_list.hpp \
    sbg_rb_tree.hpp \
    sbg_rb_tree_net.hpp \
    sbg_stack_list.hpp \
    sbg_tree.hpp \
    sbg_tree_test.h \
    sbg_tree_traverse.hpp \
    test_tree.h

DISTFILES +=
