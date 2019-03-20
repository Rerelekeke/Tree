#ifndef PERSON_H
#define PERSON_H

#include<QString>
#include<QDate>
#include<QImage>
#include<tree.h>

class Person
{
public:
    Person();
    Person(QString name, QString surname, QString query);
    Person(QString name, QString surname, QString query, QString parents);
    Person(QString name, QString surname, QString query, QString parents, QDate birthDate);
    QString getName();
protected:
    QImage *picture;

signals:
    void add(Person person);


private:
    QString name;
    QString surname;
    QString query;
    QString parents;
    QDate birthDate;

};

#endif // PERSON_H
