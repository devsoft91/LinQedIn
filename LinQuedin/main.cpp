#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <string>
#include <QDate>
#include <iostream>

#include "database.h"
#include "ubasic.h"

using namespace std;

int main(){

    Database database;
    database.load();
    Utente* utente1 = database.getUtente("a");
    Utente* ubasic = new UBasic();
    ubasic->add("c",database);
    database.save();
    return 0;

}
