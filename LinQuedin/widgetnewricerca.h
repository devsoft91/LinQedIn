#ifndef WIDGETNEWRICERCA_H
#define WIDGETNEWRICERCA_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>

#include "controller.h"

class WidgetNewRicerca : public QWidget
{
    Q_OBJECT
public:
    QDialog* box;
    QGridLayout* g_layout;
    QVBoxLayout* v_layout;
    QGroupBox* g_box;

    QRadioButton* radio1;
    QRadioButton* radio2;

    QLabel* l_username;
    QLineEdit* username;

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

    Controller* tmp;

    void fillFields();
    void fillBasic(int);
    void fillBusiness(int);
    void fillExecutive(int);
    WidgetNewRicerca(QWidget *parent,Controller*);


signals:
    void signalFocusRicerca();

public slots:
    void launchResearch();
    void checkEmptyFields();
    void warningDialog();
    void enableField();
    void disableField();

};

#endif // WIDGETNEWRICERCA_H
