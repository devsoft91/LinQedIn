#ifndef VIEWRETI_H
#define VIEWRETI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>

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

    Client* tmp;

    ViewReti(QWidget *parent,Client*);

signals:

public slots:

};

#endif // VIEWRETI_H
