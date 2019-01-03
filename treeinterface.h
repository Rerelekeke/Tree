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

class TreeInterface : public QDialog, private Tree
{
    Q_OBJECT
    
public:
    explicit TreeInterface(QWidget *parent = 0);
    ~TreeInterface();

    
public slots:
    void enableBackupPath();
    void browse();
    void treeCreation();
    
private:
    Ui::TreeInterface *ui;
    QDir *treePath;
    QDir *treeBackupPath;
    QString *treeName;
};

#endif // TREEINTERFACE_H
