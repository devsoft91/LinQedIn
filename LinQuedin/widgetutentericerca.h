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

#include "controller.h"
#include "admin.h"
#include "client.h"
#include "viewprofilo.h"

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

    ViewProfilo* profilo;

    Controller* tmp;

    WidgetUtenteRicerca(const QString&,const QString&,const QString&,QWidget *parent,Controller*);

signals:
    void signalUpdateNet();

public slots:
    void sendAddRicerca();
    void viewProfilo();

};

#endif // WIDGETUTENTERICERCA_H
