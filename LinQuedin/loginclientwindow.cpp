#include "loginclientwindow.h"

LoginClientWindow::LoginClientWindow(QWidget *parent) : QWidget(parent){

    out_layout = new QGridLayout();
    out_layout->setAlignment(Qt::AlignHCenter);

    layout1 = new QGridLayout();
    layout1->setAlignment(Qt::AlignHCenter);

    layout2 = new QGridLayout();
    layout2->setAlignment(Qt::AlignHCenter);

    l_username = new QLabel("Username:");l_username->setMaximumWidth(80);
    username = new QLineEdit();username->setMaximumWidth(250);
    layout1->addWidget(l_username,0,0);
    layout1->addWidget(username,0,1);

    b_login = new QPushButton("Login Client");
    b_login->setMaximumWidth(100);
    layout2->addWidget(b_login,0,0);

    out_layout->addLayout(layout1,0,0);
    out_layout->addLayout(layout2,1,0);

    parent->setWindowTitle("LinQedIn - Login Client");
    setLayout(out_layout);

    username->setFocus();

    connect(b_login, SIGNAL(clicked()), this, SLOT(setU()));
    connect(this, SIGNAL(valueReady(const QString&)), parent, SLOT(loginClient(const QString&)));
    connect(username, SIGNAL(returnPressed()), this, SLOT(setU()));
}

LoginClientWindow::~LoginClientWindow(){
    delete l_username;
    delete username;
    delete b_login;
    delete layout1;
    delete layout2;
    delete out_layout;
}

//slot
void LoginClientWindow::setU(){
    emit valueReady(username->text());
}
