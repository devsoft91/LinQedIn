#ifndef VIEWRETI_H
#define VIEWRETI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

#include "widgetutenterete.h"
#include "client.h"

class ViewReti : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout* layout;
    QWidget* w;
    QScrollArea* scroll_area;
    QVBoxLayout* v_layout;
    QLabel* empty;

    Client* tmp;
    map<QString,Nodo> map_rete;

    ViewReti(QWidget *parent,Client*);

signals:
    void callSaveOn();

public slots:
    void update();
    void updateAfterRemove(WidgetUtenteRete*);

};

#endif // VIEWRETI_H
