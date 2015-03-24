#ifndef VIEWRICERCA_H
#define VIEWRICERCA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

#include "client.h"
#include "widgetutentericerca.h"

class ViewRicerca : public QWidget
{
    Q_OBJECT
public:
    static bool nuovo;
    QVBoxLayout* layout;
    QWidget* w;
    QScrollArea* scroll_area;
    QVBoxLayout* v_layout;
    QLabel* no_ricerca;
    QLabel* no_risultati;

    Client* tmp;
    map<QString,Utente*> map_utenti;

    ViewRicerca(QWidget *parent,Client*);

signals:
    void signalUpdateNet();
    void callSaveOn();

public slots:
    void updateWithResearch();
    void updateWithoutResearch();
    void updateNet();

};

#endif // VIEWRICERCA_H
