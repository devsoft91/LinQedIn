#ifndef WIDGETNEWIMPIEGO_H
#define WIDGETNEWIMPIEGO_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

class WidgetNewImpiego : public QWidget
{
    Q_OBJECT
public:
    QDialog* box;
    QGridLayout* g_layout;
    QLabel* l_titolo;
    QLabel* l_azienda;
    QLabel* l_citta;
    QLabel* l_inizio;
    QLabel* l_fine;
    QLabel* primo_lavoro;
    QLineEdit* titolo;
    QLineEdit* azienda;
    QLineEdit* citta;
    QDateEdit* inizio;
    QDateEdit* fine;
    QCheckBox* check;
    QDialogButtonBox* buttonbox;
    QPushButton* aggiungi;
    QPushButton* annulla;
    WidgetNewImpiego(QWidget *parent);

signals:
    void callFetchNewImpiego(QLineEdit*,QLineEdit*,QLineEdit*,QDateEdit*,QDateEdit*,bool);

public slots:
    void newImpiegoReady();

};

#endif // WIDGETNEWIMPIEGO_H
