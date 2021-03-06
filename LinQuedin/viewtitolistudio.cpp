#include "viewtitolistudio.h"

ViewTitoliStudio::ViewTitoliStudio(QWidget *parent,Client* c) : QWidget(parent){

    tmp = c; nomediploma = 0; b_diploma = 0; b_lauree = 0;

    v_layout = new QVBoxLayout(this);

    updateView();

    connect(this, SIGNAL(callSaveOn()), parent, SLOT(saveOn()));

}

//slot
void ViewTitoliStudio::updateView(){

    lauree_layout = new QVBoxLayout();

    if(b_diploma!=0){
        v_layout->removeWidget(b_diploma);
        v_layout->removeWidget(b_lauree);
        delete b_diploma; delete b_lauree;
    }

    b_diploma = new QGroupBox("Diploma");
    b_lauree = new QGroupBox("Lauree");

    g_layout = new QGridLayout();

    l_nomediploma = new QLabel("Nome Diploma");
    l_annodiploma = new QLabel("Anno Diploma");
    buttonbox = new QDialogButtonBox(Qt::Horizontal);
    modifica = new QPushButton("Modifica"); modifica->setDisabled(true);
    annulla = new QPushButton("Annulla"); annulla->setDisabled(true);
    buttonbox->addButton(modifica,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);

    addLaurea = new QPushButton("Aggiungi Laurea");

    TitoliStudio* titoli = getTitoliStudio(tmp);

    nomediploma = new QLineEdit(titoli->getDiploma());
    annodiploma = new QSpinBox();
    annodiploma->setRange(1900,2100);
    annodiploma->setValue(titoli->getAnno());
    tmp_nomediploma = new QLineEdit(titoli->getDiploma());
    tmp_annodiploma = new QSpinBox();
    tmp_annodiploma->setRange(1900,2100);
    tmp_annodiploma->setValue(titoli->getAnno());

    g_layout->addWidget(l_nomediploma,0,0);
    g_layout->addWidget(l_annodiploma,1,0);
    g_layout->addWidget(nomediploma,0,1);
    g_layout->addWidget(annodiploma,1,1);
    g_layout->addWidget(buttonbox,2,1);

    b_diploma->setLayout(g_layout);

    v_layout->setAlignment(Qt::AlignTop);
    v_layout->addWidget(b_diploma);

    vector_lauree.clear();
    vector_lauree = titoli->getLauree();
    int size = vector_lauree.size();
    if(size != 0){
        vector<Laurea>::const_iterator it = vector_lauree.begin();
        for(int k=0;k<size;k++){
            WidgetLaurea* widget = new WidgetLaurea((*it).getNome(),(*it).getAnno(),this);
            lauree_layout->addWidget(widget);
            ++it;
        }
    }
    lauree_layout->addWidget(addLaurea);

    b_lauree->setLayout(lauree_layout);

    v_layout->addWidget(b_lauree);

    setLayout(v_layout);

    delete titoli;

    connect(addLaurea, SIGNAL(clicked()), this, SLOT(addLBox()));

    connect(modifica, SIGNAL(clicked()), this, SLOT(disableUpdate()));
    connect(modifica, SIGNAL(clicked()), this, SLOT(updateDiploma()));    
    connect(annulla, SIGNAL(clicked()), this, SLOT(backData()));
    connect(annulla, SIGNAL(clicked()), this, SLOT(disableUpdate()));
    connect(nomediploma, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(annodiploma, SIGNAL(valueChanged(int)), this, SLOT(enableUpdate(int)));
}

TitoliStudio* ViewTitoliStudio::getTitoliStudio(Client* c) const{
    return c->returnTitoliStudio();
}

void ViewTitoliStudio::setDiploma(){
    tmp_nomediploma->setText(nomediploma->text());
    tmp_annodiploma->setValue(annodiploma->text().toInt());
    tmp->sendDiploma(nomediploma->text(),annodiploma->text().toInt());
}

//slot
void ViewTitoliStudio::addLBox(){
    dialog1 = new WidgetNewLaurea(this);
}

//slot
void ViewTitoliStudio::addUBox(const QString& l,int s,WidgetLaurea* wl){

    dialog2 = new WidgetUpdateLaurea(l,s,wl,this);

}

//slot
void ViewTitoliStudio::fetchNewLaurea(QLineEdit* e,QSpinBox* b){
    Laurea l(e->text(),b->text().toInt());
    tmp->sendLaurea(l);
    updateView();
    emit callSaveOn();
}

//slot
void ViewTitoliStudio::fetchUpdateLaurea(WidgetLaurea* w,QLineEdit* e,QSpinBox* b){  //attenzione modificare non aggiungere
    Laurea l(e->text(),b->text().toInt());
    tmp->sendLaurea(w->nomelaurea->text(),l);
    updateView();
    emit callSaveOn();
}

//slot
void ViewTitoliStudio::updateAfterRemove(WidgetLaurea* w){
    lauree_layout->removeWidget(w);
    tmp->u->getProfilo().removeLaurea(w->nomelaurea->text());
    delete w;
    emit callSaveOn();
}

//slot
void ViewTitoliStudio::updateDiploma(){
    setDiploma();
    emit callSaveOn();
}

//slot
void ViewTitoliStudio::disableUpdate(){
    modifica->setDisabled(true);
    annulla->setDisabled(true);
}

//slot
void ViewTitoliStudio::backData(){
    nomediploma->setText(tmp_nomediploma->text());
    annodiploma->setValue(tmp_annodiploma->text().toInt());
}

//slot
void ViewTitoliStudio::enableUpdate(const QString&){
    modifica->setDisabled(false);
    annulla->setDisabled(false);
}

void ViewTitoliStudio::enableUpdate(int){
    modifica->setDisabled(false);
    annulla->setDisabled(false);
}
