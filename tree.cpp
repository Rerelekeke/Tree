#include "tree.h"


Tree::Tree()
{

//    emit add(*this);
}



Tree::Tree(QString name, QDateTime updateDate, QDir path, QDir backupPath)
{
	QString stringFile;
	stringFile += name + "\n";
	stringFile += updateDate.toString("yyyy/MM/dd hh:mm:ss") + "\n";
	stringFile += path.path() + "\n";
	if (backupPath.path() != "") stringFile += backupPath.path() + "\n";
	else stringFile += "BE CAREFUL, NO BACKUP \n";
	stringFile += "name,surname,query,parents,birthdate";
	
	// We create the directory if needed
	if (!path.exists(path.path() + "/"))
		path.mkpath(path.path() + "/");

	  
	QFile file(path.path() + "/" + name + ".tree");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	QTextStream flux(&file);
	flux.setCodec("UTF-8");
	flux << stringFile << endl;

	qDebug() << path.path() + "/" + name + ".tree" << endl;
	if (backupPath.path() != "") {
		// We create the directory if needed
		if (!backupPath.exists(backupPath.path() + "/"))
			backupPath.mkpath(backupPath.path() + "/");

		qDebug() << backupPath.path() + "/" + name + ".tree" << endl;
		QFile file(backupPath.path() + "/" + name + ".tree");
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
			return;
		QTextStream flux(&file);
		flux.setCodec("UTF-8");
		flux << stringFile << endl;
	}



    this->name = name;
    this->updateDate = &updateDate;
    this->path = path;
    this->backupPath = backupPath;
	persons = new QList<std::shared_ptr<Person>>();

//    emit add(*this);
}
void Tree::newPerson(std::shared_ptr<Person> person)
{
	*persons<<person;

}

QString Tree::Test_DiplayTree()
{
	QString str_tmp="";
	for (int i =0; i<persons->size();i++)
	{
		str_tmp += persons->at(i)->getName() + "\n";
	}
	return str_tmp;
}
QList<std::shared_ptr<Person>> Tree::getListPerson()
{
	return *persons;
}
//void Tree::addPerson(Person person){
//    persons<<person;

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

