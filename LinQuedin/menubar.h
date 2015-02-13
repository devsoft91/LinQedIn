#ifndef MENUBAR_H
#define MENUBAR_H

#include <QtWidgets/QMenuBar>
#include <QAction>

class MenuBar : public QMenuBar{
    Q_OBJECT
private:
    QMenu* menufile;
    QMenu* menuedit;
    QMenu* menufile_newinstance;
    QMenu* logout;
    QAction* action_new_client;
    QAction* action_new_admin;
    QAction* action_logout;
    QAction* action_save;
    QAction* action_close;
public:
    MenuBar(QWidget *parent = 0);

signals:

public slots:
    void changeMenuLogin();

};

#endif // MENUBAR_H
