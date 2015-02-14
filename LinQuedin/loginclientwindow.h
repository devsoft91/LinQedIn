#ifndef LOGINCLIENTWINDOW_H
#define LOGINCLIENTWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

#include <iostream>
using std::cout;

class LoginClientWindow : public QWidget{
    Q_OBJECT
private:
    QLabel* l_username;
    QLineEdit* username;
    QPushButton* b_login;
    QGridLayout* layout;
public:
    LoginClientWindow(QWidget *parent = 0);
    ~LoginClientWindow();

signals:
    void valueReady(const QString&);

public slots:
    void setU();

};

#endif // LOGINCLIENTWINDOW_H
