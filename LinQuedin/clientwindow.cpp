#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent,Client* c) : QTabWidget(parent){
    d_anagrafici = new ViewDatiAnagrafici(this,c);
    titoli_studio = new ViewTitoliStudio(this,c);
    rete = new QWidget(this);
    addTab(d_anagrafici,"Dati Anagrafici");
    addTab(titoli_studio,"Titoli di Studio");
    addTab(rete,"Collegamenti");

    connect(this, SIGNAL(signalSaveOn()), parent, SLOT(saveEnabler()));

}

//slot
void ClientWindow::saveOn(){
    emit signalSaveOn();
}
