#-------------------------------------------------
#
# Project created by QtCreator 2017-03-17T20:01:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cold_storage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    user_admin.cpp \
    register_window.cpp \
    admin_window.cpp \
    user_vendor.cpp \
    user_farmer.cpp \
    search_window.cpp \
    vendor_window.cpp \
    farmer_window.cpp \
    smtp.cpp

HEADERS  += mainwindow.h \
    user.h \
    user_admin.h \
    register_window.h \
    admin_window.h \
    user_vendor.h \
    user_farmer.h \
    session.h \
    functions.h \
    search_window.h \
    vendor_window.h \
    function2.h \
    function3.h \
    farmer_window.h \
    form_validate.h \
    generaterand.h \
    generate_rand2.h \
    farmer_function.h \
    generate_rand3.h \
    smtp.h

FORMS    += mainwindow.ui \
    register_window.ui \
    admin_window.ui \
    search_window.ui \
    vendor_window.ui \
    enter_reg.ui \
    farmer_window.ui
