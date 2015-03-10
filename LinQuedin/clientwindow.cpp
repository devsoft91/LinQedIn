#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent,Client* c) : QTabWidget(parent){
    d_anagrafici = new ViewDatiAnagrafici(this,c);
    titoli_studio = new ViewTitoliStudio(this,c);
    impieghi = new ViewImpieghi(this,c);
    rete = new ViewReti(this,c);
    addTab(d_anagrafici,"Dati Anagrafici");
    addTab(titoli_studio,"Titoli di Studio");
    addTab(impieghi,"Impieghi");
    addTab(rete,"Collegamenti");

    connect(this, SIGNAL(signalSaveOn()), parent, SLOT(saveEnabler()));

}

//slot
void ClientWindow::saveOn(){
    emit signalSaveOn();
}
