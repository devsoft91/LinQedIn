#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <string>
#include <QDate>
#include <iostream>
#include <typeinfo>//solo x test DA RIMUOVERE

#include "database.h"
#include "ubasic.h"

using namespace std;

int main(){

    Database database;
    database.load();
    Utente* utente1 = database.getUtente("a");
    Utente* ubasic = new UBasic();
    std::cout<<typeid(*ubasic).name()<<std::endl;
    //ubasic->add("c",database);
    database.save();
    return 0;

}
