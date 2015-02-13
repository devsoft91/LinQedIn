#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) : QTabWidget(parent){
    profilo = new ViewProfilo(this);
    rete = new QWidget(this);
    addTab(profilo,"Profilo");
    addTab(rete,"Collegamenti");

}
