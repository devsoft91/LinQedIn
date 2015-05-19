#ifndef VIEWPROFILO_H
#define VIEWPROFILO_H

#include <QWidget>
#include <QDialog>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QVariant>

#include "admin.h"
#include "client.h"
#include "controller.h"

class WidgetUtenteRete;

class ViewProfilo : public QWidget
{
    Q_OBJECT
public:
    QString username;
    int controllertype;
    QDialog* box;
    QVBoxLayout* layout;
    QTreeWidget* view;

    Controller* tmp;

    ViewProfilo(QWidget *parent,const QString&,Controller*);

    void viewBasic();
    void viewBusiness();
    void viewExecutive();
    void viewAdmin();

signals:

public slots:

};

#endif // VIEWPROFILO_H
