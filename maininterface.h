#ifndef MAININTERFACE_H
#define MAININTERFACE_H
#include "tree.h"

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "treeinterface.h"

class MainInterface : public QMainWindow
{
    Q_OBJECT
public:
    MainInterface();
    void createActions();
    void createMenus();
    void createToolbar();
    void displayTree(Tree tree);

public slots:
    void newTree();

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
    Tree *tree;

};

#endif // MAININTERFACE_H
