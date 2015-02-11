#include "loginclientwindow.h"

LoginClientWindow::LoginClientWindow(QWidget *parent) : QWidget(parent){

    email_l = new QLabel("Email:");
    email_e = new QLineEdit;
    login_b = new QPushButton("Login");
    layout = new QGridLayout();
    layout->addWidget(email_l,0,0);
    layout->addWidget(email_e,0,1);
    layout->addWidget(login_b,0,2);

    parent->setWindowTitle("LinQedIn - Login Client");
    setLayout(layout);

    connect(login_b, SIGNAL(clicked()), parent, SLOT(loginClient()));

}

LoginClientWindow::~LoginClientWindow(){
    delete email_l;
    delete email_e;
    delete login_b;
    delete layout;
}
