#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linQedin.png"));
    setWindowTitle("LinQedIn");
    setGeometry(0,0,700,500);

    menuBar = new MenuBar(this);
    setMenuBar(menuBar);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    centralWidget = new WidgetWelcome(this);
    setCentralWidget(centralWidget);

    admincontroller = 0;
    clientcontroller = 0;
    controller = 0;

    connect(this, SIGNAL(disableNewInstance()), menuBar, SLOT(disableMenuLogin()));
    connect(this, SIGNAL(enableSaveInstance()), menuBar, SLOT(enableSave()));
    connect(this, SIGNAL(signalSaveState()), menuBar, SLOT(enableMenuLogin()));
    connect(this, SIGNAL(signalDiscardState()), menuBar, SLOT(enableMenuLogin()));
    connect(this, SIGNAL(signalCancelState()), menuBar, SLOT(cancelState()));
    connect(this, SIGNAL(signalDisableFind()), menuBar, SLOT(disableFind()));
    connect(this, SIGNAL(signalEnableFind()), menuBar, SLOT(enableFind()));
    connect(this ,SIGNAL(aboutToQuit()), menuBar ,SLOT(triggeredClose()));

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
    controller->saveDatabase();
    statusBar->showMessage("Database succesfully saved!",3000);
}

//slot
void MainWindow::saveEnabler(){
    emit enableSaveInstance();
}

//slot
void MainWindow::loginClient(const QString& s){
    if(clientcontroller){
        delete controller;
        controller = 0;
    }
    clientcontroller = new Client(s);
    controller = clientcontroller;
    if(!clientcontroller->u){
        statusBar->showMessage("Errore");
    }
    else{
        centralWidget = new ClientWindow(this,clientcontroller);
        setCentralWidget(centralWidget);
        statusBar->showMessage("Succesfully logged as Client!",5000);
        QString title = "LinQedIn - " + s;
        setWindowTitle(title);
        emit disableNewInstance();
        emit signalEnableFind();
    }
}

//slot
void MainWindow::loginAdmin(const QString& s){
    if(admincontroller){
        delete controller;
        controller = 0;
    }
    admincontroller = new Admin(s);
    controller = admincontroller;
    if(admincontroller->data_==0){
        statusBar->showMessage("Errore");
    }
    else{
        centralWidget = new AdminWindow(this,admincontroller);
        setCentralWidget(centralWidget);
        statusBar->showMessage("Succesfully logged as Admin!",5000);
        setWindowTitle("LinQedIn - Admin");
        emit disableNewInstance();
        emit signalEnableFind();
    }
}

//slot
void MainWindow::logout(bool b){
    if(b){
        QMessageBox box;
        box.setWindowTitle("Attention");
        box.setText("Logout without saving?");
        box.setIcon(QMessageBox::Question);
        box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        int choose = box.exec();
        switch(choose){
            case QMessageBox::Save:
                saveConfirm();
                delete centralWidget;
                centralWidget = new WidgetWelcome(this);
                setCentralWidget(centralWidget);
                delete controller;
                controller = 0;
                statusBar->showMessage("Succesfully logged out!",3000);
                setWindowTitle("LinQedIn");
                ViewRicerca::nuovo = true;
                emit signalSaveState();
                emit signalDisableFind();
                break;
            case QMessageBox::Discard:
                delete centralWidget;
                centralWidget = new WidgetWelcome(this);
                setCentralWidget(centralWidget);
                delete controller;
                controller = 0;
                statusBar->showMessage("Succesfully logged out!",3000);
                setWindowTitle("LinQedIn");
                ViewRicerca::nuovo = true;
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
        centralWidget = new WidgetWelcome(this);
        setCentralWidget(centralWidget);
        delete controller;
        controller = 0;

        statusBar->showMessage("Succesfully logged out!",3000);
        setWindowTitle("LinQedIn");
        emit signalDiscardState();
        emit signalDisableFind();
        ViewRicerca::nuovo = true;
    }

}

//slot
void MainWindow::exit(bool b){
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
                close_event->accept();
                break;
            case QMessageBox::Discard:
                close_event->accept();
                break;
            case QMessageBox::Cancel:
                emit signalCancelState();
                close_event->ignore();
                break;
            default:
                break;
        }
    }
    else close();
}

//slot
void MainWindow::callFormRicerca(){

    dialog = new WidgetNewRicerca(centralWidget,controller);

}

//slot
void MainWindow::catchMessageToSet(const QString& m){
    statusBar->showMessage(m,5000);
}

//slot
void MainWindow::showInfo(){
    about = new WidgetAbout(this);
}

//slot
void MainWindow::closeEvent(QCloseEvent* e){
    close_event = e;
    emit aboutToQuit();
}
