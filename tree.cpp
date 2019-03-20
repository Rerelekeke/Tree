#include "tree.h"


Tree::Tree()
{

//    emit add(*this);
}


Tree::Tree(QString name, QDateTime updateDate, QDir path, QDir backupPath)
{
    this->name = name;
    this->updateDate = &updateDate;
    this->path = path;
    this->backupPath = backupPath;

//    emit add(*this);
}
//void Tree::addPerson(Person person){
//    persons<<person;
//    qDebug()<<"bug addPerson"<<endl;
//    //    QString stringFile ="";
//    //    stringFile += person.name + "," + person.surname + ","
//    //            + person.query + "," + person.parents + "," + person.birthdate;
//    //    QFile file(path.path()+"/" + name + ".tree");
//    //    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//    //        return;
//    //    QTextStream flux(&file);
//    //    flux.setCodec("UTF-8");
//    //    flux << stringFile <<endl;
//}

