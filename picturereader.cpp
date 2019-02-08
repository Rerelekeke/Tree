#include "picturereader.h"
#include "ui_picturereader.h"

pictureReader::pictureReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pictureReader)
{
    ui->setupUi(this);
}

pictureReader::~pictureReader()
{
    delete ui;
}
