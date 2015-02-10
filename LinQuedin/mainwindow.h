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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QMenuBar *menuBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H
