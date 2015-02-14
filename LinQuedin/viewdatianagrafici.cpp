#include "viewdatianagrafici.h"

ViewDatiAnagrafici::ViewDatiAnagrafici(QWidget *parent,Client* c) : QWidget(parent),tmp(c),nome(0){

    gridlayout = new QGridLayout(this);

    l_nome = new QLabel("Nome");
    l_cognome = new QLabel("Cognome");
    l_email = new QLabel("Email");
    l_datanascita = new QLabel("Data di nascita");
    l_luogonascita = new QLabel("Luogo di nascita");
    l_luogoresidenza = new QLabel("Luogo di residenza");

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    confirm = new QPushButton("Applica"); confirm->setDisabled(true);
    discard = new QPushButton("Annulla"); discard->setDisabled(true);
    buttonbox->addButton(confirm,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(discard,QDialogButtonBox::RejectRole);

    gridlayout->addWidget(l_nome,0,0);
    gridlayout->addWidget(l_cognome,1,0);
    gridlayout->addWidget(l_email,2,0);
    gridlayout->addWidget(l_datanascita,3,0);
    gridlayout->addWidget(l_luogonascita,4,0);
    gridlayout->addWidget(l_luogoresidenza,5,0);
    gridlayout->addWidget(buttonbox,6,1);

    fillFields();

    connect(confirm, SIGNAL(clicked()), this, SLOT(update()));
    connect(confirm, SIGNAL(clicked()), this, SLOT(disableUpdate()));
    connect(discard, SIGNAL(clicked()), this, SLOT(fillFields()));
    connect(discard, SIGNAL(clicked()), this, SLOT(disableUpdate()));
    connect(this, SIGNAL(signalUpdate()), parent, SLOT(saveOn()));



}

DAnagrafici* ViewDatiAnagrafici::getDatiAnagrafici(Client* c) const{
    return c->returnDatiAnagrafici();
}

//slot
void ViewDatiAnagrafici::fillFields(){
    DAnagrafici* dati = getDatiAnagrafici(tmp);
    if(nome){
        delete nome; delete cognome; delete email; delete datanascita, delete luogonascita, delete luogoresidenza;
    }
    nome = new QLineEdit(dati->getNome());
    cognome = new QLineEdit(dati->getCognome());
    email = new QLineEdit(dati->getEmail());
    datanascita = new QDateEdit(dati->getData_nascita());
    luogonascita = new QLineEdit(dati->getLuogo_nascita());
    luogoresidenza = new QLineEdit(dati->getLuogo_residenza());
    gridlayout->addWidget(nome,0,1);
    gridlayout->addWidget(cognome,1,1);
    gridlayout->addWidget(email,2,1);
    gridlayout->addWidget(datanascita,3,1);
    gridlayout->addWidget(luogonascita,4,1);
    gridlayout->addWidget(luogoresidenza,5,1);
    delete dati;
    setLayout(gridlayout);

    connect(nome, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(cognome, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(email, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(datanascita, SIGNAL(dateChanged(const QDate&)), this, SLOT(enableUpdate(const QDate&)));
    connect(luogonascita, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(luogoresidenza, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
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

//slot
void ViewDatiAnagrafici::disableUpdate(){
    confirm->setDisabled(true);
    discard->setDisabled(true);
}

//slot
void ViewDatiAnagrafici::enableUpdate(const QString& s){
    confirm->setDisabled(false);
    discard->setDisabled(false);
}

//slot
void ViewDatiAnagrafici::enableUpdate(const QDate& d){
    confirm->setDisabled(false);
}
