#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include "tree.h"

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "treeinterface.h"
#include "personinterface.h"

class MainInterface : public QMainWindow, private Tree
{
    Q_OBJECT
public:
    MainInterface();
    void createActions();
    void createMenus();
    void createToolbar();
    //void displayTree(Tree tree);

public slots:
    void newTree();
    void newPerson();
    void createCurrentTree();
    void addCurrentPerson(Person currentPerson);

signals:
    void signalAddNewPerson();

private:
    QToolBar *toolBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAddPerson;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionQuit;
	std::shared_ptr<Tree> tree;
    Person *person;
    TreeInterface *treeInterface;
    PersonInterface *personInterface;

};

#endif // MAININTERFACE_H
