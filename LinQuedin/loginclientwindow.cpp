#include "loginclientwindow.h"

LoginClientWindow::LoginClientWindow(QWidget *parent) : QWidget(parent){

    email_l = new QLabel("Username:");
    email_e = new QLineEdit;
    login_b = new QPushButton("Login Client");
    layout = new QGridLayout();
    layout->addWidget(email_l,0,0);
    layout->addWidget(email_e,0,1);
    layout->addWidget(login_b,0,2);

    parent->setWindowTitle("LinQedIn - Login Client");
    setLayout(layout);

    connect(login_b, SIGNAL(clicked()), this, SLOT(setU()));
    connect(this, SIGNAL(valueReady(const QString&)), parent, SLOT(loginClient(const QString&)));
}

LoginClientWindow::~LoginClientWindow(){
    delete email_l;
    delete email_e;
    delete login_b;
    delete layout;
}

//slot
void LoginClientWindow::setU(){
    emit valueReady(email_e->text());
}
