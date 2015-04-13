#include "widgetlaurea.h"

WidgetLaurea::WidgetLaurea(const QString& s, const int& i, QWidget *parent) : QWidget(parent){

    g_layout = new QGridLayout(this);

    l_nomelaurea = new QLabel("Nome Laurea");
    l_annolaurea = new QLabel("Anno Laurea");

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    aggiorna = new QPushButton("Aggiorna");
    elimina = new QPushButton("Elimina");
    buttonbox->addButton(aggiorna,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(elimina,QDialogButtonBox::RejectRole);

    nomelaurea = new QLineEdit(s); nomelaurea->setReadOnly(true); nomelaurea->setFrame(false);
    annolaurea = new QLineEdit(QString::number(i)); annolaurea->setReadOnly(true); annolaurea->setFrame(false);

    g_layout->addWidget(l_nomelaurea,0,0);
    g_layout->addWidget(l_annolaurea,1,0);
    g_layout->addWidget(nomelaurea,0,1);
    g_layout->addWidget(annolaurea,1,1);
    g_layout->addWidget(buttonbox,2,1);

    setLayout(g_layout);

    connect(elimina, SIGNAL(clicked()), this, SLOT(sendRemoveId()));
    connect(this, SIGNAL(signalRemoveId(WidgetLaurea*)), parent, SLOT(updateAfterRemove(WidgetLaurea*)));
    connect(aggiorna, SIGNAL(clicked()), this, SLOT(sendUpdateId()));
    connect(this, SIGNAL(signalUpdateId(const QString&,int,WidgetLaurea*)), parent, SLOT(addUBox(const QString&,int,WidgetLaurea*)));

}

WidgetLaurea::~WidgetLaurea(){
    delete nomelaurea;
    delete annolaurea;
    delete l_nomelaurea;
    delete l_annolaurea;
    delete aggiorna;
    delete elimina;
    delete buttonbox;
    delete g_layout;
}

//slot
void WidgetLaurea::sendRemoveId(){
    emit signalRemoveId(this);
}

//slot
void WidgetLaurea::sendUpdateId(){
    emit signalUpdateId(nomelaurea->text(),annolaurea->text().toInt(),this);
}


