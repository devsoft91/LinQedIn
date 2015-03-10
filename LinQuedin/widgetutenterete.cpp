#include "widgetutenterete.h"

WidgetUtenteRete::WidgetUtenteRete(QWidget *parent) : QWidget(parent){

    out_layout = new QVBoxLayout();

    box_esterna = new QGroupBox("Utente");

    g_layout = new QGridLayout();

    sx_layout = new QVBoxLayout();

    nome = new QLabel("Ciccio Pasticcio");
    QFont font; font.setPointSize(20);
    nome->setFont(font);
    dettaglio = new QLabel("Madonna puttana");

    sx_layout->addWidget(nome);
    sx_layout->addWidget(dettaglio);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    visualizza = new QPushButton("Visualizza Profilo");
    elimina = new QPushButton("Elimina dalla rete");
    buttonbox->addButton(visualizza,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(elimina,QDialogButtonBox::RejectRole);

    g_layout->addLayout(sx_layout,0,0);
    g_layout->addWidget(buttonbox,0,1);

    box_esterna->setLayout(g_layout);
    out_layout->addWidget(box_esterna);
    setLayout(out_layout);

}
