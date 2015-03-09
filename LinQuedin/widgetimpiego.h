#ifndef WIDGETIMPIEGO_H
#define WIDGETIMPIEGO_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QPushButton>

#include "client.h"

class WidgetImpiego : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout* out_layout;
    QGroupBox* box_esterna;
    QGridLayout* g_layout;
    QLabel* l_titolo;
    QLabel* l_azienda;
    QLabel* l_citta;
    QLabel* l_inizio;
    QLabel* l_fine;
    QLineEdit* titolo;
    QLineEdit* azienda;
    QLineEdit* citta;
    QDateEdit* inizio;
    QDateEdit* fine;
    QDialogButtonBox* buttonbox;
    QPushButton* applica;
    QPushButton* annulla;
    QPushButton* elimina;

    QString tmp_titolo;
    QString tmp_azienda;
    QString tmp_citta;
    QDate tmp_inizio;
    QDate tmp_fine;

    WidgetImpiego(const QString&,const QString&,const QString&,const QDate&,const QDate&,QWidget*);

signals:
    void signalRemoveId(WidgetImpiego*);
    void signalUpdateId(WidgetImpiego*,const QString&,const QString&,const QString&,const QDate&,const QDate&);

public slots:
    void enableUpdate(const QString&);
    void enableUpdate(const QDate&);
    void disableUpdate();
    void sendRemoveId();
    void updateState();
    void backData();
};

#endif // WIDGETIMPIEGO_H
