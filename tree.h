#ifndef TREE_H
#define TREE_H

#include<QString>
#include<QDate>
#include<QDir>
#include <QDialog>
#include <person.h>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include <QVBoxLayout>
#include <tree.h>

class Tree
{
public:
    Tree();
    Tree(QString name, QDateTime updateDate, QDir path, QDir backupPath);
//    void modifyPerson(Person person);


public slots:
//    void addPerson(Person person);
    void acceptNewPerson();

//signals:
//    void add(Tree tree);

protected:
    QString name;
    QDateTime *updateDate;
    QDir path;
    QDir backupPath;

private:
//    QList<Person> persons;
};

#endif // TREE_H
