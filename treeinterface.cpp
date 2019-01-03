#include "treeinterface.h"
#include "ui_treeinterface.h"

TreeInterface::TreeInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeInterface)
{
    ui->setupUi(this);
}

TreeInterface::~TreeInterface()
{
    delete ui;
}
