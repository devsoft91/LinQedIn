#ifndef VIEWTITOLISTUDIO_H
#define VIEWTITOLISTUDIO_H

#include <QWidget>
#include <list>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

#include "widgetlaurea.h"
#include "widgetnewlaurea.h"
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
    QLineEdit* tmp_nomediploma;
    QSpinBox* tmp_annodiploma;
    QLabel* l_nomediploma;
    QLabel* l_annodiploma;
    QDialogButtonBox* buttonbox;
    QPushButton* modifica;
    QPushButton* annulla;
    QPushButton* addLaurea;

    WidgetNewLaurea* dialog1;
    WidgetUpdateLaurea* dialog2;

    Client* tmp;
    vector<Laurea> vector_lauree;

    ViewTitoliStudio(QWidget *parent,Client*);
    TitoliStudio* getTitoliStudio(Client*) const;
    void setDiploma();

signals:
    void callSaveOn();

public slots:
    void updateView();
    void addLBox();
    void addUBox(const QString&,int,WidgetLaurea*);
    void fetchNewLaurea(QLineEdit*,QSpinBox*);
    void fetchUpdateLaurea(WidgetLaurea*,QLineEdit*,QSpinBox*);
    void updateAfterRemove(WidgetLaurea*);
    void updateDiploma();
    void disableUpdate();
    void backData();
    void enableUpdate(const QString&);
    void enableUpdate(int);

};

#endif // VIEWTITOLISTUDIO_H
