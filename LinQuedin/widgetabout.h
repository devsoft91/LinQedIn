#ifndef WIDGETABOUT_H
#define WIDGETABOUT_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QPixmap>
#include <QFont>

class WidgetAbout : public QWidget
{
    Q_OBJECT
public:
    QDialog* box;
    QGridLayout* g_layout;
    QVBoxLayout* v_layout1;
    QVBoxLayout* v_layout2;
    QLabel* l_image;
    QLabel* info1;
    QLabel* info2;
    QLabel* info3;
    QLabel* info4;
    QLabel* info5;
    QDialogButtonBox* buttonbox;
    QPushButton* chiudi;
    WidgetAbout(QWidget *parent = 0);

signals:

public slots:

};

#endif // WIDGETABOUT_H
