#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent){
    action_new_client = new QAction(QIcon(":/immagini/client.png"),"Client",this);
    action_new_admin = new QAction(QIcon(":/immagini/admin.png"),"Administrator",this);
    action_logout = new QAction(QIcon(":/immagini/logout.png"),"Logout",this);
    action_save = new QAction(QIcon(":/immagini/save.png"),"Save",this);
    action_close = new QAction(QIcon(":/immagini/exit.png"),"Exit",this);

    QKeySequence newClient(Qt::ALT + Qt::Key_C);
    QKeySequence newAdmin(Qt::ALT + Qt::Key_A);
    QKeySequence logout(Qt::CTRL + Qt::Key_W);
    QKeySequence save(Qt::CTRL + Qt::Key_S);
    QKeySequence close(Qt::CTRL + Qt::Key_Q);

    action_new_client->setShortcut(newClient);
    action_new_admin->setShortcut(newAdmin);
    action_logout->setShortcut(logout);action_logout->setEnabled(false);
    action_save->setShortcut(save);action_save->setEnabled(false);
    action_close->setShortcut(close);

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
    menuedit->addAction("Undo");
    menuedit->addAction("Redo");
    menuedit->addSeparator();
    menuedit->addAction("Cut");
    menuedit->addAction("Copy");
    menuedit->addAction("Paste");
    addMenu(menuedit);

    connect(action_new_client, SIGNAL(triggered()), parent, SLOT(showLoginClientWindow()));
    connect(action_new_admin, SIGNAL(triggered()), parent, SLOT(showLoginAdminWindow()));
    connect(action_logout, SIGNAL(triggered()), parent, SLOT(logout()));
    connect(action_save, SIGNAL(triggered()), parent, SLOT(saveConfirm()));
    connect(action_save, SIGNAL(triggered()), this, SLOT(disableSave()));
    connect(action_close, SIGNAL(triggered()), parent, SLOT(close()));
}

//slot
void MenuBar::changeMenuLogin(){
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
