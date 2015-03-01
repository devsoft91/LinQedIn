#include "loginclientwindow.h"

LoginClientWindow::LoginClientWindow(QWidget *parent) : QWidget(parent){

    l_username = new QLabel("Username:");
    username = new QLineEdit;
    b_login = new QPushButton("Login Client");
    layout = new QGridLayout();
    layout->addWidget(l_username,0,0);
    layout->addWidget(username,0,1);
    layout->addWidget(b_login,0,2);

    parent->setWindowTitle("LinQedIn - Login Client");
    setLayout(layout);

    username->setFocus();

    connect(b_login, SIGNAL(clicked()), this, SLOT(setU()));
    connect(this, SIGNAL(valueReady(const QString&)), parent, SLOT(loginClient(const QString&)));
    connect(username, SIGNAL(returnPressed()), this, SLOT(setU()));
}

LoginClientWindow::~LoginClientWindow(){
    delete l_username;
    delete username;
    delete b_login;
    delete layout;
}

//slot
void LoginClientWindow::setU(){
    emit valueReady(username->text());
}
