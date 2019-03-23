#pragma once
#ifndef TREEUNITTESTS_H
#define TREEUNITTESTS_H

#include<QString>
#include<QDate>
#include<QImage>
#include<tree.h>

class TreeUnitTests {

public:

	TreeUnitTests();
	bool getTest();
	bool getTestInterface();
	 void CreationTreeTest();
	 void AddingSonAndParents();
	 static void DisplayMessage(QString str_display);
	

private :
	bool test;
	bool testInterface;
	Tree* currentTree;
	

};

#endif // TREEUNITTESTS_H
