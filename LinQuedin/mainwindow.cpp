#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linkedin.png"));
    setWindowTitle("LinQedIn");
    setGeometry(400,150,600,500);

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

    menuBar = new QMenuBar(this);

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
    menuBar->addMenu(menufile);

    QMenu* menuedit = new QMenu("Edit");
    menuedit->addAction("Undo");
    menuedit->addAction("Redo");
    menuedit->addSeparator();
    menuedit->addAction("Cut");
    menuedit->addAction("Copy");
    menuedit->addAction("Paste");
    menuBar->addMenu(menuedit);

    QMenu* menutools = new QMenu("Tools");
    QMenu* menutools_options = new QMenu("Options");
    menutools_options->addAction("Language");
    menutools_options->addAction("Design");
    menutools_options->addAction("Info");
    menutools->addMenu(menutools_options);
    menuBar->addMenu(menutools);
    setMenuBar(menuBar);

    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    setCentralWidget(centralWidget);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    setStatusBar(statusBar);
    connect(action_save, SIGNAL(triggered()), this, SLOT(close()));
    connect(action_close, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}
