#ifndef WIDGETLAUREA_H
#define WIDGETLAUREA_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QString>

#include "widgetupdatelaurea.h"

class WidgetLaurea : public QWidget{
    Q_OBJECT
public:
    QGridLayout* g_layout;
    QLineEdit* nomelaurea;
    QLineEdit* annolaurea;
    QLabel* l_nomelaurea;
    QLabel* l_annolaurea;
    QDialogButtonBox* buttonbox;
    QPushButton* aggiorna;
    QPushButton* elimina;

    WidgetUpdateLaurea* dialog;

    WidgetLaurea(const QString&, const int&, QWidget *parent = 0);
    ~WidgetLaurea();

signals:
    void signalRemoveId(WidgetLaurea*);
    void signalUpdateId(const QString&,int,WidgetLaurea*);

public slots:
    void sendRemoveId();
    void sendUpdateId();

};

#endif // WIDGETLAUREA_H
