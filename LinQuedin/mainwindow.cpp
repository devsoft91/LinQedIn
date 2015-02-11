#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linkedin.png"));
    setWindowTitle("LinQedIn");
    setGeometry(250,250,500,400);

    menuBar = new MenuBar(this);
    setMenuBar(menuBar);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

}

MainWindow::~MainWindow()
{

}

//slot
void MainWindow::showLoginClientWindow(){
    //if(centralWidget)
        //delete centralWidget;
    centralWidget = new LoginClientWindow(this);
    setCentralWidget(centralWidget);
}

//slot
void MainWindow::showLoginAdminWindow(){
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
    centralWidget = new ClientWindow(this);
    setCentralWidget(centralWidget);
    statusBar->showMessage("Succesfully logged as Client!");
}

//slot
void MainWindow::loginAdmin(){
    if(centralWidget)
        delete centralWidget;
    //centralWidget = new AdminWindow(this);
    //setCentralWidget(centralWidget);
    statusBar->showMessage("Succesfully logged as Admin!");
}
