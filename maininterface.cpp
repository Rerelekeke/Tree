#include "maininterface.h"
#include "treeinterface.h"
#include "TreeUnitTests.h"


MainInterface::MainInterface()
{


	createActions();
	createMenus();
	createToolbar();
	MainInterface::showMaximized();
	if (TreeUnitTests().getTestInterface()) {

		//TreeUnitTests* tests = new TreeUnitTests();
		//tests->CreationTreeTest();
		//tests->AddingSonAndParents();
		//actionAddPerson->setEnabled(true);

	}


}
void MainInterface::newTree() {
	treeInterface = new TreeInterface();
	connect(treeInterface, SIGNAL(signalReturnTree()), this, SLOT(createCurrentTree()));
	treeInterface->show();

}

void MainInterface::createCurrentTree() {
	tree = treeInterface->getCurrentTree();
	actionAddPerson->setEnabled(true);
}



void MainInterface::newPerson() {
	//if (tree != NULL) {
	personInterface = new PersonInterface();
	connect(personInterface, SIGNAL(signalReturnPerson(std::shared_ptr<Person>)), this, SLOT(addCurrentPerson(std::shared_ptr<Person>)));
	personInterface->show();
	//}
	//else {
	//	QMessageBox msgBox;
	//	msgBox.setText("Attention");
	//	msgBox.setInformativeText(tr("please open or create a tree");
	//	msgBox.setStandardButtons(QMessageBox::Ok);
	//	msgBox.setDefaultButton(QMessageBox::Ok);
	//	msgBox.exec();
	//}




}

void MainInterface::addCurrentPerson(std::shared_ptr<Person> currentPerson) {
	person = currentPerson;

	tree->newPerson(person);
	DisplayTree();
	this->update();

	if (TreeUnitTests().getTestInterface()) {

		TreeUnitTests().DisplayMessage(tree->Test_DiplayTree());

	}



}

void MainInterface::DisplayTree() {



	QList<std::shared_ptr<Person>> persons = tree->getListPerson();
	QVBoxLayout *layoutPrincipal = new QVBoxLayout;
	QWidget * screen = new QWidget();


	//picRead = new QImage(persons.at(0)->getPicture()->scaled(labelPicture->width(), labelPicture->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));


	

	for (int i = 0; i < persons.size(); i++) {
	QGridLayout *layoutTree = new QGridLayout();
	labelPicture = new QLabel();
	//labelPicture->setObjectName(QStringLiteral("labelPicture"));
	//labelPicture->setGeometry(QRect(30, 20, 341, 201));
	//labelPicture->setFrameShape(QFrame::Box);
	labelName = new QLabel();
	//picRead = persons.at(i)->getPicture()->scaled(labelPicture->width(), labelPicture->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	//picRead = std::make_shared<QImage>(persons.at(i)->getPicture()->scaled(labelPicture->width(), labelPicture->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	//labelPicture->setPixmap(QPixmap::fromImage(QImage("D:\\Dropbox\\Documents\\Codage\\C++\\Qt\\Tree\\Tests Results\\Annick Demongeot.jpg")));

	//picRead = new QImage();
	/*picRead = std::make_shared<QImage>(persons.at(i)->getPicture());
	labelPicture->setPixmap(QPixmap::fromImage(*picRead));*/
	labelPicture->setFrameStyle(0);


	labelPicture->setFrameStyle(0);
	labelName->setText(persons.at(0)->getName() + persons.at(0)->getSurname());
	layoutTree->addWidget(labelPicture, 1, 1);
	layoutTree->addWidget(labelName, 1, 2);
	layoutPrincipal->addLayout(layoutTree);

	}
	screen->setLayout(layoutPrincipal);

	this->setCentralWidget(screen);


	/*


		QList<std::shared_ptr<Person>> persons = tree->getListPerson();
		QVBoxLayout *layoutPrincipal = new QVBoxLayout;
		QImage *picRead;
		QLabel *labelPicture;
		QLabel *labelName;
		for each (person in persons) {
			QGridLayout *layoutTree = new QGridLayout();
			picRead = new QImage(person->getPicture()->scaled(labelPicture->width(), labelPicture->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
			labelPicture->setPixmap(QPixmap::fromImage(*picRead));
			labelPicture->move((this->width() - picRead->width()) / 2, 40);
			labelPicture->setFrameStyle(0);
			labelName->setText(person->getName() + person->getSurname());
			layoutTree->addWidget(labelPicture, 1, 1);
			layoutTree->addWidget(labelName, 1, 2);
			layoutPrincipal->addLayout(layoutTree);

		}
		this->setLayout(layoutPrincipal);
	*/

}



void MainInterface::createActions() {
	actionNew = new QAction(tr("&Nouveau"), this);
	actionNew->setShortcut(QKeySequence("Ctrl+N"));
	connect(actionNew, SIGNAL(triggered()), this, SLOT(newTree()));
	actionOpen = new QAction(tr("&Ouvrir"), this);
	actionOpen->setShortcut(QKeySequence("Ctrl+O"));
	actionSave = new QAction(tr("&Enregistrer"), this);
	actionSave->setShortcut(QKeySequence("Ctrl+S"));
	actionAddPerson = new QAction(tr("&Ajouter une nouvelle Personne"), this);
	actionAddPerson->setShortcut(QKeySequence("Ctrl+U"));
	connect(actionAddPerson, SIGNAL(triggered()), this, SLOT(newPerson()));
	actionAddPerson->setShortcut(QKeySequence("Ctrl++"));
	actionHelp = new QAction(tr("&Aide"), this);
	actionAbout = new QAction(tr("A &Propos"), this);
	actionQuit = new QAction(tr("&Quitter"), this);
}

void MainInterface::createMenus() {
	menuFile = menuBar()->addMenu(tr("&Fichier"));
	menuFile->addAction(actionNew);
	menuFile->addAction(actionOpen);
	menuFile->addAction(actionSave);
	menuFile->addAction(actionQuit);

	menuHelp = menuBar()->addMenu(tr("&Aide"));
	menuHelp->addAction(actionHelp);
	menuHelp->addAction(actionAbout);
}

void MainInterface::createToolbar() {
	toolBar = addToolBar(tr("Barre d'Outils"));
	toolBar->addAction(actionAddPerson);
	actionAddPerson->setEnabled(false);
	toolBar->addAction(actionSave);



}


