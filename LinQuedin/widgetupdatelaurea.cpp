#include "widgetupdatelaurea.h"

WidgetUpdateLaurea::WidgetUpdateLaurea(const QString& l,int s,WidgetLaurea* laurea,QWidget *parent) : QWidget(parent){

    tmp_laurea = laurea;

    box = new QDialog();
    box->resize(300,100);
    layout = new QGridLayout(box);
    box->setWindowTitle("Aggiorna Laurea");
    l_nomelaurea = new QLabel("Nome Laurea");
    l_annolaurea = new QLabel("Anno Laurea");
    nomelaurea = new QLineEdit(l);
    annolaurea = new QSpinBox();
    annolaurea->setRange(1900,2100);
    annolaurea->setValue(s);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    conferma = new QPushButton("Conferma");
    annulla = new QPushButton("Annulla");
    buttonbox->addButton(conferma,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
    layout->addWidget(l_nomelaurea,0,0);
    layout->addWidget(l_annolaurea,1,0);
    layout->addWidget(nomelaurea,0,1);
    layout->addWidget(annolaurea,1,1);
    layout->addWidget(buttonbox,2,1);
    box->setLayout(layout);

    connect(conferma, SIGNAL(clicked()), this, SLOT(updateLaureaReady()));
    connect(annulla, SIGNAL(clicked()), box, SLOT(close()));
    connect(this, SIGNAL(callFetchUpdateLaurea(WidgetLaurea*,QLineEdit*,QSpinBox*)), parent, SLOT(fetchUpdateLaurea(WidgetLaurea*,QLineEdit*,QSpinBox*)));

    box->exec();

}

//slot
void WidgetUpdateLaurea::updateLaureaReady(){
    emit callFetchUpdateLaurea(tmp_laurea,nomelaurea,annolaurea);
    box->close();
}
