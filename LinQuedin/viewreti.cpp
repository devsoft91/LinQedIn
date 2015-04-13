#include "viewreti.h"

ViewReti::ViewReti(QWidget* parent, Client* c) : QWidget(parent){

    tmp = c;
    layout = 0;

    update();

    connect(this, SIGNAL(callSaveOn()), parent, SLOT(saveOn()));
}

//slot
void ViewReti::update(){
    if(layout){
        delete empty;
        delete v_layout;
        delete w;
        delete scroll_area;
        delete layout;
    }

    empty = new QLabel("Nessun Collegamento");

    layout = new QVBoxLayout();
    layout->setMargin(0);

    scroll_area = new QScrollArea();

    w = new QWidget();

    v_layout = new QVBoxLayout();
    v_layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    map_rete.clear();
    map_rete = tmp->returnRete();
    int size = map_rete.size();
    if(size != 0){
        map<QString,Nodo>::const_iterator it = map_rete.begin();
        for(int k=0;k<size;k++){
            QString namesurname((*it).second.getUtente()->getProfilo().getDati().getNome() + " " + (*it).second.getUtente()->getProfilo().getDati().getCognome());
            QString infojob;
            if((*it).second.getUtente()->getProfilo().getImpieghi().getLavori().empty())
                infojob = "Disoccupato";
            else infojob = (*it).second.getUtente()->getProfilo().getImpieghi().getLavori().front().getTitolo() + " - " + (*it).second.getUtente()->getProfilo().getImpieghi().getLavori().front().getAzienda();
            QString username((*it).second.getUtente()->getUsername());
            WidgetUtenteRete* widget = new WidgetUtenteRete(namesurname,infojob,username,this,tmp);
            v_layout->addWidget(widget);
            ++it;
        }
    }
    else{
        v_layout->addWidget(empty);
        v_layout->setAlignment(Qt::AlignHCenter);
    }

    w->setLayout(v_layout);

    scroll_area->setWidget(w);
    scroll_area->setWidgetResizable(true);

    layout->addWidget(scroll_area);

    setLayout(layout);

}

//slot
void ViewReti::updateAfterRemove(WidgetUtenteRete* widget){

    map_rete.clear();
    map_rete = tmp->returnRete();
    //map<QString,Nodo>::const_iterator it = map_rete.find(w->username);

    Client* tmp1 = new Client(widget->username,tmp->data_);

    tmp1->removeFromNet(tmp->u->getUsername());
    tmp->removeFromNet(tmp1->u->getUsername());

    update();

    delete tmp1;

    emit callSaveOn();

}
