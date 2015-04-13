#-------------------------------------------------
#
# Project created by QtCreator 2015-01-12T12:05:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinQuedin
TEMPLATE = app

DEFINES += BDAY=\\\"$$system(date +%d)\\\"
DEFINES += BMONTH=\\\"$$system(date +%b)\\\"
DEFINES += BYEAR=\\\"$$system(date +%Y)\\\"
DEFINES += BHOUR=\\\"$$system(date +%H)\\\"
DEFINES += BMINUTE=\\\"$$system(date +%M)\\\"
DEFINES += BSECOND=\\\"$$system(date +%S)\\\"

SOURCES += main.cpp\
        mainwindow.cpp \
    danagrafici.cpp \
    titolistudio.cpp \
    laurea.cpp \
    impieghi.cpp \
    lavoro.cpp \
    utente.cpp \
    profilo.cpp \
    database.cpp \
    rete.cpp \
    nodo.cpp \
    ubasic.cpp \
    ubusiness.cpp \
    uexecutive.cpp \
    client.cpp \
    menubar.cpp \
    loginclientwindow.cpp \
    loginadminwindow.cpp \
    clientwindow.cpp \
    viewdatianagrafici.cpp \
    viewtitolistudio.cpp \
    widgetlaurea.cpp \
    widgetnewlaurea.cpp \
    widgetupdatelaurea.cpp \
    viewimpieghi.cpp \
    widgetimpiego.cpp \
    widgetnewimpiego.cpp \
    viewreti.cpp \
    widgetutenterete.cpp \
    viewricerca.cpp \
    widgetnewricerca.cpp \
    datiricerca.cpp \
    widgetutentericerca.cpp \
    admin.cpp \
    adminwindow.cpp \
    controller.cpp \
    viewgestioneutenti.cpp \
    widgetchooseplan.cpp \
    widgetabout.cpp \
    widgetwelcome.cpp \
    viewprofilo.cpp

HEADERS  += mainwindow.h \
    danagrafici.h \
    titolistudio.h \
    laurea.h \
    impieghi.h \
    lavoro.h \
    utente.h \
    profilo.h \
    database.h \
    rete.h \
    nodo.h \
    ubasic.h \
    ubusiness.h \
    uexecutive.h \
    client.h \
    menubar.h \
    loginclientwindow.h \
    loginadminwindow.h \
    clientwindow.h \
    viewdatianagrafici.h \
    viewtitolistudio.h \
    widgetlaurea.h \
    widgetnewlaurea.h \
    widgetupdatelaurea.h \
    viewimpieghi.h \
    widgetimpiego.h \
    widgetnewimpiego.h \
    viewreti.h \
    widgetutenterete.h \
    viewricerca.h \
    widgetnewricerca.h \
    datiricerca.h \
    widgetutentericerca.h \
    admin.h \
    adminwindow.h \
    controller.h \
    viewgestioneutenti.h \
    widgetchooseplan.h \
    widgetabout.h \
    widgetwelcome.h \
    viewprofilo.h

RESOURCES += \
    resources.qrc
