#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    setWindowIcon(QIcon(":/immagini/linkedin.png"));

    QAction* action_save = new QAction(QIcon(":/immagini/save.png"),"Save",this);
    QAction* action_close = new QAction(QIcon(":/immagini/exit.png"),"Exit",this);

    QKeySequence save(Qt::CTRL + Qt::Key_S);
    QKeySequence close(Qt::ALT + Qt::Key_F4);

    action_save->setShortcut(save);
    action_close->setShortcut(close);

    //setObjectName(QStringLiteral("MainWindow"));
    resize(400, 300);
    menuBar = new QMenuBar(this);

    QMenu* menufile = new QMenu("File");
    menufile->addAction(action_save);
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

    setMenuBar(menuBar);/*
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    addToolBar(mainToolBar);*/
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    setCentralWidget(centralWidget);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    setStatusBar(statusBar);
    connect(action_close, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}
