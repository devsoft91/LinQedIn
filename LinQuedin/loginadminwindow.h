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
    QGridLayout* layout1;
    QGridLayout* layout2;
    QGridLayout* out_layout;
    QLabel* l_pswd;
    QLineEdit* pswd;
    QPushButton* b_login;
    LoginAdminWindow(QWidget *parent = 0);
    ~LoginAdminWindow();

signals:
    void signalPassPswd(const QString&);

public slots:
    void checkPswd();

};

#endif // LOGINADMINWINDOW_H
