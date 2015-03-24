#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent,Client* c) : QTabWidget(parent){
    tmp = c;
    d_anagrafici = new ViewDatiAnagrafici(this,c);
    titoli_studio = new ViewTitoliStudio(this,c);
    impieghi = new ViewImpieghi(this,c);
    rete = new ViewReti(this,c);
    ricerca = new ViewRicerca(this,c);
    addTab(d_anagrafici,"Dati Anagrafici");
    addTab(titoli_studio,"Titoli di Studio");
    addTab(impieghi,"Impieghi");
    addTab(rete,"Collegamenti");
    addTab(ricerca,"Risultati Ricerca");

    connect(this, SIGNAL(signalSaveOn()), parent, SLOT(saveEnabler()));
    connect(this, SIGNAL(signalUpdateRicerca()), ricerca, SLOT(updateWithResearch()));
    connect(this, SIGNAL(signalUpdateViewReti()), rete, SLOT(update()));

}

//slot
void ClientWindow::saveOn(){
    emit signalSaveOn();
}

//slot
void ClientWindow::focusRicerca(){
    setCurrentIndex(4);
    emit signalUpdateRicerca();
}

//slot
void ClientWindow::updateViewReti(){
    emit signalUpdateViewReti();
}
