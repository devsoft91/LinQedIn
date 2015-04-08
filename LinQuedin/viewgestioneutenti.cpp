#include "viewgestioneutenti.h"

ViewGestioneUtenti::ViewGestioneUtenti(QWidget *parent,Admin* a) : QWidget(parent){

    tmp = a;

    v_layout = new QVBoxLayout();
    v_layout->setAlignment(Qt::AlignHCenter);

    QLabel* space = new QLabel();
    space->setMaximumHeight(20);

    g_aggiungi = new QGroupBox("Aggiungi"); g_aggiungi->setMaximumSize(450,150);
    g_layout1out = new QGridLayout();
    g_layout1a = new QGridLayout();
    g_layout1b = new QGridLayout();
    user1 = new QLabel("Username"); user1->setMaximumWidth(60);
    l_aggiungi = new QLineEdit(); l_aggiungi->setMaximumWidth(210);
    b_aggiungi = new QPushButton("Aggiungi"); b_aggiungi->setMaximumWidth(100);
    g_layout1a->addWidget(user1,0,0);
    g_layout1a->addWidget(l_aggiungi,0,1);
    g_layout1b->addWidget(b_aggiungi,0,0);
    g_layout1out->addLayout(g_layout1a,0,0);
    g_layout1out->addLayout(g_layout1b,1,0);
    g_aggiungi->setLayout(g_layout1out);

    g_elimina = new QGroupBox("Elimina"); g_elimina->setMaximumSize(450,150);
    g_layout2out = new QGridLayout();
    g_layout2a = new QGridLayout();
    g_layout2b = new QGridLayout();
    user2 = new QLabel("Username"); user2->setMaximumWidth(60);
    l_elimina = new QLineEdit(); l_elimina->setMaximumWidth(210);
    b_elimina = new QPushButton("Elimina"); b_elimina->setMaximumWidth(100);
    g_layout2a->addWidget(user2,0,0);
    g_layout2a->addWidget(l_elimina,0,1);
    g_layout2b->addWidget(b_elimina,0,0);
    g_layout2out->addLayout(g_layout2a,0,0);
    g_layout2out->addLayout(g_layout2b,1,0);
    g_elimina->setLayout(g_layout2out);

    g_modifica = new QGroupBox("Modifica"); g_modifica->setMaximumSize(450,150);
    g_layout3out = new QGridLayout();
    g_layout3a = new QGridLayout();
    g_layout3b = new QGridLayout();
    user3 = new QLabel("Username"); user3->setMaximumWidth(60);
    l_modifica = new QLineEdit(); l_modifica->setMaximumWidth(210);
    b_modifica = new QPushButton("Modifica"); b_modifica->setMaximumWidth(100);
    g_layout3a->addWidget(user3,0,0);
    g_layout3a->addWidget(l_modifica,0,1);
    g_layout3b->addWidget(b_modifica,0,0);
    g_layout3out->addLayout(g_layout3a,0,0);
    g_layout3out->addLayout(g_layout3b,1,0);
    g_modifica->setLayout(g_layout3out);

    v_layout->addWidget(g_aggiungi);
    v_layout->addWidget(space);
    v_layout->addWidget(g_elimina);
    v_layout->addWidget(space);
    v_layout->addWidget(g_modifica);

    setLayout(v_layout);

    connect(b_aggiungi, SIGNAL(clicked()), this, SLOT(checkEmptyAdd()));
    connect(l_aggiungi, SIGNAL(returnPressed()), this, SLOT(checkEmptyAdd()));
    connect(b_elimina, SIGNAL(clicked()), this, SLOT(checkEmptyDel()));
    connect(l_elimina, SIGNAL(returnPressed()), this, SLOT(checkEmptyDel()));
    connect(b_modifica, SIGNAL(clicked()), this, SLOT(checkEmptyMod()));
    connect(l_modifica, SIGNAL(returnPressed()), this, SLOT(checkEmptyMod()));

    connect(this, SIGNAL(enableSaveInstance()), parent, SLOT(saveOn()));
    connect(this, SIGNAL(sendMessage(const QString&)), parent, SLOT(catchMessage(const QString&)));

}

//slot
void ViewGestioneUtenti::checkEmptyAdd(){
    if(l_aggiungi->text()=="")
        warningDialog();
    else{
        QMessageBox box;
        box.setWindowTitle("Conferma");
        QString mex = "Sei sicuro di voler aggiungere l'utente \"" + l_aggiungi->text() + "\" ?";
        box.setText(mex);
        box.setIcon(QMessageBox::Question);
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int choose = box.exec();
        switch(choose){
            case QMessageBox::Ok:
                tmp->addToDatabase(l_aggiungi->text());
                l_aggiungi->clear();
                emit enableSaveInstance();
                emit sendMessage("User inserted correctly in the database!");
                break;
            default:
                break;
        }

    }
}

//slot
void ViewGestioneUtenti::checkEmptyDel(){
    if(l_elimina->text()=="")
        warningDialog();
    else{
        if(!tmp->exist(l_elimina->text())){
            QMessageBox box;
            box.setWindowTitle("Errore");
            QString mex = "L'utente \"" + l_elimina->text() + "\" non esiste!";
            box.setText(mex);
            box.setIcon(QMessageBox::Critical);
            box.setStandardButtons(QMessageBox::Ok);
            box.exec();
        }
        else{
            QMessageBox box;
            box.setWindowTitle("Conferma");
            QString mex = "Sei sicuro di voler eliminare l'utente \"" + l_elimina->text() + "\" ?";
            box.setText(mex);
            box.setIcon(QMessageBox::Question);
            box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            int choose = box.exec();
            switch(choose){
                case QMessageBox::Ok:
                    tmp->delFromDatabase(l_elimina->text());
                    l_elimina->clear();
                    emit enableSaveInstance();
                    emit sendMessage("User deleted correctly from the database!");
                    break;
                default:
                    break;
            }

        }

    }

}

//slot
void ViewGestioneUtenti::checkEmptyMod(){
    if(l_modifica->text()=="")
        warningDialog();
    else{
        if(!tmp->exist(l_modifica->text())){
            QMessageBox box;
            box.setWindowTitle("Errore");
            QString mex = "L'utente \"" + l_modifica->text() + "\" non esiste!";
            box.setText(mex);
            box.setIcon(QMessageBox::Critical);
            box.setStandardButtons(QMessageBox::Ok);
            box.exec();
        }
        else{
            chooseplan = new WidgetChoosePlan(this,tmp,l_modifica->text());
        }
    }
}

void ViewGestioneUtenti::warningDialog(){
    QMessageBox box;
    box.setWindowTitle("Attenzione");
    box.setText("Inserisci uno username!");
    box.setIcon(QMessageBox::Warning);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
}

//slot
void ViewGestioneUtenti::catchSaveOn(){
    emit enableSaveInstance();
}
