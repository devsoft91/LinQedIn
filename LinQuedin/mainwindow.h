#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QKeySequence>
#include <QAction>

#include "menubar.h"
#include "loginclientwindow.h"
#include "loginadminwindow.h"
#include "clientwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QMenuBar *menuBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:
    void showLoginClientWindow();
    void showLoginAdminWindow();
    void saveConfirm();
    void loginClient();
    void loginAdmin();

};

#endif // MAINWINDOW_H
