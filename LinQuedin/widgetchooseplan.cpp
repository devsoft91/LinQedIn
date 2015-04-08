#include "widgetchooseplan.h"

WidgetChoosePlan::WidgetChoosePlan(QWidget *parent,Admin* a,const QString& u) : QWidget(parent){

    tmp = a; user = u;

    box = new QDialog();
    QString title = "Scegli Piano - " + u;
    box->setWindowTitle(title);
    box->resize(350,150);

    v_layout = new QVBoxLayout();

    basic = new QRadioButton("Basic");
    business = new QRadioButton("Business");
    executive = new QRadioButton("Executive");

    if(tmp->typeOf(u)==0)
        basic->setChecked(true);
    if(tmp->typeOf(u)==1)
        business->setChecked(true);
    if(tmp->typeOf(u)==2)
        executive->setChecked(true);

    v_layout->addWidget(basic);
    v_layout->addWidget(business);
    v_layout->addWidget(executive);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    conferma = new QPushButton("Conferma");
    annulla = new QPushButton("Annulla");
    buttonbox->addButton(conferma,QDialogButtonBox::AcceptRole);
    buttonbox->addButton(annulla,QDialogButtonBox::RejectRole);
    v_layout->addWidget(buttonbox);

    box->setLayout(v_layout);

    connect(conferma, SIGNAL(clicked()), this, SLOT(updatePlan()));
    connect(this, SIGNAL(sendSaveOn()), parent, SLOT(catchSaveOn()));
    connect(annulla, SIGNAL(clicked()), box, SLOT(close()));

    box->exec();

}

//slot
void WidgetChoosePlan::updatePlan(){

    if(basic->isChecked())
        type = 0;
    if(business->isChecked())
        type = 1;
    if(executive->isChecked())
        type = 2;

    int tipo = tmp->typeOf(user);
    if(tipo!=type){
        tmp->changePlanTo(user,type);
        box->close();
        emit sendSaveOn();
    }
    else{
        QMessageBox box;
        box.setWindowTitle("Attenzione");
        QString mex = "Il piano dell'utente \"" + user + "\" non è cambiato!";
        box.setText(mex);
        box.setIcon(QMessageBox::Warning);
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
    }
}
