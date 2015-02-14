#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linkedin.png"));
    setWindowTitle("LinQedIn");
    setGeometry(200,200,700,500);

    menuBar = new MenuBar(this);
    setMenuBar(menuBar);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    utentecontrol = 0;

    connect(this, SIGNAL(disableNewInstance()), menuBar, SLOT(changeMenuLogin()));
    connect(this, SIGNAL(enableSaveInstance()), menuBar, SLOT(enableSave()));

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
    utentecontrol->saveDatabase();
    statusBar->showMessage("Database succesfully saved!");
}

//slot
void MainWindow::saveEnabler(){
    emit enableSaveInstance();
}

//slot
void MainWindow::loginClient(const QString& s){
    std::cout<<s.toStdString()<<std::endl;
    if(utentecontrol)
        utentecontrol->initialize(s);
    else utentecontrol = new Client(s);
    if(!utentecontrol->u){
        statusBar->showMessage("Errore");
    }
    else{
        centralWidget = new ClientWindow(this,utentecontrol);
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
