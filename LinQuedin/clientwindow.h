#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QTabWidget>
#include <QTabBar>

#include "viewdatianagrafici.h"
#include "viewtitolistudio.h"
#include "viewimpieghi.h"
#include "viewreti.h"
#include "viewricerca.h"
#include "client.h"

class ClientWindow : public QTabWidget{
    Q_OBJECT
public:
    ViewDatiAnagrafici* d_anagrafici;
    ViewTitoliStudio* titoli_studio;
    ViewImpieghi* impieghi;
    ViewReti* rete;
    ViewRicerca* ricerca;

    Client* tmp;

    ClientWindow(QWidget *parent,Client*);

signals:
    void signalSaveOn();
    void signalUpdateRicerca();
    void signalUpdateViewReti();

public slots:
    void saveOn();
    void focusRicerca();
    void updateViewReti();
    
};

#endif // CLIENTWINDOW_H
