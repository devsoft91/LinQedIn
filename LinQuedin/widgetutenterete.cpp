#include "widgetutenterete.h"

WidgetUtenteRete::WidgetUtenteRete(const QString& a,const QString& b,const QString& u,QWidget *parent,Client* c) : QWidget(parent),username(u){

    tmp = c;

    out_layout = new QVBoxLayout();

    box_esterna = new QGroupBox("Utente");

    g_layout = new QGridLayout();

    sx_layout = new QVBoxLayout();

    nome = new QLabel(a);
    QFont font; font.setPointSize(20);
    nome->setFont(font);
    dettaglio = new QLabel(b);

    sx_layout->addWidget(nome);
    sx_layout->addWidget(dettaglio);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    visualizza = new QPushButton("Visualizza Profilo");
    elimina = new QPushButton("Elimina dalla Rete");
    buttonbox->addButton(visualizza,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(elimina,QDialogButtonBox::RejectRole);

    g_layout->addLayout(sx_layout,0,0);
    g_layout->addWidget(buttonbox,0,1);

    box_esterna->setLayout(g_layout);
    out_layout->addWidget(box_esterna);
    setLayout(out_layout);

    connect(elimina, SIGNAL(clicked()), this, SLOT(sendRemoveId()));
    connect(this, SIGNAL(signalRemoveId(WidgetUtenteRete*)), parent, SLOT(updateAfterRemove(WidgetUtenteRete*)));
    connect(visualizza, SIGNAL(clicked()), this, SLOT(viewProfilo()));
}

//slot
void WidgetUtenteRete::sendRemoveId(){
    emit signalRemoveId(this);
}

//slot
void WidgetUtenteRete::viewProfilo(){
    profilo = new ViewProfilo(this,username,tmp);
}
