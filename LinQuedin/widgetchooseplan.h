#ifndef WIDGETCHOOSEPLAN_H
#define WIDGETCHOOSEPLAN_H

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>

#include "admin.h"

class WidgetChoosePlan : public QWidget
{
    Q_OBJECT
public:
    QDialog* box;
    QVBoxLayout* v_layout;
    QRadioButton* basic;
    QRadioButton* business;
    QRadioButton* executive;
    QDialogButtonBox* buttonbox;
    QPushButton* conferma;
    QPushButton* annulla;

    int type;
    QString user;
    Admin* tmp;

    WidgetChoosePlan(QWidget *parent,Admin*,const QString&);

signals:
    void sendSaveOn();
    void sendMessage(const QString&);

public slots:
    void updatePlan();

};

#endif // WIDGETCHOOSEPLAN_H
