#include "viewtitolistudio.h"

ViewTitoliStudio::ViewTitoliStudio(QWidget *parent,Client* c) : QWidget(parent){

    tmp = c; nomediploma = 0;

    v_layout = new QVBoxLayout(this);
    lauree_layout = new QVBoxLayout();

    b_diploma = new QGroupBox("Diploma");
    b_lauree = new QGroupBox("Lauree");

    g_layout = new QGridLayout();
    g_layout->setSizeConstraint(QLayout::SetMinimumSize);

    l_nomediploma = new QLabel("Nome Diploma");
    l_annodiploma = new QLabel("Anno Diploma");

    updateView();
}

//slot
void ViewTitoliStudio::updateView(){
    TitoliStudio* titoli = getTitoliStudio(tmp);
    if(nomediploma){
        delete nomediploma;
    }
    nomediploma = new QLineEdit(titoli->getDiploma());
    annodiploma = new QSpinBox();
    annodiploma->setRange(1900,2100);
    annodiploma->setValue(titoli->getAnno());

    g_layout->addWidget(l_nomediploma,0,0);
    g_layout->addWidget(l_annodiploma,1,0);
    g_layout->addWidget(nomediploma,0,1);
    g_layout->addWidget(annodiploma,1,1);

    b_diploma->setLayout(g_layout);

    v_layout->addWidget(b_diploma);
    v_layout->setAlignment(Qt::AlignTop);


    vector_lauree = titoli->getLaurea();
    if(vector_lauree.size()!=0){
        vector<Laurea>::const_iterator it = vector_lauree.begin();
        int k=0;
        for(;it!=vector_lauree.end();++it){
            WidgetLaurea* widget = new WidgetLaurea((*it).getNome(),(*it).getAnno(),k);
            lauree_layout->addWidget(widget);
            list_lauree.push_back(widget);
            ++k;
        }
        b_lauree->setLayout(lauree_layout);

    }

    v_layout->addWidget(b_lauree);
    setLayout(v_layout);
}

TitoliStudio* ViewTitoliStudio::getTitoliStudio(Client* c) const{
    return c->returnTitoliStudio();
}
