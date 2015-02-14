#ifndef VIEWTITOLISTUDIO_H
#define VIEWTITOLISTUDIO_H

#include <QWidget>
#include <QGridLayout>

#include "client.h"

class ViewTitoliStudio : public QWidget
{
    Q_OBJECT
public:
    QGridLayout* layout;
    ViewTitoliStudio(QWidget *parent,Client*);

signals:

public slots:

};

#endif // VIEWTITOLISTUDIO_H
