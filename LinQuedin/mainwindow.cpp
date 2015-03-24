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

    connect(this, SIGNAL(disableNewInstance()), menuBar, SLOT(disableMenuLogin()));
    connect(this, SIGNAL(enableSaveInstance()), menuBar, SLOT(enableSave()));
    connect(this, SIGNAL(signalSaveState()), menuBar, SLOT(enableMenuLogin()));
    connect(this, SIGNAL(signalDiscardState()), menuBar, SLOT(enableMenuLogin()));
    connect(this, SIGNAL(signalCancelState()), menuBar, SLOT(cancelState()));
    connect(this, SIGNAL(signalDisableFind()), menuBar, SLOT(disableFind()));
    connect(this, SIGNAL(signalEnableFind()), menuBar, SLOT(enableFind()));

}

MainWindow::~MainWindow(){
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
    statusBar->showMessage("Database succesfully saved!",3000);
}

//slot
void MainWindow::saveEnabler(){
    emit enableSaveInstance();
}

//slot
void MainWindow::loginClient(const QString& s){
    if(utentecontrol)
        utentecontrol->initialize(s);
    else utentecontrol = new Client(s);
    if(!utentecontrol->u){
        statusBar->showMessage("Errore");
    }
    else{
        centralWidget = new ClientWindow(this,utentecontrol);
        setCentralWidget(centralWidget);
        statusBar->showMessage("Succesfully logged as Client!",5000);
        QString title = "LinQedIn - " + s;
        setWindowTitle(title);
        emit disableNewInstance();
        emit signalEnableFind();
    }
}

//slot
void MainWindow::loginAdmin(){
    //centralWidget = new AdminWindow(this);
    //setCentralWidget(centralWidget);
    statusBar->showMessage("Succesfully logged as Admin!");
}

//slot
void MainWindow::logout(bool b){
    if(b){
        QMessageBox box;
        box.setWindowTitle("Attention");
        box.setText("Exit without saving?");
        box.setIcon(QMessageBox::Question);
        box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        int choose = box.exec();
        switch(choose){
            case QMessageBox::Save:
                saveConfirm();
                delete centralWidget;
                delete utentecontrol;
                utentecontrol = 0;
                statusBar->showMessage("Succesfully logged out!",3000);
                setWindowTitle("LinQedIn");
                emit signalSaveState();
                emit signalDisableFind();
                break;
            case QMessageBox::Discard:
                delete centralWidget;
                delete utentecontrol;
                utentecontrol = 0;
                statusBar->showMessage("Succesfully logged out!",3000);
                setWindowTitle("LinQedIn");
                emit signalDiscardState();
                emit signalDisableFind();
                break;
            case QMessageBox::Cancel:
                emit signalCancelState();
                break;
            default:
                break;
        }
    }
    else{
        delete centralWidget;
        delete utentecontrol;
        utentecontrol = 0;
        statusBar->showMessage("Succesfully logged out!",3000);
        setWindowTitle("LinQedIn");
        emit signalDiscardState();
        emit signalDisableFind();
    }

}

//slot
void MainWindow::callFormRicerca(){

    dialog = new WidgetNewRicerca(centralWidget,utentecontrol);

}
