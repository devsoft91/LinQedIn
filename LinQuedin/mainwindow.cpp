#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linkedin.png"));
    setWindowTitle("LinQedIn");
    setGeometry(250,250,500,400);

    menuBar = new MenuBar(this);
    setMenuBar(menuBar);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    //connect(action_save, SIGNAL(triggered()), this, SLOT(close()));
    //connect(action_close, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}

//slot
void MainWindow::showLoginClient(){
    if(centralWidget)
        delete centralWidget;
    centralWidget = new LoginClientWindow(this);
    setCentralWidget(centralWidget);
}

//slot
void MainWindow::showLoginAdmin(){
    if(centralWidget)
        delete centralWidget;
    centralWidget = new LoginAdminWindow(this);
    setCentralWidget(centralWidget);
}

//slot
void MainWindow::saveConfirm(){
    statusBar->showMessage("Database succesfully saved!");
}

//slot
void MainWindow::loginClient(){
    if(centralWidget)
        delete centralWidget;
    statusBar->showMessage("Succesfully logged as Client!");
}

//slot
void MainWindow::loginAdmin(){
    if(centralWidget)
        delete centralWidget;
    statusBar->showMessage("Succesfully logged as Admin!");
}
