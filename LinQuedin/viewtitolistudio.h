#ifndef VIEWTITOLISTUDIO_H
#define VIEWTITOLISTUDIO_H

#include <QWidget>
#include <list>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>

#include "widgetlaurea.h"
#include "client.h"

using std::list;

class ViewTitoliStudio : public QWidget
{
    Q_OBJECT
public:
    QGroupBox* b_diploma;
    QGroupBox* b_lauree;
    QVBoxLayout* v_layout;
    QVBoxLayout* lauree_layout;
    QGridLayout* g_layout;
    QLineEdit* nomediploma;
    QSpinBox* annodiploma;
    QLabel* l_nomediploma;
    QLabel* l_annodiploma;
    QPushButton* confirm;
    QPushButton* discard;

    Client* tmp;
    vector<Laurea> vector_lauree;

    list<WidgetLaurea*> list_lauree;
    ViewTitoliStudio(QWidget *parent,Client*);
    TitoliStudio* getTitoliStudio(Client*) const;
    void setTitoliStudio();

signals:

public slots:
    void updateView();

};

#endif // VIEWTITOLISTUDIO_H
