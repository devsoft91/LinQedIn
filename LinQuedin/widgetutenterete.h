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


class WidgetUtenteRete : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout* out_layout;
    QGroupBox* box_esterna;
    QGridLayout* g_layout;
    QVBoxLayout* sx_layout;
    QLabel* nome;
    QLabel*dettaglio;
    QDialogButtonBox* buttonbox;
    QPushButton* visualizza;
    QPushButton* elimina;
    WidgetUtenteRete(QWidget *parent = 0);

signals:

public slots:

};

#endif // WIDGETUTENTERETE_H
