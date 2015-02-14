#ifndef VIEWDATIANAGRAFICI_H
#define VIEWDATIANAGRAFICI_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QDateEdit>
#include <QPushButton>
#include <QDialogButtonBox>

#include "client.h"

class ViewDatiAnagrafici : public QWidget
{
    Q_OBJECT
public:
    QGridLayout* gridlayout;
    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* email;
    QDateEdit* datanascita;
    QLineEdit* luogonascita;
    QLineEdit* luogoresidenza;
    QLabel* l_nome;
    QLabel* l_cognome;
    QLabel* l_email;
    QLabel* l_datanascita;
    QLabel* l_luogonascita;
    QLabel* l_luogoresidenza;
    QPushButton* b_nome;
    QPushButton* b_cognome;
    QPushButton* b_email;
    QPushButton* b_datanascita;
    QPushButton* b_luogonascita;
    QPushButton* b_luogoresidenza;
    QDialogButtonBox* buttonbox;
    QPushButton* confirm;
    QPushButton* discard;

    Client* tmp;

    ViewDatiAnagrafici(QWidget *parent,Client*);
    DAnagrafici* getDatiAnagrafici(Client*) const;
    void setDatiAnagrafici();

signals:
    void signalUpdate();

public slots:
    void fillFields();
    void update();
    void disableUpdate();
    void enableUpdate(const QString&);
    void enableUpdate(const QDate&);

};

#endif // VIEWDATIANAGRAFICI_H
