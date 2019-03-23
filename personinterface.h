#ifndef PERSONINTERFACE_H
#define PERSONINTERFACE_H

#include <QDialog>
#include <QFileDialog>
#include <person.h>
#include <QImage>
#include <QMessageBox>
#include <QGridLayout>
#include <QFormLayout>
#include <picturereader.h>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>

class PersonInterface : public QDialog, private Person
{
    Q_OBJECT


public:
    PersonInterface();
    ~PersonInterface();
	std::shared_ptr<Person> getCurrentPerson();

    QLabel *labelPicture;



public slots:
    void AddPicture();
    void CreatePerson();
    void ModifyPicture(QImage picture_temp);
    void Cancel();

signals:
    void signalReturnPerson(std::shared_ptr<Person> person);

private:
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonAddPerson;
    QLabel *labelTitle;
    QLineEdit *lineEditSurname;
    QLineEdit *lineEditName;
    QLabel *labelName;
    QLabel *labelParents;
    QLabel *labelQuery;
    QLineEdit *lineEditParents;
    QLineEdit *lineEditQuery;
    QLabel *labelBirthdate;
    QDateEdit *dateEditBirthdate;
    QLabel *labelSurname;
    QPushButton *pushButtonAddPicture;
	std::shared_ptr<Person> currentPerson;

};

#endif // PERSONINTERFACE_H
