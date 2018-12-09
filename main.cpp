#include <QApplication>
#include <QtWidgets>
#include "maininterface.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainInterface fenetre;
    fenetre.show();


    return app.exec();
}
