#include "treeinterface.h"
#include "ui_treeinterface.h"
#include <QDebug>



TreeInterface::TreeInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeInterface)
{
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    QGridLayout *layoutName = new QGridLayout();
    QGridLayout *layoutPath = new QGridLayout();
    QGridLayout *layoutBackupPath = new QGridLayout();
    QGridLayout *layoutButtons = new QGridLayout();
    ui->setupUi(this);
    ui->labelTitle->setText(QObject::tr("Create a genealogic tree"));
    ui->labelName->setText(QObject::tr("Name"));
    ui->labelPath->setText(QObject::tr("Path"));
    ui->checkBoxBackupPath->setText(QObject::tr("BackupPath"));
    ui->pushButtonBrowsePath->setText(QObject::tr("Browse"));
    ui->pushButtonBrowseBackupPath->setText(QObject::tr("Browse"));
    connect(ui->checkBoxBackupPath, SIGNAL(clicked()), this, SLOT(enableBackupPath()));
    connect(ui->pushButtonBrowsePath, SIGNAL(clicked(bool)), this, SLOT(browse(bool)));
    connect(ui->pushButtonBrowseBackupPath, SIGNAL(clicked(bool)), this, SLOT(browse(bool)));
    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(createTree()));

    layoutPrincipal->setSpacing(20);
    layoutPrincipal->addWidget(ui->labelTitle);
    layoutName->addWidget(ui->labelName,1,1);
    layoutName->addWidget(ui->lineEditName,1,2);
    layoutPrincipal->addLayout(layoutName);
    layoutPath->addWidget(ui->labelPath,1,1);
    layoutPath->addWidget(ui->lineEditPath,1,2);
    layoutPath->addWidget(ui->pushButtonBrowsePath,1,3);
    layoutPrincipal->addLayout(layoutPath);
    layoutBackupPath->addWidget(ui->checkBoxBackupPath,1,1);
    layoutBackupPath->addWidget(ui->lineEditBackupPath,1,2);
    layoutBackupPath->addWidget(ui->pushButtonBrowseBackupPath,1,3);
    layoutPrincipal->addLayout(layoutBackupPath);
    layoutButtons->addWidget(ui->pushButtonOk,1,1);
    layoutButtons->addWidget(ui->pushButtonCancel,1,2);
    layoutPrincipal->addLayout(layoutButtons,2);

    this->setLayout(layoutPrincipal);
}

TreeInterface::~TreeInterface()
{
    delete ui;
}

void TreeInterface::createTree(){

    QString stringError;
    QString stringFile;
    if (ui->lineEditName->text() == ""){
        stringError += tr("Please fill the name field\n");
    }
    if(ui->lineEditPath->text() == "" )
    {
        stringError += tr("Please fill the path field\n");
    }
    if(ui->lineEditBackupPath->text() == "" && ui->checkBoxBackupPath->isChecked())
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
        QString name = ui->lineEditName->text();
        QDateTime *updateDate = new QDateTime(QDateTime::currentDateTime());
        stringFile += name + "\n";
        stringFile += updateDate->toString("yyyy/MM/dd hh:mm:ss") + "\n";
        stringFile += path.path() + "\n";
        stringFile += backupPath.path() + "\n";
        stringFile += "name,surname,query,parents,birthdate";

        // We create the directory if needed
        if (!path.exists(path.path()+"/"))
            path.mkpath(path.path()+"/");


        QFile file(path.path()+"/" + name + ".tree");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream flux(&file);
        flux.setCodec("UTF-8");
        flux << stringFile <<endl;

        Tree *currentTree = new Tree(name, *updateDate, path, backupPath);
        emit signalReturnTree(*currentTree);


        this->hide();
    }

}

void TreeInterface::enableBackupPath(){
    if(ui->checkBoxBackupPath->isChecked()){
        ui->lineEditBackupPath->setEnabled(true);
        ui->pushButtonBrowseBackupPath->setEnabled(true);
    }
    else {
        ui->pushButtonBrowseBackupPath->setEnabled(false);
        ui->lineEditBackupPath->setEnabled(false);
    }
}

void TreeInterface::browse(bool pathType){
    QLineEdit *LineEdit = ui->lineEditPath;


    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly, false);
    if (dialog.exec())
      QStringList fileNames = dialog.selectedFiles();
    if(pathType){
        path= dialog.directory().path();
        LineEdit->setText(path.path()+"/");
    }
    else{
        backupPath= dialog.directory().path();
        LineEdit->setText(backupPath.path()+"/");
    }



}
