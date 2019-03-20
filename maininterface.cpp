#include "maininterface.h"
#include "treeinterface.h"


MainInterface::MainInterface()
{
    createActions();
    createMenus();
    createToolbar();
    MainInterface::showMaximized();
}
void MainInterface::newTree(){
    treeInterface =  new TreeInterface();
    connect(treeInterface,SIGNAL(signalReturnTree(Tree)),this, SLOT(createCurrentTree(Tree)));
    treeInterface->show();

}

void MainInterface::createCurrentTree(Tree currentTree){
    *tree = currentTree;
}



void MainInterface::newPerson(){

    personInterface =  new PersonInterface();
    connect(personInterface,SIGNAL(signalReturnPerson(Person)),this, SLOT(addCurrentPerson(Person)));
    personInterface->show();


}

void MainInterface::addCurrentPerson(Person currentPerson){
    *person = currentPerson;
}

//void MainInterface::newPerson(){
//    emit signalAddNewPerson();
////    if(!name.isEmpty()){
//        PersonInterface *person =  new PersonInterface();
//        connect(this,SIGNAL(add(person)),treeInterface, SLOT(addPerson(person)));
//        person->show();
////    }
////    else
////    {
////        QMessageBox msgBox;
////        msgBox.setText(tr("Error"));
////        msgBox.setStyleSheet("QMessageBox { width: 100 px }");
////        msgBox.setInformativeText(tr("You have to open a tree, first."));
////        msgBox.setStandardButtons(QMessageBox::Ok);
////        msgBox.setDefaultButton(QMessageBox::Ok);
////        msgBox.exec();
////    }

//}

void MainInterface::createActions(){
    actionNew = new QAction(tr("&Nouveau"),this);
    actionNew->setShortcut(QKeySequence("Ctrl+N"));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newTree()));
    actionOpen = new QAction(tr("&Ouvrir"),this);
    actionOpen->setShortcut(QKeySequence("Ctrl+O"));
    actionSave = new QAction(tr("&Enregistrer"),this);
    actionSave->setShortcut(QKeySequence("Ctrl+S"));
    actionAddPerson = new QAction(tr("&Ajouter une nouvelle Personne"),this);
    actionAddPerson->setShortcut(QKeySequence("Ctrl+U"));
    connect(actionAddPerson, SIGNAL(triggered()), this, SLOT(newPerson()));
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


