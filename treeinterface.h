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
	Tree getCurrentTree();
    ~TreeInterface();

    
public slots:
    void enableBackupPath();
    void browsePath();
	void browseBackupPath();
    void createTree();
    
signals:
    void signalReturnTree();

private:
    Ui::TreeInterface *ui;
	std::unique_ptr<Tree>  currentTree;
	void browse(bool pathType);
    QDir path;
    QDir backupPath;
	QString treeName;
	QDateTime updateDate;
};

#endif // TREEINTERFACE_H
