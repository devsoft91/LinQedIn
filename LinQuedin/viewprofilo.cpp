#include "viewprofilo.h"

ViewProfilo::ViewProfilo(QWidget *parent) : QWidget(parent){
    layout = new QVBoxLayout(this);

    datianagrafici = new QGroupBox();
    titolistudio = new QGroupBox();
    impieghi = new QGroupBox();

    layoutbox = new QGridLayout(datianagrafici);
    nome = new QLineEdit();
    layoutbox->addWidget(nome);

    datianagrafici->setTitle("Dati Anagrafici");
    titolistudio->setTitle("Titoli di Studio");
    impieghi->setTitle("Impieghi");

    datianagrafici->setLayout(layoutbox);
    layout->addWidget(datianagrafici);
    layout->addWidget(titolistudio);
    layout->addWidget(impieghi);
    setLayout(layout);

}
