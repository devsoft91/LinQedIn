#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linkedin.png"));
    setWindowTitle("LinQedIn");
    setGeometry(250,250,500,400);

    menuBar = new MenuBar(this);
    setMenuBar(menuBar);
/*
    centralWidget = new QWidget(this);

    tabs = new QTabWidget(centralWidget);
    QWidget* a = new QWidget(tabs);
    QWidget* b = new QWidget(tabs);
    //a->resize(250,250);
    tabs->addTab(a,"Pagina 1");
    tabs->addTab(b,"Pagina 2");
    setCentralWidget(centralWidget);*/
    //setTabOrder(a,b);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    utente = 0;

    connect(this, SIGNAL(disableNewInstance()), menuBar, SLOT(changeMenuLogin()));

}

MainWindow::~MainWindow()
{

}

//slot
void MainWindow::showLoginClientWindow(){
    centralWidget = new LoginClientWindow(this);
    setCentralWidget(centralWidget);
}

//slot
void MainWindow::showLoginAdminWindow(){
    centralWidget = new LoginAdminWindow(this);
    setCentralWidget(centralWidget);
}

//slot
void MainWindow::saveConfirm(){
    statusBar->showMessage("Database succesfully saved!");
}

//slot
void MainWindow::loginClient(const QString& s){
    std::cout<<s.toStdString()<<std::endl;
    if(utente)
        utente->initialize(s);
    else utente = new Client(s);
    if(!utente->u){
        statusBar->showMessage("Errore");
    }
    else{
        centralWidget = new ClientWindow(this);
        setCentralWidget(centralWidget);
        statusBar->showMessage("Succesfully logged as Client!");
        QString title = "LinQedIn - " + s;
        setWindowTitle(title);
        emit disableNewInstance();
    }
}

//slot
void MainWindow::loginAdmin(){
    //centralWidget = new AdminWindow(this);
    //setCentralWidget(centralWidget);
    statusBar->showMessage("Succesfully logged as Admin!");
}

//slot
void MainWindow::logout(){
    if(true/*save enabled*/){
        QMessageBox box;
        box.setWindowTitle("Attention");
        box.setText("Exit without saving?");
        box.setIcon(QMessageBox::Question);
        box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        int choose = box.exec();
        switch(choose){
            case QMessageBox::Save:
                saveConfirm();
                break;
            case QMessageBox::Discard:
                //exit without saving
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }
    }

}
