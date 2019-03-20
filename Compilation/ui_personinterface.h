/********************************************************************************
** Form generated from reading UI file 'personinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONINTERFACE_H
#define UI_PERSONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PersonInterface
{
public:
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonAddPerson;
    QLabel *labelTitle;
    QLineEdit *lineEditSurname;
    QLineEdit *lineEditName;
    QLabel *labelName;
    QLineEdit *lineEditParents;
    QLineEdit *lineEditQuery;
    QLabel *labelSurname;
    QPushButton *pushButtonAddPicture;
    QLabel *labelPicture;

    void setupUi(QDialog *PersonInterface)
    {
        if (PersonInterface->objectName().isEmpty())
            PersonInterface->setObjectName(QStringLiteral("PersonInterface"));
        PersonInterface->resize(569, 406);
        pushButtonCancel = new QPushButton(PersonInterface);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(260, 340, 93, 28));
        pushButtonAddPerson = new QPushButton(PersonInterface);
        pushButtonAddPerson->setObjectName(QStringLiteral("pushButtonAddPerson"));
        pushButtonAddPerson->setGeometry(QRect(140, 340, 93, 28));
        labelTitle = new QLabel(PersonInterface);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(220, 20, 76, 16));
        labelTitle->setAlignment(Qt::AlignCenter);
        lineEditSurname = new QLineEdit(PersonInterface);
        lineEditSurname->setObjectName(QStringLiteral("lineEditSurname"));
        lineEditSurname->setGeometry(QRect(452, 201, 74, 22));
        lineEditName = new QLineEdit(PersonInterface);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(118, 201, 73, 22));
        labelName = new QLabel(PersonInterface);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(41, 201, 42, 16));
        lineEditParents = new QLineEdit(PersonInterface);
        lineEditParents->setObjectName(QStringLiteral("lineEditParents"));
        lineEditParents->setGeometry(QRect(118, 248, 137, 22));
        lineEditQuery = new QLineEdit(PersonInterface);
        lineEditQuery->setObjectName(QStringLiteral("lineEditQuery"));
        lineEditQuery->setGeometry(QRect(118, 295, 137, 22));
        labelSurname = new QLabel(PersonInterface);
        labelSurname->setObjectName(QStringLiteral("labelSurname"));
        labelSurname->setGeometry(QRect(334, 201, 61, 16));
        pushButtonAddPicture = new QPushButton(PersonInterface);
        pushButtonAddPicture->setObjectName(QStringLiteral("pushButtonAddPicture"));
        pushButtonAddPicture->setGeometry(QRect(280, 90, 93, 28));
        labelPicture = new QLabel(PersonInterface);
        labelPicture->setObjectName(QStringLiteral("labelPicture"));
        labelPicture->setGeometry(QRect(140, 60, 84, 91));
        labelPicture->setFrameShape(QFrame::Box);
        labelPicture->setTextFormat(Qt::AutoText);
        labelPicture->setAlignment(Qt::AlignCenter);
        labelPicture->setMargin(0);

        retranslateUi(PersonInterface);

        QMetaObject::connectSlotsByName(PersonInterface);
    } // setupUi

    void retranslateUi(QDialog *PersonInterface)
    {
        PersonInterface->setWindowTitle(QApplication::translate("PersonInterface", "Dialog", 0));
        pushButtonCancel->setText(QApplication::translate("PersonInterface", "Cancel", 0));
        pushButtonAddPerson->setText(QApplication::translate("PersonInterface", "Add Person", 0));
        labelTitle->setText(QApplication::translate("PersonInterface", "Add a Person", 0));
        labelName->setText(QApplication::translate("PersonInterface", "Name :", 0));
        labelSurname->setText(QApplication::translate("PersonInterface", "Surname :", 0));
        pushButtonAddPicture->setText(QApplication::translate("PersonInterface", "Add Picture", 0));
        labelPicture->setText(QApplication::translate("PersonInterface", "Person Picture", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonInterface: public Ui_PersonInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONINTERFACE_H
