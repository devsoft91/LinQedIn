#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTabWidget>

#include "viewdatianagrafici.h"
#include "viewtitolistudio.h"
#include "client.h"

class ClientWindow : public QTabWidget{
    Q_OBJECT
public:
    ViewDatiAnagrafici* d_anagrafici;
    ViewTitoliStudio* titoli_studio;
    QWidget* impieghi;
    QWidget* rete;
    ClientWindow(QWidget *parent,Client*);


signals:
    void signalSaveOn();

public slots:
    void saveOn();
    
};

#endif // CLIENTWINDOW_H
