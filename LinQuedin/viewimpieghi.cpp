#include "viewimpieghi.h"

ViewImpieghi::ViewImpieghi(QWidget *parent,Client* c) : QWidget(parent){

    tmp = c;

    updateView();

    connect(this, SIGNAL(callSaveOn()), parent, SLOT(saveOn()));

}

//slot
void ViewImpieghi::updateView(){

    Impieghi* impieghi = getImpieghi(tmp);

    layout = new QVBoxLayout();

    v_layout = new QVBoxLayout();
    v_layout->setAlignment(Qt::AlignTop);

    scroll_area = new QScrollArea(this);

    w = new QWidget(scroll_area);

    addImpiego = new QPushButton("Aggiungi Impiego");

    vector_impieghi.clear();
    vector_impieghi = impieghi->getLavoro();
    int size = vector_impieghi.size();
    if(size != 0){
        vector<Lavoro>::const_iterator it = vector_impieghi.begin();
        for(int k=0;k<size;k++){
            WidgetImpiego* widget = new WidgetImpiego((*it).getTitolo(),(*it).getAzienda(),(*it).getCitta(),(*it).getInizio(),(*it).getFine(),this);
            v_layout->addWidget(widget);
            ++it;
        }
    }
    v_layout->addWidget(addImpiego);

    w->setLayout(v_layout);

    scroll_area->setWidget(w);
    scroll_area->setWidgetResizable(true);

    layout->addWidget(scroll_area);

    setLayout(layout);

    delete impieghi;

    connect(addImpiego, SIGNAL(clicked()), this, SLOT(addIBox()));

}

Impieghi* ViewImpieghi::getImpieghi(Client* c) const{
    return c->returnImpieghi();
}

//slot
void ViewImpieghi::addIBox(){
    dialog = new WidgetNewImpiego(this);
}

//slot
void ViewImpieghi::fetchNewImpiego(QLineEdit* a,QLineEdit* b,QLineEdit* c,QDateEdit* d,QDateEdit* e){
    Lavoro l(a->text(),b->text(),c->text(),d->date(),e->date());
    tmp->sendLavoro(l);
    delete layout;
    updateView();
    emit callSaveOn();
}

//slot
void ViewImpieghi::updateAfterRemove(WidgetImpiego* w){
    v_layout->removeWidget(w);
    Lavoro l(w->titolo->text(),w->azienda->text(),w->citta->text(),w->inizio->date(),w->fine->date());
    tmp->u->profile.removeImpiego(l);
    delete w;
    emit callSaveOn();
}

//slot
void ViewImpieghi::updateAfterUpdate(WidgetImpiego* w,const QString& a,const QString& b,const QString& c,const QDate& d,const QDate& e){
    Lavoro l(w->titolo->text(),w->azienda->text(),w->citta->text(),w->inizio->date(),w->fine->date());
    Lavoro old(a,b,c,d,e);
    tmp->u->profile.updateImpiego(l,old);
    emit callSaveOn();
}


