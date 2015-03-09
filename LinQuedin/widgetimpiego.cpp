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

    tmp_titolo = titolo->text();
    tmp_azienda = azienda->text();
    tmp_citta = citta->text();
    tmp_inizio = inizio->date();
    tmp_fine = fine->date();

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    applica = new QPushButton("Applica"); applica->setDisabled(true);
    annulla = new QPushButton("Annulla"); annulla->setDisabled(true);
    elimina = new QPushButton("Elimina");
    buttonbox->addButton(applica,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
    buttonbox->addButton(elimina,QDialogButtonBox::ActionRole);

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

    connect(elimina, SIGNAL(clicked()), this, SLOT(sendRemoveId()));
    connect(this, SIGNAL(signalRemoveId(WidgetImpiego*)), parent, SLOT(updateAfterRemove(WidgetImpiego*)));
    connect(applica, SIGNAL(clicked()), this, SLOT(updateState()));
    connect(applica, SIGNAL(clicked()), this, SLOT(disableUpdate()));
    connect(this, SIGNAL(signalUpdateId(WidgetImpiego*,const QString&,const QString&,const QString&,const QDate&,const QDate&)), parent, SLOT(updateAfterUpdate(WidgetImpiego*,const QString&,const QString&,const QString&,const QDate&,const QDate&)));
    connect(annulla, SIGNAL(clicked()), this, SLOT(backData()));

}

//slot
void WidgetImpiego::enableUpdate(const QString&){
    applica->setDisabled(false);
    annulla->setDisabled(false);
    elimina->setDisabled(true);
}

//slot
void WidgetImpiego::enableUpdate(const QDate&){
    applica->setDisabled(false);
    annulla->setDisabled(false);
    elimina->setDisabled(true);
}

//slot
void WidgetImpiego::disableUpdate(){
    applica->setDisabled(true);
    annulla->setDisabled(true);
    elimina->setDisabled(false);

    tmp_titolo = titolo->text();
    tmp_azienda = azienda->text();
    tmp_citta = citta->text();
    tmp_inizio = inizio->date();
    tmp_fine = fine->date();
}

//slot
void WidgetImpiego::sendRemoveId(){
    emit signalRemoveId(this);
}

//slot
void WidgetImpiego::updateState(){
    emit signalUpdateId(this,tmp_titolo,tmp_azienda,tmp_citta,tmp_inizio,tmp_fine);
}

//slot
void WidgetImpiego::backData(){
    titolo->setText(tmp_titolo);
    azienda->setText(tmp_azienda);
    citta->setText(tmp_citta);
    inizio->setDate(tmp_inizio);
    fine->setDate(tmp_fine);

    disableUpdate();
}
