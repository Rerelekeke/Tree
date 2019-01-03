#ifndef TREE_H
#define TREE_H

#include<QString>
#include<QDate>
#include<QDir>
#include <QDialog>
#include"person.h"
#include <QList>

class Tree
{
public:
    Tree();
    void addPerson(Person person);
    void modifyPerson(Person person);

protected:
    QString name;
    QDateTime *updateDate;
    QDir path;
    QDir backupPath;
private:

    QList<Person> persons;
};

#endif // TREE_H
