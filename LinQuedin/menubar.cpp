#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent){
    QAction* action_new_client = new QAction(QIcon(":/immagini/client.png"),"Client",this);
    QAction* action_new_admin = new QAction(QIcon(":/immagini/admin.png"),"Administrator",this);
    QAction* action_save = new QAction(QIcon(":/immagini/save.png"),"Save",this);
    QAction* action_close = new QAction(QIcon(":/immagini/exit.png"),"Exit",this);

    QKeySequence newClient(Qt::ALT + Qt::Key_C);
    QKeySequence newAdmin(Qt::ALT + Qt::Key_A);
    QKeySequence save(Qt::CTRL + Qt::Key_S);
    QKeySequence close(Qt::CTRL + Qt::Key_Q);

    action_new_client->setShortcut(newClient);
    action_new_admin->setShortcut(newAdmin);
    action_save->setShortcut(save);
    action_close->setShortcut(close);

    QMenu* menufile = new QMenu("File");
    QMenu* menufile_newinstance = new QMenu("New Instance");
    menufile_newinstance->addAction(action_new_client);
    menufile_newinstance->addAction(action_new_admin);
    menufile_newinstance->setIcon(QIcon(":/immagini/new.png"));
    menufile->addMenu(menufile_newinstance);
    menufile->addSeparator();
    menufile->addAction(action_save);
    menufile->addSeparator();
    menufile->addAction(action_close);
    addMenu(menufile);

    QMenu* menuedit = new QMenu("Edit");
    menuedit->addAction("Undo");
    menuedit->addAction("Redo");
    menuedit->addSeparator();
    menuedit->addAction("Cut");
    menuedit->addAction("Copy");
    menuedit->addAction("Paste");
    addMenu(menuedit);

    QMenu* menutools = new QMenu("Tools");
    QMenu* menutools_options = new QMenu("Options");
    menutools_options->addAction("Language");
    menutools_options->addAction("Design");
    menutools_options->addAction("Info");
    menutools->addMenu(menutools_options);
    addMenu(menutools);

    connect(action_new_client, SIGNAL(triggered()), parent, SLOT(showLoginClient()));
    connect(action_new_admin, SIGNAL(triggered()), parent, SLOT(showLoginAdmin()));
    connect(action_save, SIGNAL(triggered()), parent, SLOT(saveConfirm()));
    connect(action_close, SIGNAL(triggered()), parent, SLOT(close()));
}
