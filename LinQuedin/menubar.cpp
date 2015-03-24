#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent){
    action_new_client = new QAction(QIcon(":/immagini/client.png"),"Client",this);
    action_new_admin = new QAction(QIcon(":/immagini/admin.png"),"Administrator",this);
    action_logout = new QAction(QIcon(":/immagini/logout.png"),"Logout",this);
    action_save = new QAction(QIcon(":/immagini/save.png"),"Save",this);
    action_close = new QAction(QIcon(":/immagini/exit.png"),"Exit",this);
    action_find = new QAction(QIcon(":/immagini/find.png"),"Find",this);
    action_about = new QAction(QIcon(":/immagini/about.png"),"About LinQedin",this);

    QKeySequence newClient(Qt::ALT + Qt::Key_C);
    QKeySequence newAdmin(Qt::ALT + Qt::Key_A);
    QKeySequence logout(Qt::CTRL + Qt::Key_W);
    QKeySequence save(Qt::CTRL + Qt::Key_S);
    QKeySequence close(Qt::CTRL + Qt::Key_Q);
    QKeySequence find(Qt::CTRL + Qt::Key_F);
    QKeySequence about(Qt::CTRL + Qt::Key_I);

    action_new_client->setShortcut(newClient);
    action_new_admin->setShortcut(newAdmin);
    action_logout->setShortcut(logout);action_logout->setEnabled(false);
    action_save->setShortcut(save);action_save->setEnabled(false);
    action_close->setShortcut(close);
    action_find->setShortcut(find);action_find->setEnabled(false);
    action_about->setShortcut(about);

    menufile = new QMenu("File");
    menufile_newinstance = new QMenu("New Instance");
    menufile_newinstance->addAction(action_new_client);
    menufile_newinstance->addAction(action_new_admin);
    menufile_newinstance->setIcon(QIcon(":/immagini/new.png"));
    menufile->addMenu(menufile_newinstance);
    menufile->addAction(action_logout);
    menufile->addSeparator();
    menufile->addAction(action_save);
    menufile->addSeparator();
    menufile->addAction(action_close);
    addMenu(menufile);

    menuedit = new QMenu("Edit");
    menuedit->addAction(action_find);
    addMenu(menuedit);

    menuhelp = new QMenu("Help");
    menuhelp->addAction(action_about);
    addMenu(menuhelp);

    connect(action_new_client, SIGNAL(triggered()), parent, SLOT(showLoginClientWindow()));
    connect(action_new_admin, SIGNAL(triggered()), parent, SLOT(showLoginAdminWindow()));
    connect(action_logout, SIGNAL(triggered()), this, SLOT(checkSaveOn()));
    connect(this, SIGNAL(logoutSave(bool)), parent, SLOT(logout(bool)));
    connect(action_save, SIGNAL(triggered()), parent, SLOT(saveConfirm()));
    connect(action_save, SIGNAL(triggered()), this, SLOT(disableSave()));
    connect(action_close, SIGNAL(triggered()), parent, SLOT(close()));
    connect(action_find, SIGNAL(triggered()), parent, SLOT(callFormRicerca()));
}

//slot
void MenuBar::checkSaveOn(){
    if(action_save->isEnabled()){
        emit logoutSave(true);
    }
    else emit logoutSave(false);
}

//slot
void MenuBar::enableMenuLogin(){
    menufile_newinstance->setDisabled(false);
    action_new_client->setDisabled(false);
    action_new_admin->setDisabled(false);
    action_logout->setDisabled(true);
    action_save->setDisabled(true);
}

//slot
void MenuBar::disableMenuLogin(){
    menufile_newinstance->setDisabled(true);
    action_new_client->setDisabled(true);
    action_new_admin->setDisabled(true);
    action_logout->setDisabled(false);
}

//slot
void MenuBar::enableSave(){
    action_save->setDisabled(false);
}

//slot
void MenuBar::disableSave(){
    action_save->setDisabled(true);
}

//slot
void MenuBar::cancelState(){
    menufile_newinstance->setEnabled(false);
    action_new_client->setEnabled(false);
    action_new_admin->setEnabled(false);
    action_logout->setEnabled(true);
    action_save->setEnabled(true);
}

//slot
void MenuBar::enableFind(){
    action_find->setEnabled(true);
}

//slot
void MenuBar::disableFind(){
    action_find->setEnabled(false);
}
