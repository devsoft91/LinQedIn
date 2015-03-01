#include "widgetlaurea.h"

WidgetLaurea::WidgetLaurea(const QString& s, const int& i, const int& k, QWidget *parent) : QWidget(parent){

    id = k;

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

}
