#include "widgetutentericerca.h"

WidgetUtenteRicerca::WidgetUtenteRicerca(const QString& a,const QString& b,const QString& u,QWidget *parent,Controller *c) : QWidget(parent),username(u){

    tmp = c; username = u;

    out_layout = new QVBoxLayout();

    box_esterna = new QGroupBox("Utente");

    g_layout = new QGridLayout();

    sx_layout = new QVBoxLayout();

    if(typeid(*tmp)==typeid(Admin)){
        QString stringa = a + " - (" + u + ")";
        nome = new QLabel(stringa);
    }
    else nome = new QLabel(a);

    QFont font; font.setPointSize(20);
    nome->setFont(font);
    dettaglio = new QLabel(b);

    sx_layout->addWidget(nome);
    sx_layout->addWidget(dettaglio);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    visualizza = new QPushButton("Visualizza Profilo");
    aggiungi = new QPushButton("Aggiungi alla Rete");
    if(typeid(*tmp)==typeid(Client))
        if(!(tmp->isFriendOf(u)))
            buttonbox->addButton(aggiungi,QDialogButtonBox::ActionRole);
    buttonbox->addButton(visualizza,QDialogButtonBox::AcceptRole);

    g_layout->addLayout(sx_layout,0,0);
    g_layout->addWidget(buttonbox,0,1);

    box_esterna->setLayout(g_layout);
    out_layout->addWidget(box_esterna);
    setLayout(out_layout);

    connect(aggiungi, SIGNAL(clicked()), this, SLOT(sendAddRicerca()));
    connect(this, SIGNAL(signalUpdateNet()), parent, SLOT(updateNet()));
    connect(visualizza, SIGNAL(clicked()), this, SLOT(viewProfilo()));
}

//slot
void WidgetUtenteRicerca::sendAddRicerca(){
    buttonbox->removeButton(aggiungi);
    tmp->addToNet(username);
    emit signalUpdateNet();
}

//slot
void WidgetUtenteRicerca::viewProfilo(){
    profilo = new ViewProfilo(this,username,tmp);
}
