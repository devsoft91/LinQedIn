#include "widgetnewricerca.h"

WidgetNewRicerca::WidgetNewRicerca(QWidget *parent,Controller* c) : QWidget(parent){

    tmp = c;

    box = new QDialog();
    box->resize(300,100);
    g_layout = new QGridLayout();

    fillFields();

    if(tmp->returnUserType()!=3)
        box->setLayout(g_layout);

    connect(cerca, SIGNAL(clicked()), this, SLOT(checkEmptyFields()));
    connect(annulla, SIGNAL(clicked()), box, SLOT(close()));
    connect(this, SIGNAL(signalFocusRicerca()), parent, SLOT(focusRicerca()));

    box->exec();

}

void WidgetNewRicerca::fillFields(){
    if(tmp->returnUserType()==0){
        box->setWindowTitle("Nuova Ricerca - Basic");
        fillBasic(0);
    }
    if(tmp->returnUserType()==1){
        box->setWindowTitle("Nuova Ricerca - Business");
        fillBusiness(1);
    }
    if(tmp->returnUserType()==2){
        box->setWindowTitle("Nuova Ricerca - Executive");
        fillExecutive(2);
    }
    if(tmp->returnUserType()==3){
        box->setWindowTitle("Nuova Ricerca - Admin");

        l_username = new QLabel("Username");
        username = new QLineEdit(); username->setText("");
        g_layout->addWidget(l_username,0,0);
        g_layout->addWidget(username,0,1);

        v_layout = new QVBoxLayout();
        v_layout->setAlignment(Qt::AlignTop);

        radio1 = new QRadioButton("Cerca un utente");
        radio1->setChecked(true);
        g_box = new QGroupBox("Info");
        g_box->setLayout(g_layout);
        QFrame* line = new QFrame();
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        radio2 = new QRadioButton("Cerca tutti gli utenti");

        v_layout->addWidget(radio1);
        v_layout->addWidget(g_box);
        v_layout->addWidget(line);
        v_layout->addWidget(radio2);

        buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
        cerca = new QPushButton("Cerca");
        annulla = new QPushButton("Annulla");
        buttonbox->addButton(cerca,QDialogButtonBox::AcceptRole);
        buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
        buttonbox->setContentsMargins(0,10,0,0);
        v_layout->addWidget(buttonbox);

        box->setLayout(v_layout);

        connect(radio1, SIGNAL(clicked()), this, SLOT(enableField()));
        connect(radio2, SIGNAL(clicked()), this, SLOT(disableField()));
    }
}

void WidgetNewRicerca::fillBasic(int i){
    l_nome = new QLabel("Nome");
    l_cognome = new QLabel("Cognome");
    nome = new QLineEdit(); nome->setText("");
    cognome = new QLineEdit(); cognome->setText("");

    g_layout->addWidget(l_nome,0,0);
    g_layout->addWidget(l_cognome,1,0);
    g_layout->addWidget(nome,0,1);
    g_layout->addWidget(cognome,1,1);

    if(i==0){
        buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
        cerca = new QPushButton("Cerca");
        annulla = new QPushButton("Annulla");
        buttonbox->addButton(cerca,QDialogButtonBox::AcceptRole);
        buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
        g_layout->addWidget(buttonbox,2,1);
    }
}

void WidgetNewRicerca::fillBusiness(int i){
    fillBasic(i);

    l_diploma = new QLabel("Diploma");
    l_laurea = new QLabel("Laurea");
    diploma = new QLineEdit();
    laurea = new QLineEdit();

    g_layout->addWidget(l_diploma,2,0);
    g_layout->addWidget(l_laurea,3,0);
    g_layout->addWidget(diploma,2,1);
    g_layout->addWidget(laurea,3,1);

    if(i==1){
        buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
        cerca = new QPushButton("Cerca");
        annulla = new QPushButton("Annulla");
        buttonbox->addButton(cerca,QDialogButtonBox::AcceptRole);
        buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
        g_layout->addWidget(buttonbox,4,1);
    }

}

void WidgetNewRicerca::fillExecutive(int i){
    fillBusiness(i);

    l_titolo = new QLabel("Titolo");
    l_azienda = new QLabel("Azienda");
    titolo = new QLineEdit();
    azienda = new QLineEdit();

    g_layout->addWidget(l_titolo,5,0);
    g_layout->addWidget(l_azienda,6,0);
    g_layout->addWidget(titolo,5,1);
    g_layout->addWidget(azienda,6,1);

    if(i==2){
        buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
        cerca = new QPushButton("Cerca");
        annulla = new QPushButton("Annulla");
        buttonbox->addButton(cerca,QDialogButtonBox::AcceptRole);
        buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
        g_layout->addWidget(buttonbox,7,1);
    }

}

//slot
void WidgetNewRicerca::launchResearch(){
    if(tmp->returnUserType()==0)
        tmp->sendRicerca("",nome->text(),cognome->text(),"","","","");
    if(tmp->returnUserType()==1)
        tmp->sendRicerca("",nome->text(),cognome->text(),diploma->text(),laurea->text(),"","");
    if(tmp->returnUserType()==2)
        tmp->sendRicerca("",nome->text(),cognome->text(),diploma->text(),laurea->text(),titolo->text(),azienda->text());
    if(tmp->returnUserType()==3)
        if(radio1->isChecked())
            tmp->sendRicerca(username->text(),"","","","","","");
        else tmp->sendRicerca("","","","","","","");

    box->close();

    emit signalFocusRicerca();
}

//slot
void WidgetNewRicerca::checkEmptyFields(){
    if(tmp->returnUserType()==0)
        if(nome->text()=="" && cognome->text()=="")
            warningDialog();
        else launchResearch();
    if(tmp->returnUserType()==1)
        if(nome->text()=="" && cognome->text()=="" && diploma->text()=="" && laurea->text()=="")
            warningDialog();
        else launchResearch();
    if(tmp->returnUserType()==2)
        if(nome->text()=="" && cognome->text()=="" && diploma->text()=="" && laurea->text()=="" && titolo->text()=="" && azienda->text()=="")
            warningDialog();
        else launchResearch();
    if(tmp->returnUserType()==3)
        if(radio1->isChecked() && username->text()=="")
            warningDialog();
        else launchResearch();
}

//slot
void WidgetNewRicerca::warningDialog(){
    QMessageBox box;
    box.setWindowTitle("Attenzione");
    box.setText("Hai lasciato tutti i campi vuoti!");
    box.setIcon(QMessageBox::Warning);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
}

//slot
void WidgetNewRicerca::enableField(){
    g_box->setEnabled(true);
}

//slot
void WidgetNewRicerca::disableField(){
    g_box->setEnabled(false);
}
