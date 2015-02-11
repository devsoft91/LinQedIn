#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) : QWidget(parent){

    button = new QPushButton("Test");
    layout = new QGridLayout();
    layout->addWidget(button,0,0);
    setLayout(layout);

}
