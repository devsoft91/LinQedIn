#include "adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent,Admin* a) : QTabWidget(parent){
    tmp = a;
    gestioneutenti = new ViewGestioneUtenti(this,a);
    ricerca = new ViewRicerca(this,a);
    addTab(gestioneutenti,"Gestisci Utenti");
    addTab(ricerca,"Risultati Ricerca");

    connect(this, SIGNAL(signalUpdateRicerca()), ricerca, SLOT(updateWithResearch()));
    connect(this, SIGNAL(signalSaveOn()), parent, SLOT(saveEnabler()));
    connect(this, SIGNAL(sendMessageToBar(const QString&)), parent, SLOT(catchMessageToSet(const QString&)));
}

//slot
void AdminWindow::focusRicerca(){
    setCurrentIndex(1);
    emit signalUpdateRicerca();
}

//slot
void AdminWindow::saveOn(){
    emit signalSaveOn();
}

//slot
void AdminWindow::catchMessage(const QString& m){
    emit sendMessageToBar(m);
}
