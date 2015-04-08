#ifndef VIEWGESTIONEUTENTI_H
#define VIEWGESTIONEUTENTI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

#include "admin.h"
#include "widgetchooseplan.h"

class ViewGestioneUtenti : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout* v_layout;
    QGridLayout* g_layout1out;
    QGridLayout* g_layout1a;
    QGridLayout* g_layout1b;
    QGridLayout* g_layout2out;
    QGridLayout* g_layout2a;
    QGridLayout* g_layout2b;
    QGridLayout* g_layout3out;
    QGridLayout* g_layout3a;
    QGridLayout* g_layout3b;
    QGroupBox* g_aggiungi;
    QGroupBox* g_elimina;
    QGroupBox* g_modifica;
    QLabel* user1;
    QLabel* user2;
    QLabel* user3;
    QLineEdit* l_aggiungi;
    QLineEdit* l_elimina;
    QLineEdit* l_modifica;
    QPushButton* b_aggiungi;
    QPushButton* b_elimina;
    QPushButton* b_modifica;

    WidgetChoosePlan* chooseplan;

    Admin* tmp;

    ViewGestioneUtenti(QWidget *parent,Admin*);
    void warningDialog();

signals:
    void enableSaveInstance();
    void sendMessage(const QString&);

public slots:
    void checkEmptyAdd();
    void checkEmptyDel();
    void checkEmptyMod();
    void catchSaveOn();

};

#endif // VIEWGESTIONEUTENTI_H
