#ifndef WIDGETNEWLAUREA_H
#define WIDGETNEWLAUREA_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>

class WidgetNewLaurea : public QWidget
{
    Q_OBJECT
public:
    QDialog* box;
    QGridLayout* layout;
    QLineEdit* nomelaurea;
    QSpinBox* annolaurea;
    QLabel* l_nomelaurea;
    QLabel* l_annolaurea;
    QDialogButtonBox* buttonbox;
    QPushButton* aggiungi;
    QPushButton* annulla;
    WidgetNewLaurea(QWidget *parent = 0);

signals:
    void callFetchNewLaurea(QLineEdit*,QSpinBox*);

public slots:
    void newLaureaReady();

};

#endif // WIDGETNEWLAUREA_H
