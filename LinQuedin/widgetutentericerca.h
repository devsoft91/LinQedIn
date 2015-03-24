#ifndef WIDGETUTENTERICERCA_H
#define WIDGETUTENTERICERCA_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>

#include "client.h"

class WidgetUtenteRicerca : public QWidget
{
    Q_OBJECT
public:
    QString username;
    QVBoxLayout* out_layout;
    QGroupBox* box_esterna;
    QGridLayout* g_layout;
    QVBoxLayout* sx_layout;
    QLabel* nome;
    QLabel*dettaglio;
    QDialogButtonBox* buttonbox;
    QPushButton* visualizza;
    QPushButton* aggiungi;

    Client* tmp;

    WidgetUtenteRicerca(const QString&,const QString&,const QString&,QWidget *parent,Client*);

signals:
    void signalUpdateNet();

public slots:
    void sendAddRicerca();

};

#endif // WIDGETUTENTERICERCA_H
