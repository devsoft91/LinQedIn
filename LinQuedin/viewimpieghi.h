#ifndef VIEWIMPIEGHI_H
#define VIEWIMPIEGHI_H

#include <QWidget>
#include <list>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QRect>

#include "widgetimpiego.h"
#include "widgetnewimpiego.h"
#include "client.h"

class ViewImpieghi : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout* layout;
    QWidget* w;
    QScrollArea* scroll_area;
    QVBoxLayout* v_layout;
    QPushButton* addImpiego;

    WidgetNewImpiego* dialog;

    Client* tmp;
    list<Lavoro> list_impieghi;

    ViewImpieghi(QWidget *parent,Client*);
    Impieghi* getImpieghi(Client*) const;
    void setImpieghi();

signals:
    void callSaveOn();

public slots:
    void updateView();
    void addIBox();
    void fetchNewImpiego(QLineEdit*,QLineEdit*,QLineEdit*,QDateEdit*,QDateEdit*,bool);
    void updateAfterRemove(WidgetImpiego*);
    void updateAfterUpdate(WidgetImpiego*,const QString&,const QString&,const QString&,const QDate&,const QDate&);

};

#endif // VIEWIMPIEGHI_H
