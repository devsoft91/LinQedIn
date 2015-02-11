#ifndef LOGINCLIENTWINDOW_H
#define LOGINCLIENTWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LoginClientWindow : public QWidget{
    Q_OBJECT
public:
    QLabel* email_l;
    QLineEdit* email_e;
    QPushButton* login_b;
    QGridLayout* layout;
    LoginClientWindow(QWidget *parent = 0);
    ~LoginClientWindow();

signals:

public slots:

};

#endif // LOGINCLIENTWINDOW_H
