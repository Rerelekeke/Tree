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
	static void CreationTreeTest();

private :
	bool test;
	bool testInterface;

};

#endif // TREEUNITTESTS_H
