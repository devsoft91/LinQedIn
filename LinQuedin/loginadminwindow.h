#ifndef LOGINADMINWINDOW_H
#define LOGINADMINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LoginAdminWindow : public QWidget
{
    Q_OBJECT
public:
    QLabel* email_l;
    QLineEdit* email_e;
    QPushButton* login_b;
    LoginAdminWindow(QWidget *parent = 0);

signals:

public slots:

};

#endif // LOGINADMINWINDOW_H
