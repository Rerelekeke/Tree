#include "person.h"


Person::Person()
{

//    emit add(*this);
}

Person::Person(QString name, QString surname, QString query){
    this->name = name;
    this->surname = surname;
    this->query = query;
//    emit add(*this);
}
Person::Person(QString name, QString surname, QString query, QString parents){
    this->name = name;
    this->surname = surname;
    this->query = query;
    this->parents = parents;
//    emit add(*this);
}
Person::Person(QString name, QString surname, QString query, QString parents, QDate birthDate){
    this->name = name;
    this->surname = surname;
    this->query = query;
    this->parents = parents;
    this->birthDate = birthDate;
//    emit add(*this);
}
Person::Person(QString name, QString surname, QString query, QString parents, QDate birthDate, QString picturePath) {
	this->name = name;
	this->surname = surname;
	this->query = query;
	this->parents = parents;
	this->birthDate = birthDate;
	this->picture = new QImage(picturePath);
	//    emit add(*this);
}


QString Person::getName(){
    return name;
}

QString Person::getSurname()
{
	return surname;
}

QImage* Person::getPicture()
{
	return picture;
}
