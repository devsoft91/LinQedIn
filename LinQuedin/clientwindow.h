#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class ClientWindow : public QWidget{
    Q_OBJECT
public:
    QPushButton* button;
    QGridLayout* layout;
    ClientWindow(QWidget *parent);

signals:

public slots:
    
};

#endif // CLIENTWINDOW_H
