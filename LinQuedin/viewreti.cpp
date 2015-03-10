#include "viewreti.h"

ViewReti::ViewReti(QWidget* parent, Client* c) : QWidget(parent){

    tmp = c;

    layout = new QVBoxLayout();

    v_layout = new QVBoxLayout();
    v_layout->setAlignment(Qt::AlignTop);

    scroll_area = new QScrollArea(this);

    w = new QWidget(scroll_area);

    WidgetUtenteRete* user1 = new WidgetUtenteRete();
    v_layout->addWidget(user1);
    WidgetUtenteRete* user2 = new WidgetUtenteRete();
    v_layout->addWidget(user2);
    WidgetUtenteRete* user3 = new WidgetUtenteRete();
    v_layout->addWidget(user3);

    w->setLayout(v_layout);

    scroll_area->setWidget(w);
    scroll_area->setWidgetResizable(true);

    layout->addWidget(scroll_area);

    setLayout(layout);
}
