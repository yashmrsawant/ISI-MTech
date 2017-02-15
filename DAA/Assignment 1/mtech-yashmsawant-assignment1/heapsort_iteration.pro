TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    test.cpp \
    heapsort.cpp \
    mergesort.cpp \
    quicksort.cpp \
    main_solution.cpp

HEADERS += \
    heapsort.h \
    mergesort.h \
    quicksort.h \
    commons.h \
    gnuplot.h \
    stack.h

DISTFILES +=
