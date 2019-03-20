#include <QApplication>
#include <QtWidgets>
#include "maininterface.h"
#include "TreeUnitTests.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/favicon.ico"));


	if (TreeUnitTests().getTest()) 
	{
		TreeUnitTests* tests = new TreeUnitTests();
		tests->CreationTreeTest();
		return 0;
	}
	else {
		MainInterface fenetre;
		fenetre.show();
		return app.exec();
	}



}
