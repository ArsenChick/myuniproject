TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    myfunc.c \
    square.c

HEADERS += \
    myfunc.h \
    square.h

QMAKE_CFLAGS += -Wall -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
