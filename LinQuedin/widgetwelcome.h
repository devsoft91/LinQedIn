#ifndef WIDGETWELCOME_H
#define WIDGETWELCOME_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QFont>

class WidgetWelcome : public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout* v_layout;
    QVBoxLayout* v_layout_a;
    QVBoxLayout* v_layout_c;
    QGridLayout* g_layout;
    QWidget* login;
    QWidget* w_admin;
    QWidget* w_client;
    QLabel* welcome;
    QLabel* img_admin;
    QLabel* img_client;
    QLabel* l_admin;
    QLabel* l_client;
    QPixmap* p_admin;
    QPixmap* p_client;

    WidgetWelcome(QWidget *parent);

signals:
    void callAdmin();
    void callClient();

public slots:
    void checkStringLogin(const QString&);

};

#endif // WIDGETWELCOME_H
