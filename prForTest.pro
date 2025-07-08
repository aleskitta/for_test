QT += testlib widgets


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += tst_t_integers.h
SOURCES += \
           ../main_project/mainwindow.cpp \
           tst_t_integers.cpp

LIBS += -L$$PWD/../main_project/debug -lmain_project_name
INCLUDEPATH += ../main_project
