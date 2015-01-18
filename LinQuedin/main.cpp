#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <string>
#include <QDate>
#include <iostream>

#include "database.h"

using namespace std;

int main(){

    Database database;
    database.load();
    //Utente* utente1 = database.getUtente("a");
    //utente1->add("c",database);
    database.save();
    return 0;

}
