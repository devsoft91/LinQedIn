#ifndef WIDGETUPDATELAUREA_H
#define WIDGETUPDATELAUREA_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>

//#include "widgetlaurea.h"
class WidgetLaurea;

class WidgetUpdateLaurea : public QWidget{
    Q_OBJECT
public:
    QDialog* box;
    QGridLayout* layout;
    QLineEdit* nomelaurea;
    QSpinBox* annolaurea;
    QLabel* l_nomelaurea;
    QLabel* l_annolaurea;
    QDialogButtonBox* buttonbox;
    QPushButton* conferma;
    QPushButton* annulla;

    WidgetLaurea* tmp_laurea;

    WidgetUpdateLaurea(const QString&,int,WidgetLaurea* laurea,QWidget *parent = 0);

signals:
    void callFetchUpdateLaurea(WidgetLaurea*,QLineEdit*,QSpinBox*);

public slots:
    void updateLaureaReady();

};

#endif // WIDGETUPDATELAUREA_H
