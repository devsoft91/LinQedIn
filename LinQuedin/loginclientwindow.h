#ifndef LOGINCLIENTWINDOW_H
#define LOGINCLIENTWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LoginClientWindow : public QWidget{
    Q_OBJECT
private:
    QGridLayout* layout1;
    QGridLayout* layout2;
    QGridLayout* out_layout;
    QLabel* l_username;
    QLineEdit* username;
    QPushButton* b_login;

public:
    LoginClientWindow(QWidget *parent = 0);
    ~LoginClientWindow();

signals:
    void valueReady(const QString&);

public slots:
    void setU();

};

#endif // LOGINCLIENTWINDOW_H
