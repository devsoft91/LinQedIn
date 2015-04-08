#include <QApplication>
#include <QString>
#include <string>
#include <QDate>
#include <iostream>
#include <typeinfo>//solo x test DA RIMUOVERE

#include "mainwindow.h"
#include "qdesktopwidget.h"

using namespace std;

int main(int argc,char* argv[]){

    QApplication app(argc,argv);
    MainWindow w;
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x,y);
    w.show();

    return app.exec();

}
