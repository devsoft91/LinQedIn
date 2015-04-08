#include "widgetwelcome.h"

WidgetWelcome::WidgetWelcome(QWidget *parent) : QWidget(parent){

    v_layout = new QVBoxLayout();
    v_layout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    g_layout = new QGridLayout();
    //g_layout->setContentsMargins(70,70,20,20);

    welcome = new QLabel("Welcome!");
    welcome->setMargin(20);
    welcome->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setBold(true);
    font.setPointSize(25);
    welcome->setFont(font);

    v_layout->addWidget(welcome);

    w_admin = new QWidget();
    v_layout_a = new QVBoxLayout();
    v_layout_a->setContentsMargins(25,0,25,0);
    img_admin = new QLabel(); img_admin->setMargin(20);
    l_admin = new QLabel("<a href=\"admin\">Login as Admin</a>");
    l_admin->setAlignment(Qt::AlignCenter);
    QPixmap* img_a = new QPixmap(":/immagini/admin.png");
    *img_a = img_a->scaledToHeight(120);
    *img_a = img_a->scaledToWidth(120);
    img_admin->setPixmap(*img_a);
    v_layout_a->addWidget(img_admin);
    v_layout_a->addWidget(l_admin);
    w_admin->setLayout(v_layout_a);

    w_client = new QWidget();
    v_layout_c = new QVBoxLayout();
    v_layout_c->setContentsMargins(25,0,25,0);
    img_client = new QLabel(); img_client->setMargin(20);
    l_client = new QLabel("<a href=\"client\">Login as Client</a>");
    l_client->setAlignment(Qt::AlignCenter);
    QPixmap* img_c = new QPixmap(":/immagini/client.png");
    *img_c = img_c->scaledToHeight(120);
    *img_c = img_c->scaledToWidth(120);
    img_client->setPixmap(*img_c);
    v_layout_c->addWidget(img_client);
    v_layout_c->addWidget(l_client);
    w_client->setLayout(v_layout_c);

    g_layout->addWidget(w_admin,0,0);
    g_layout->addWidget(w_client,0,1);

    login = new QWidget();
    login->setLayout(g_layout);

    v_layout->addWidget(login);

    setLayout(v_layout);

    connect(l_admin, SIGNAL(linkActivated(const QString&)), this, SLOT(checkStringLogin(const QString&)));
    connect(l_client, SIGNAL(linkActivated(const QString&)), this, SLOT(checkStringLogin(const QString&)));
    connect(this, SIGNAL(callAdmin()), parent, SLOT(showLoginAdminWindow()));
    connect(this, SIGNAL(callClient()), parent, SLOT(showLoginClientWindow()));

}

//slot
void WidgetWelcome::checkStringLogin(const QString& s){
    if(s=="admin")
        emit callAdmin();
    if(s=="client")
        emit callClient();
}
