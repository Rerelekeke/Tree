#include "maininterface.h"



MainInterface::MainInterface()
{
    createActions();
    createMenus();
    createToolbar();
    MainInterface::showMaximized();
}
void MainInterface::newTree(){
    TreeInterface *tree =  new TreeInterface();
    tree->show();

}

void MainInterface::createActions(){
    actionNew = new QAction(tr("&Nouveau"),this);
    actionNew->setShortcut(QKeySequence("Ctrl+N"));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newTree()));
    actionOpen = new QAction(tr("&Ouvrir"),this);
    actionOpen->setShortcut(QKeySequence("Ctrl+O"));
    actionSave = new QAction(tr("&Enregistrer"),this);
    actionSave->setShortcut(QKeySequence("Ctrl+S"));
    actionAddPerson = new QAction(tr("&Ajouter une nouvelle Personne"),this);
    actionAddPerson->setShortcut(QKeySequence("Ctrl++"));
    actionHelp = new QAction(tr("&Aide"),this);
    actionAbout = new QAction(tr("A &Propos"),this);
    actionQuit = new QAction(tr("&Quitter"),this);
}

void MainInterface::createMenus(){
    menuFile = menuBar()->addMenu(tr("&Fichier"));
    menuFile->addAction(actionNew);
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionQuit);

    menuHelp = menuBar()->addMenu(tr("&Aide"));
    menuHelp->addAction(actionHelp);
    menuHelp->addAction(actionAbout);
}

void MainInterface::createToolbar(){
    toolBar = addToolBar(tr("Barre d'Outils"));
    toolBar->addAction(actionAddPerson);
    toolBar->addAction(actionSave);



}


