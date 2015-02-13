#ifndef VIEWPROFILO_H
#define VIEWPROFILO_H

#include <QWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QGridLayout>

class ViewProfilo : public QWidget
{
    Q_OBJECT
public:
    QGroupBox* datianagrafici;
    QGroupBox* titolistudio;
    QGroupBox* impieghi;
    QVBoxLayout* layout;
    QGridLayout* layoutbox;
    QLineEdit* nome;

    ViewProfilo(QWidget *parent = 0);

signals:

public slots:

};

#endif // VIEWPROFILO_H
