#include "widgetimpiego.h"

WidgetImpiego::WidgetImpiego(const QString& a,const QString& b,const QString& c,const QDate& d,const QDate& e,QWidget *parent) : QWidget(parent){

    out_layout = new QVBoxLayout();

    box_esterna = new QGroupBox("Impiego");

    g_layout = new QGridLayout();

    l_titolo = new QLabel("Titolo");
    l_azienda = new QLabel("Nome Azienda");
    l_citta = new QLabel("Città");
    l_inizio = new QLabel("Data Inizio");
    l_fine = new QLabel("Data Fine");

    titolo = new QLineEdit(a);
    azienda = new QLineEdit(b);
    citta = new QLineEdit(c);
    inizio = new QDateEdit(d); inizio->setDisplayFormat("dd/MM/yyyy");
    fine = new QDateEdit(e); fine->setDisplayFormat("dd/MM/yyyy");

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    modifica = new QPushButton("Modifica"); modifica->setDisabled(true);
    annulla = new QPushButton("Annulla"); annulla->setDisabled(true);
    buttonbox->addButton(modifica,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);

    g_layout->addWidget(l_titolo,0,0);
    g_layout->addWidget(l_azienda,1,0);
    g_layout->addWidget(l_citta,2,0);
    g_layout->addWidget(l_inizio,3,0);
    g_layout->addWidget(l_fine,4,0);
    g_layout->addWidget(titolo,0,1);
    g_layout->addWidget(azienda,1,1);
    g_layout->addWidget(citta,2,1);
    g_layout->addWidget(inizio,3,1);
    g_layout->addWidget(fine,4,1);
    g_layout->addWidget(buttonbox,5,1);

    box_esterna->setLayout(g_layout);
    out_layout->addWidget(box_esterna);
    setLayout(out_layout);

    connect(titolo, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(azienda, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(citta, SIGNAL(textChanged(const QString&)), this, SLOT(enableUpdate(const QString&)));
    connect(inizio, SIGNAL(dateChanged(const QDate&)), this, SLOT(enableUpdate(const QDate&)));
    connect(fine, SIGNAL(dateChanged(const QDate&)), this, SLOT(enableUpdate(const QDate&)));

}

//slot
void WidgetImpiego::enableUpdate(const QString&){
    modifica->setDisabled(false);
    annulla->setDisabled(false);
}

//slot
void WidgetImpiego::enableUpdate(const QDate&){
    modifica->setDisabled(false);
    annulla->setDisabled(false);
}
