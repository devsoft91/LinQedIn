#include "widgetnewimpiego.h"

WidgetNewImpiego::WidgetNewImpiego(QWidget *parent) : QWidget(parent){

    box = new QDialog();
    box->resize(300,100);
    g_layout = new QGridLayout(box);
    box->setWindowTitle("Nuovo Impiego");

    l_titolo = new QLabel("Titolo");
    l_azienda = new QLabel("Nome Azienda");
    l_citta = new QLabel("Città");
    l_inizio = new QLabel("Data Inizio");
    l_fine = new QLabel("Data Fine");
    primo_lavoro = new QLabel("Attuale lavoro?");

    titolo = new QLineEdit();
    azienda = new QLineEdit();
    citta = new QLineEdit();
    inizio = new QDateEdit(); inizio->setDisplayFormat("dd/MM/yyyy");
    fine = new QDateEdit(); fine->setDisplayFormat("dd/MM/yyyy");

    check = new QCheckBox();

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    aggiungi = new QPushButton("Aggiungi");
    annulla = new QPushButton("Annulla");
    buttonbox->addButton(aggiungi,QDialogButtonBox::AcceptRole);
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
    g_layout->addWidget(primo_lavoro,5,0);
    g_layout->addWidget(check,5,1);
    g_layout->addWidget(buttonbox,6,1);

    box->setLayout(g_layout);

    connect(aggiungi, SIGNAL(clicked()), this, SLOT(newImpiegoReady()));
    connect(annulla, SIGNAL(clicked()), box, SLOT(close()));
    connect(this, SIGNAL(callFetchNewImpiego(QLineEdit*,QLineEdit*,QLineEdit*,QDateEdit*,QDateEdit*,bool)), parent, SLOT(fetchNewImpiego(QLineEdit*,QLineEdit*,QLineEdit*,QDateEdit*,QDateEdit*,bool)));

    box->exec();

}

//slot
void WidgetNewImpiego::newImpiegoReady(){
    emit callFetchNewImpiego(titolo,azienda,citta,inizio,fine,check->isChecked());
    box->close();
}
