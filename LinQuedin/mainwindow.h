#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
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
    Client* utente;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void disableNewInstance();

public slots:
    void showLoginClientWindow();
    void showLoginAdminWindow();
    void saveConfirm();
    void loginClient(const QString&);
    void loginAdmin();
    void logout();

};

#endif // MAINWINDOW_H
