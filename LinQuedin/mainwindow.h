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

#include "client.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMenuBar *menuBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    Client* utentecontrol;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void disableNewInstance();
    void enableSaveInstance();

public slots:
    void showLoginClientWindow();
    void showLoginAdminWindow();
    void saveConfirm();
    void saveEnabler();
    void loginClient(const QString&);
    void loginAdmin();
    void logout(bool);

};

#endif // MAINWINDOW_H
