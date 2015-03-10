#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTabWidget>

#include "viewdatianagrafici.h"
#include "viewtitolistudio.h"
#include "viewimpieghi.h"
#include "viewreti.h"
#include "client.h"

class ClientWindow : public QTabWidget{
    Q_OBJECT
public:
    ViewDatiAnagrafici* d_anagrafici;
    ViewTitoliStudio* titoli_studio;
    ViewImpieghi* impieghi;
    ViewReti* rete;
    ClientWindow(QWidget *parent,Client*);


signals:
    void signalSaveOn();

public slots:
    void saveOn();
    
};

#endif // CLIENTWINDOW_H
