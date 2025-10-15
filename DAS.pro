#-------------------------------------------------
#
# Project created by QtCreator 2020-04-23T08:34:43
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DAS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += PROJECT=\\\"$$PWD\\\"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    booking.cpp \
    cancellation.cpp \
    records.cpp \
    mydb.cpp \
    reschedule.cpp

HEADERS += \
    mainwindow.h \
    booking.h \
    cancellation.h \
    records.h \
    mydb.h \
    reschedule.h

FORMS += \
    mainwindow.ui \
    booking.ui \
    cancellation.ui \
    records.ui \
    reschedule.ui

# Specify the directory for the output executable
DESTDIR = $$OUT_PWD/../Qt-Doctor-Appointment-System/build

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    README.md
