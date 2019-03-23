#include "personinterface.h"
#include <QDebug>
#include "person.h"
#include "tree.h"
#include "TreeUnitTests.h"

PersonInterface::PersonInterface(){
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    QGridLayout *layoutPicture = new QGridLayout();
    QGridLayout *layoutGrid = new QGridLayout();
    QGridLayout *layoutButtons = new QGridLayout();
    labelTitle=new QLabel();
    labelTitle->setText(tr("ADD A PERSON"));
    labelTitle->setAlignment(Qt::AlignHCenter);
    labelName = new QLabel();
    labelName->setText(tr("Name :"));
    lineEditName = new QLineEdit();
    labelSurname = new QLabel();
    labelSurname->setText(tr("Surname :"));
    lineEditSurname = new QLineEdit();
    labelPicture = new QLabel();
    labelPicture->setText(tr("Person picture"));
    labelParents = new QLabel();
    labelParents->setText(tr("Parents :"));
    lineEditParents = new QLineEdit();
    labelQuery = new QLabel();
    labelQuery->setText(tr("Query :"));
    lineEditQuery = new QLineEdit();
    dateEditBirthdate = new QDateEdit();
    labelBirthdate = new QLabel();
    labelBirthdate->setText(tr("Birthdate :"));
    pushButtonAddPerson = new QPushButton();
    pushButtonAddPerson->setText(tr("Add Person"));
    pushButtonAddPicture = new QPushButton();
    pushButtonAddPicture->setText(tr("Add Picture"));
    pushButtonCancel = new QPushButton();
    pushButtonCancel->setText(tr("Cancel"));
    connect(pushButtonAddPicture,SIGNAL(clicked()),this,SLOT(AddPicture()));
    layoutPrincipal->setSpacing(20);
    layoutPrincipal->addWidget(labelTitle);
    layoutPicture->addWidget(labelPicture,1,1,2,2);
    labelPicture->resize(150,150);
    layoutPicture->addWidget(pushButtonAddPicture,1,3,2,1);
    layoutPrincipal->addLayout(layoutPicture,2);
    layoutGrid->addWidget(labelName,1,1);
    layoutGrid->addWidget(lineEditName,1,2);
    layoutGrid->addWidget(labelSurname,1,3);
    layoutGrid->addWidget(lineEditSurname,1,4);
    layoutGrid->addWidget(labelBirthdate,1,5);
    layoutGrid->addWidget(dateEditBirthdate,1,6);
    layoutGrid->addWidget(labelParents,2,1);
    layoutGrid->addWidget(lineEditParents,2,2,1,5);
    layoutGrid->addWidget(labelQuery,3,1);
    layoutGrid->addWidget(lineEditQuery,3,2,1,5);
    layoutPrincipal->addLayout(layoutGrid);
    layoutButtons->addWidget(pushButtonAddPerson,1,1);
    layoutButtons->addWidget(pushButtonCancel,1,2);
    layoutPrincipal->addLayout(layoutButtons,2);
    labelPicture->setAlignment(Qt::AlignCenter);

	if (TreeUnitTests().getTestInterface()) {
		lineEditName->setText("Remi");
		lineEditSurname->setText("Thiiriet");
		lineEditQuery->setText("Remi, Thiriet, remi");
		lineEditParents->setText("Annick Demongeot, Jean-marc THIRIET");
	}

    connect(pushButtonAddPerson,SIGNAL(clicked()),this,SLOT(CreatePerson()));
    connect(pushButtonCancel,SIGNAL(clicked()),this,SLOT(Cancel()));


    this->setLayout(layoutPrincipal);

}

std::shared_ptr<Person> PersonInterface::getCurrentPerson() {
	return currentPerson;
}


PersonInterface::~PersonInterface()
{
    delete this;
}


void PersonInterface::AddPicture()
{

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        PictureReader *picreader = new PictureReader(image);
        connect(picreader, SIGNAL(pics(QImage)), this, SLOT(ModifyPicture(QImage)));
        picreader->exec();


    }


}

void PersonInterface::ModifyPicture(QImage picture_temp){
    qDebug()<<"bug ModifyPicture"<<endl;
    PersonInterface::labelPicture->setPixmap(QPixmap::fromImage(picture_temp));
    qDebug()<<"bug ModifyPicture end"<<endl;
}


void PersonInterface::CreatePerson(){

    currentPerson = std::make_shared<Person>(lineEditName->text(),lineEditSurname->text(),lineEditQuery->text(),lineEditParents->text(),dateEditBirthdate->date());
    qDebug() <<currentPerson->getName()<<endl;
    emit signalReturnPerson(*currentPerson);
    this->close();
}

void PersonInterface::Cancel(){
    this->close();
}
