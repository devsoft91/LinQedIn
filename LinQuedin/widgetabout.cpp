#include "widgetabout.h"

WidgetAbout::WidgetAbout(QWidget *parent) : QWidget(parent){

    box = new QDialog();
    box->setWindowTitle("About LinQedIn");

    g_layout = new QGridLayout();
    g_layout->setAlignment(Qt::AlignTop);
    g_layout->setSizeConstraint( QLayout::SetFixedSize );

    v_layout1 = new QVBoxLayout();
    v_layout1->setAlignment(Qt::AlignBottom);
    v_layout2 = new QVBoxLayout();

    l_image = new QLabel();
    QPixmap* img = new QPixmap(":/immagini/linQedin.png");
    *img = img->scaledToHeight(150);
    l_image->setPixmap(*img);

    v_layout1->addWidget(l_image);

    QFont font;
    font.setBold(true);
    font.setPointSize(13);
    info1 = new QLabel("LinQedIn"); info1->setContentsMargins(30,15,0,15);
    info1->setMinimumWidth(250);
    info1->setFont(font);

    info2 = new QLabel("Built with Qt 5.3.2 (GCC 4.6.1, 64 bit)");
    info2->setContentsMargins(30,10,10,10);
    QString date = QString::fromLocal8Bit(BMONTH) + " " + QString::fromLocal8Bit(BDAY) + " " + QString::fromLocal8Bit(BYEAR);
    QString time = QString::fromLocal8Bit(BHOUR) + ":" + QString::fromLocal8Bit(BMINUTE) + ":" + QString::fromLocal8Bit(BSECOND);
    QString datetime = "Built on " + date + " at " + time + " CEST";
    info3 = new QLabel(datetime);
    info3->setContentsMargins(30,10,10,10);
    info4 = new QLabel("Copyright 2014-2015 - Giacomo Beltrame - All Rights Reserved");
    info4->setContentsMargins(30,10,10,10);
    info5 = new QLabel("This program has been developed like a didactical project\nfor \"Programmazione ad Oggetti\" course\nat \"Università degli Studi di Padova\"");
    info5->setContentsMargins(30,10,10,10);

    v_layout2->addWidget(info1);
    v_layout2->addWidget(info2);
    v_layout2->addWidget(info3);
    v_layout2->addWidget(info4);
    v_layout2->addWidget(info5);

    buttonbox = new QDialogButtonBox(Qt::Horizontal,this);
    chiudi = new QPushButton("Close");
    buttonbox->addButton(chiudi,QDialogButtonBox::RejectRole);

    g_layout->addLayout(v_layout1,0,0);
    g_layout->addLayout(v_layout2,0,1);
    g_layout->addWidget(buttonbox,1,1);

    box->setLayout(g_layout);

    connect(chiudi, SIGNAL(clicked()), box, SLOT(close()));

    box->exec();

}
