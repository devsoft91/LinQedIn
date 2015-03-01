#ifndef WIDGETLAUREA_H
#define WIDGETLAUREA_H

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QString>

class WidgetLaurea : public QWidget{
    Q_OBJECT
public:
    int id;
    QGridLayout* g_layout;
    QLineEdit* nomelaurea;
    QLineEdit* annolaurea;
    QLabel* l_nomelaurea;
    QLabel* l_annolaurea;
    QDialogButtonBox* buttonbox;
    QPushButton* aggiorna;
    QPushButton* elimina;
    WidgetLaurea(const QString&, const int&, const int&, QWidget *parent = 0);

signals:

public slots:

};

#endif // WIDGETLAUREA_H
