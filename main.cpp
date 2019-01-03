#include <QApplication>
#include <QtWidgets>
#include "maininterface.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/favicon.ico"));

    MainInterface fenetre;
    fenetre.show();


    return app.exec();
}
