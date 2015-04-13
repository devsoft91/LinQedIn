#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>
#include <QPushButton>
#include <QKeySequence>
#include <QMessageBox>
#include <QRect>
#include <QCloseEvent>

#include "menubar.h"
#include "loginclientwindow.h"
#include "loginadminwindow.h"
#include "adminwindow.h"
#include "clientwindow.h"
#include "widgetnewricerca.h"
#include "widgetabout.h"
#include "widgetwelcome.h"

#include "admin.h"
#include "client.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMenuBar *menuBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    Admin* admincontroller;
    Client* clientcontroller;
    Controller* controller;

    WidgetAbout* about;
    WidgetNewRicerca* dialog;

    QCloseEvent* close_event;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void disableNewInstance();
    void enableSaveInstance();
    void signalSaveState();
    void signalDiscardState();
    void signalCancelState();
    void signalDisableFind();
    void signalEnableFind();
    void signalAddRicerca();
    void aboutToQuit();

public slots:
    void showLoginClientWindow();
    void showLoginAdminWindow();
    void saveConfirm();
    void saveEnabler();
    void loginClient(const QString&);
    void loginAdmin(const QString&);
    void logout(bool);
    void exit(bool);
    void callFormRicerca();
    void catchMessageToSet(const QString&);
    void showInfo();
    void closeEvent(QCloseEvent*);
};

#endif // MAINWINDOW_H
