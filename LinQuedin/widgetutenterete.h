#ifndef WIDGETUTENTERETE_H
#define WIDGETUTENTERETE_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>

#include "client.h"
#include "viewprofilo.h"

class WidgetUtenteRete : public QWidget
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
    QPushButton* elimina;

    ViewProfilo* profilo;

    Client* tmp;

    WidgetUtenteRete(const QString&,const QString&,const QString&,QWidget *parent,Client*);

signals:
    void signalRemoveId(WidgetUtenteRete*);

public slots:
    void sendRemoveId();
    void viewProfilo();

};

#endif // WIDGETUTENTERETE_H
