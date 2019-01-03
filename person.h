#ifndef PERSON_H
#define PERSON_H

#include<QString>
#include<QDate>


class Person
{
public:
    Person();
    Person(QString name, QString surname, QString query);
    Person(QString name, QString surname, QString query, Person parents[]);
    Person(QString name, QString surname, QString query, Person parents[], QDate birthDate);
private:
    QString name;
    QString surname;
    QString query;
    QDate birthDate;
    Person *parents[];
};

#endif // PERSON_H
