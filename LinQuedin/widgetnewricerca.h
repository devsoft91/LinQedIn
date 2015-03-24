#ifndef WIDGETNEWRICERCA_H
#define WIDGETNEWRICERCA_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

#include "client.h"

class WidgetNewRicerca : public QWidget
{
    Q_OBJECT
public:
    QDialog* box;
    QGridLayout* g_layout;
    QLabel* l_nome;
    QLabel* l_cognome;
    QLineEdit* nome;
    QLineEdit* cognome;

    QLabel* l_diploma;
    QLabel* l_laurea;
    QLineEdit* diploma;
    QLineEdit* laurea;

    QLabel* l_titolo;
    QLabel* l_azienda;
    QLineEdit* titolo;
    QLineEdit* azienda;

    QDialogButtonBox* buttonbox;
    QPushButton* cerca;
    QPushButton* annulla;

    Client* tmp;

    void fillFields();
    void fillBasic(int);
    void fillBusiness(int);
    void fillExecutive(int);
    WidgetNewRicerca(QWidget *parent,Client*);


signals:
    void signalFocusRicerca();

public slots:
    void launchResearch();
    void checkEmptyFields();
    void warningDialog();

};

#endif // WIDGETNEWRICERCA_H
