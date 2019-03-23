#include "tree.h"
#include <QMessageBox>
#include "time.h"
#include "TreeUnitTests.h"


TreeUnitTests::TreeUnitTests() {
	test = false;
	testInterface = true;
}

bool TreeUnitTests::getTest() {
	return test;
}

bool TreeUnitTests::getTestInterface() {
	return testInterface;
}

void message(QString msg) {
	QMessageBox msgBox;
	msgBox.setText("Error");
	msgBox.setInformativeText(msg);
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.setDefaultButton(QMessageBox::Ok);
	msgBox.exec();
}

void TreeUnitTests::DisplayMessage(QString str_display) {
	QMessageBox msgBox;
	msgBox.setText("Test");
	msgBox.setInformativeText(str_display);
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.setDefaultButton(QMessageBox::Ok);
	msgBox.exec();
}
void TreeUnitTests::CreationTreeTest() {

		// NE PAS MODIFIER LES VALEURS
		QString name = "test";
		QDir* path = new QDir("D:\\Dropbox\\Documents\\Codage\\C++\\Qt\\Tree\\Tests Results");
		QDir* backupPath = new QDir("D:\\Dropbox\\Documents\\Codage\\C++\\Qt\\Tree\\Tests Results\\Backup");
		QDateTime updateDate = QDateTime::currentDateTime();


		// SUPPRESSION DES FICHIERS TEST EXISTANTS

		QFile file(path->path() + "/" + name + ".tree");
		file.remove();
		QFile backupFile(backupPath->path() + "/" + name + ".tree");
		backupFile.remove();

		// MODIFIER VALEURS BACKUP PATH SI ON VEUT
		backupPath->setPath("");

		//CREATION DE L'ARBRE
			currentTree = new Tree(name, updateDate, *path, *backupPath);
			
		// VERIFICATION

		QFileInfo check_file(path->path() + "/" + name + ".tree");
		// check if file exists and if yes: Is it really a file and no directory?
		if (check_file.exists() && check_file.isFile()) {
		}
		else {
			message("Creation de l'arbre non effectuee");
		}

		QFileInfo check_Backupfile(backupPath->path() + "/" + name + ".tree");
		// check if file exists and if yes: Is it really a file and no directory?
		if (check_Backupfile.exists() && check_Backupfile.isFile() || backupPath->path() == "") {
		}
		else {
			message("Creation du backup de l'arbre non effectuee");
		}

		
	}

void TreeUnitTests::AddingSonAndParents() {

	// CREATION OF TREE BEFIRE
	
	currentTree->newPerson(std::make_shared<Person>("Annick", "Demongeot", "demongeot,annick", "Eliane Demongeot, Claude Demongeot", QDate::fromString("28/07/1962", "dd/MM/yyyy"), "D:\\Dropbox\\Documents\\Codage\\C++\\Qt\\Tree\\Tests Results\\Annick Demongeot.jpg"));
	currentTree->newPerson(std::make_shared<Person>("Jean-marc", "Thiriet", "jean-marc,thiriet", "Claude THIRIET, Marie-Thérèse THIRIET", QDate::fromString("21/02/1962", "dd/MM/yyyy"), "D:\\Dropbox\\Documents\\Codage\\C++\\Qt\\Tree\\Tests Results\\Jean-marc Thiriet.jpg"));
	currentTree->newPerson(std::make_shared<Person>("Rémi", "Thiriet", "remi,thiriet,rémi", "Annick Demongeot, Jean-Marc THIRIET", QDate::fromString("01/08/1993", "dd/MM/yyyy"), "D:\\Dropbox\\Documents\\Codage\\C++\\Qt\\Tree\\Tests Results\\Rémi THIRIET.jpg"));

	if (TreeUnitTests().getTestInterface()) {

		TreeUnitTests().DisplayMessage(currentTree->Test_DiplayTree());

	}


}



