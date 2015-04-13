#include "viewricerca.h"

bool ViewRicerca::nuovo = true;

ViewRicerca::ViewRicerca(QWidget *parent,Controller* c) : QWidget(parent){

    tmp = c;
    no_ricerca = new QLabel("Nessuna ricerca effettuata");
    no_risultati = new QLabel("Nessun risultato");
    layout = 0;

    updateWithoutResearch();

    nuovo = false;

    if(typeid(*tmp)==typeid(Client)){
        connect(this, SIGNAL(signalUpdateNet()), parent, SLOT(updateViewReti()));
        connect(this, SIGNAL(callSaveOn()), parent, SLOT(saveOn()));
    }
}

//slot
void ViewRicerca::updateWithResearch(){
    map_utenti.clear();
    map_utenti = tmp->returnRicerca();
    updateWithoutResearch();
}

//slot
void ViewRicerca::updateWithoutResearch(){
    if(layout){
        delete layout;
    }
    layout = new QVBoxLayout();
    layout->setMargin(0);

    v_layout = new QVBoxLayout();
    v_layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    scroll_area = new QScrollArea();

    w = new QWidget(scroll_area);

    int size = map_utenti.size();
    if(size != 0){
        map<QString,Utente*>::const_iterator it = map_utenti.begin();
        for(int k=0;k<size;k++){
            QString namesurname((*it).second->getProfilo().getDati().getNome() + " " + (*it).second->getProfilo().getDati().getCognome());
            QString infojob;
            if((*it).second->getProfilo().getImpieghi().impieghi.empty())
                infojob = "Disoccupato";
            else infojob = (*it).second->getProfilo().getImpieghi().impieghi.front().getTitolo() + " - " + (*it).second->getProfilo().getImpieghi().impieghi.front().getAzienda();
            QString username((*it).second->getUsername());
            WidgetUtenteRicerca* widget = new WidgetUtenteRicerca(namesurname,infojob,username,this,tmp);
            v_layout->addWidget(widget);
            ++it;
        }
    }
    else{
        if(nuovo) v_layout->addWidget(no_ricerca);
        else v_layout->addWidget(no_risultati);

        v_layout->setAlignment(Qt::AlignHCenter);
    }

    w->setLayout(v_layout);

    scroll_area->setWidget(w);
    scroll_area->setWidgetResizable(true);

    layout->addWidget(scroll_area);

    setLayout(layout);
}

//slot
void ViewRicerca::updateNet(){
    emit signalUpdateNet();
    emit callSaveOn();
}
