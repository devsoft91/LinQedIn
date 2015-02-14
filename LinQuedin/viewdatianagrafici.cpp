#include "viewdatianagrafici.h"

ViewDatiAnagrafici::ViewDatiAnagrafici(QWidget *parent,Client* c) : QWidget(parent),tmp(c){

    DAnagrafici* dati = getDatiAnagrafici(tmp);
    gridlayout = new QGridLayout(this);
    nome = new QLineEdit(dati->getNome());
    cognome = new QLineEdit(dati->getCognome());
    email = new QLineEdit(dati->getEmail());
    datanascita = new QDateEdit(dati->getData_nascita());
    luogonascita = new QLineEdit(dati->getLuogo_nascita());
    luogoresidenza = new QLineEdit(dati->getLuogo_residenza());
    l_nome = new QLabel("Nome");
    l_cognome = new QLabel("Cognome");
    l_email = new QLabel("Email");
    l_datanascita = new QLabel("Data di nascita");
    l_luogonascita = new QLabel("Luogo di nascita");
    l_luogoresidenza = new QLabel("Luogo di residenza");

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    confirm = new QPushButton("Applica");
    discard = new QPushButton("Annulla");
    buttonbox->addButton(confirm,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(discard,QDialogButtonBox::RejectRole);
    //buttonbox->setCenterButtons(true);

    gridlayout->addWidget(l_nome,0,0);
    gridlayout->addWidget(l_cognome,1,0);
    gridlayout->addWidget(l_email,2,0);
    gridlayout->addWidget(l_datanascita,3,0);
    gridlayout->addWidget(l_luogonascita,4,0);
    gridlayout->addWidget(l_luogoresidenza,5,0);
    gridlayout->addWidget(nome,0,1);
    gridlayout->addWidget(cognome,1,1);
    gridlayout->addWidget(email,2,1);
    gridlayout->addWidget(datanascita,3,1);
    gridlayout->addWidget(luogonascita,4,1);
    gridlayout->addWidget(luogoresidenza,5,1);
    gridlayout->addWidget(buttonbox,6,1);


    setLayout(gridlayout);

    delete dati;

    connect(confirm, SIGNAL(clicked()), this, SLOT(update()));
    connect(this, SIGNAL(signalUpdate()), parent, SLOT(saveOn()));

}

DAnagrafici* ViewDatiAnagrafici::getDatiAnagrafici(Client* c) const{
    return c->returnDatiAnagrafici();
}

void ViewDatiAnagrafici::setDatiAnagrafici(){
    DAnagrafici dati(nome->text(),cognome->text(),email->text(),datanascita->date(),luogonascita->text(),luogoresidenza->text());
    tmp->sendDatiAnagrafici(dati);
}

//slot
void ViewDatiAnagrafici::update(){
    setDatiAnagrafici();
    emit signalUpdate();
}
