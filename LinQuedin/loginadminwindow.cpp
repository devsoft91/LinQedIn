#include "loginadminwindow.h"

LoginAdminWindow::LoginAdminWindow(QWidget *parent) : QWidget(parent){

    out_layout = new QGridLayout();
    out_layout->setAlignment(Qt::AlignHCenter);

    layout1 = new QGridLayout();
    layout1->setAlignment(Qt::AlignHCenter);

    layout2 = new QGridLayout();
    layout2->setAlignment(Qt::AlignHCenter);

    l_pswd = new QLabel("Password:");l_pswd->setMaximumWidth(80);
    pswd = new QLineEdit(); pswd->setMaximumWidth(250); pswd->setEchoMode(QLineEdit::Password);
    layout1->addWidget(l_pswd,0,0);
    layout1->addWidget(pswd,0,1);

    b_login = new QPushButton("Login Admin");b_login->setMaximumWidth(100);
    layout2->addWidget(b_login,0,0);

    out_layout->addLayout(layout1,0,0);
    out_layout->addLayout(layout2,1,0);

    parent->setWindowTitle("LinQedIn - Login Admin");
    setLayout(out_layout);

    pswd->setFocus();

    connect(b_login, SIGNAL(clicked()), this, SLOT(checkPswd()));
    connect(this, SIGNAL(signalPassPswd(QString)), parent, SLOT(loginAdmin(const QString&)));
    connect(pswd, SIGNAL(returnPressed()), this, SLOT(checkPswd()));
    }

LoginAdminWindow::~LoginAdminWindow(){
    delete l_pswd;
    delete pswd;
    delete b_login;
    delete layout1;
    delete layout2;
    delete out_layout;
}

//slot
void LoginAdminWindow::checkPswd(){
    emit signalPassPswd(pswd->text());
}

