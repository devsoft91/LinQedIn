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

#include "menubar.h"
#include "loginclientwindow.h"
#include "loginadminwindow.h"
#include "clientwindow.h"
#include "widgetnewricerca.h"

#include "client.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMenuBar *menuBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    Client* utentecontrol;

    WidgetNewRicerca* dialog;

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

public slots:
    void showLoginClientWindow();
    void showLoginAdminWindow();
    void saveConfirm();
    void saveEnabler();
    void loginClient(const QString&);
    void loginAdmin();
    void logout(bool);
    void callFormRicerca();

};

#endif // MAINWINDOW_H
