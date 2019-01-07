#include "personinterface.h"
#include "ui_personinterface.h"

PersonInterface::PersonInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonInterface)
{
    ui->setupUi(this);
}

PersonInterface::~PersonInterface()
{
    delete ui;
}
