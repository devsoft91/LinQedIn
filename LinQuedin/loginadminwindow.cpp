#include "loginadminwindow.h"

LoginAdminWindow::LoginAdminWindow(QWidget *parent) : QWidget(parent){

    email_l = new QLabel("Username:");
    email_e = new QLineEdit;
    login_b = new QPushButton("Login Admin");
    layout = new QGridLayout;
    layout->addWidget(email_l,0,0);
    layout->addWidget(email_e,0,1);
    layout->addWidget(login_b,0,2);

    parent->setWindowTitle("LinQedIn - Login Administrator");
    setLayout(layout);

    connect(login_b, SIGNAL(clicked()), parent, SLOT(loginAdmin()));

}

LoginAdminWindow::~LoginAdminWindow(){
    delete email_l;
    delete email_e;
    delete login_b;
    delete layout;
}
