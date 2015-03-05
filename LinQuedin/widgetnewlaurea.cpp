#include "widgetnewlaurea.h"

WidgetNewLaurea::WidgetNewLaurea(QWidget *parent) : QWidget(parent){

    box = new QDialog();
    box->resize(300,100);
    //if(box->testAttribute(Qt::WA_DeleteOnClose)) std::cout<<"ok"<<std::endl;
    //else std::cout<<"male"<<std::endl;
    layout = new QGridLayout(box);
    box->setWindowTitle("Nuova Laurea");
    l_nomelaurea = new QLabel("Nome Laurea");
    l_annolaurea = new QLabel("Anno Laurea");
    nomelaurea = new QLineEdit();
    annolaurea = new QSpinBox();
    annolaurea->setRange(1900,2100);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    aggiungi = new QPushButton("Aggiungi");
    annulla = new QPushButton("Annulla");
    buttonbox->addButton(aggiungi,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
    layout->addWidget(l_nomelaurea,0,0);
    layout->addWidget(l_annolaurea,1,0);
    layout->addWidget(nomelaurea,0,1);
    layout->addWidget(annolaurea,1,1);
    layout->addWidget(buttonbox,2,1);
    box->setLayout(layout);

    connect(aggiungi, SIGNAL(clicked()), this, SLOT(newLaureaReady()));
    connect(annulla, SIGNAL(clicked()), box, SLOT(close()));
    connect(this, SIGNAL(callFetchNewLaurea(QLineEdit*,QSpinBox*)), parent, SLOT(fetchNewLaurea(QLineEdit*,QSpinBox*)));

    box->exec();

}

//slot
void WidgetNewLaurea::newLaureaReady(){
    emit callFetchNewLaurea(nomelaurea,annolaurea);
    box->close();
}
