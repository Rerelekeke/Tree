#include "treeinterface.h"
#include "ui_treeinterface.h"
#include <QDebug>


TreeInterface::TreeInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeInterface)
{
    ui->setupUi(this);
    ui->labelTitle->setText(QObject::tr("Créer un arbre généalogique"));
    ui->labelName->setText(QObject::tr("Name"));
    ui->labelPath->setText(QObject::tr("Path"));
    ui->checkBoxBackupPath->setText(QObject::tr("BackupPath"));
    ui->pushButtonBrowse->setText(QObject::tr("Browse"));
    connect(ui->checkBoxBackupPath, SIGNAL(clicked()), this, SLOT(enableBackupPath()));
    connect(ui->pushButtonBrowse, SIGNAL(clicked()), this, SLOT(browse()));
    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(treeCreation()));
}

TreeInterface::~TreeInterface()
{
    delete ui;
}

void TreeInterface::treeCreation(){
    QString stringError;
    QString stringFile;
    if (ui->fieldName->text() == ""){
        stringError += tr("Please fill the name field\n");
    }
    if(ui->fieldPath->text() == "" )
    {
        stringError += tr("Please fill the path field\n");
    }
    if(ui->fieldBackupPath->text() == "" && ui->checkBoxBackupPath->isChecked())
    {
        stringError += tr("Please fill the backup path field or untick the backup path checkbox\n");
    }
    if(stringError != ""){
        QMessageBox msgBox;
        msgBox.setText(tr("Error"));
        msgBox.setInformativeText(stringError);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else{
        name = ui->fieldName->text();
        updateDate = new QDateTime(QDateTime::currentDateTime());
        stringFile += name + "\n";
        stringFile += updateDate->toString("yyyy/MM/dd hh:mm:ss") + "\n";
        stringFile += path.path() + "\n";
        stringFile += backupPath.path() + "\n";

        // We create the directory if needed
        if (!path.exists(path.path()+"/"))
            path.mkpath(path.path()+"/");


        QFile file(path.path()+"/" + name + ".tree");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream flux(&file);
        flux.setCodec("UTF-8");
        flux << stringFile <<endl;

        this->hide();
    }

}

void TreeInterface::enableBackupPath(){
    if(ui->checkBoxBackupPath->isChecked()){
        ui->fieldBackupPath->setEnabled(true);
    }
    else {
        ui->fieldBackupPath->setEnabled(false);
    }
}

void TreeInterface::browse(){
    QLineEdit *LineEdit = ui->fieldPath;


    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly, false);
    if (dialog.exec())
      QStringList fileNames = dialog.selectedFiles();

    path= dialog.directory().path();
    LineEdit->setText(path.path()+"/");

}
