#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTabWidget>

#include "viewprofilo.h"

class ClientWindow : public QTabWidget{
    Q_OBJECT
public:
    ViewProfilo* profilo;
    QWidget* rete;
    ClientWindow(QWidget *parent);

signals:

public slots:
    
};

#endif // CLIENTWINDOW_H
