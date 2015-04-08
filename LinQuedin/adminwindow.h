#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include "admin.h"
#include "viewgestioneutenti.h"
#include "viewricerca.h"

class AdminWindow : public QTabWidget
{
    Q_OBJECT
public:
    ViewGestioneUtenti* gestioneutenti;
    ViewRicerca* ricerca;

    Admin* tmp;

    AdminWindow(QWidget *parent,Admin*);

signals:
    void signalUpdateRicerca();
    void signalSaveOn();
    void sendMessageToBar(const QString&);

public slots:
    void focusRicerca();
    void saveOn();
    void catchMessage(const QString&);

};

#endif // ADMINWINDOW_H
