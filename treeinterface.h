#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

#include <QDialog>
#include <QFileDialog>
#include <QLineEdit>
#include <tree.h>
#include <QMessageBox>
#include <stdio.h>
#include <QFile>
#include <QTextStream>
using namespace std;


namespace Ui {
class TreeInterface;
}

class TreeInterface : public QDialog
{
    Q_OBJECT
    
public:
    explicit TreeInterface(QWidget *parent = 0);
    ~TreeInterface();

    
public slots:
    void enableBackupPath();
    void browse(bool pathType);
    void createTree();
    
signals:
    void signalReturnTree(Tree);

private:
    Ui::TreeInterface *ui;
    QDir path;
    QDir backupPath;
};

#endif // TREEINTERFACE_H
