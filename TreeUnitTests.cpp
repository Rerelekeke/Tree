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
			Tree *currentTree = new Tree(name, updateDate, *path, *backupPath);
			
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
		if (check_Backupfile.exists() && check_Backupfile.isFile()) {
		}
		else {
			message("Creation du backup de l'arbre non effectuee");
		}

		
	}



