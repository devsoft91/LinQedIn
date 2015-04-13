#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QAction>

class MenuBar : public QMenuBar{
    Q_OBJECT    
public:
    QMenu* menufile;
    QMenu* menuedit;
    QMenu* menuhelp;
    QMenu* menufile_newinstance;
    QMenu* logout;
    QAction* action_new_client;
    QAction* action_new_admin;
    QAction* action_logout;
    QAction* action_save;
    QAction* action_close;
    QAction* action_find;
    QAction* action_about;
    MenuBar(QWidget *parent = 0);

signals:
    void logoutSave(bool);
    void exitSave(bool);
    void signalCheckSaveOn(const QString&);

public slots:
    void checkSaveOn(const QString&);
    void enableMenuLogin();
    void disableMenuLogin();
    void enableSave();
    void disableSave();
    void cancelState();
    void enableFind();
    void disableFind();
    void triggeredLogout();
    void triggeredClose();

};

#endif // MENUBAR_H
