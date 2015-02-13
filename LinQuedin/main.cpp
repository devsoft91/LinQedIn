#include <QApplication>
#include <QString>
#include <string>
#include <QDate>
#include <iostream>
#include <typeinfo>//solo x test DA RIMUOVERE

#include "mainwindow.h"

using namespace std;

int main(int argc,char* argv[]){

    QApplication app(argc,argv);
    MainWindow w;
    w.show();

    return app.exec();

}
