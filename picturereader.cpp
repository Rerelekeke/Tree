#include "picturereader.h"
#include "personinterface.h"
#include <QDebug>

PictureReader::PictureReader(QImage pic) {
        this->setWindowTitle(tr("Picture Reader"));
    this->resize(400, 300);
    labelPicture = new QLabel(this);
    labelPicture->setObjectName(QStringLiteral("labelPicture"));
    labelPicture->setGeometry(QRect(30, 20, 341, 201));
    labelPicture->setFrameShape(QFrame::Box);
    pushButtonOk = new QPushButton(this);
    pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
    pushButtonOk->setGeometry(QRect(90, 250, 93, 28));
    pushButtonOk->setText(tr("Ok"));
    pushButtonCancel = new QPushButton(this);
    pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
    pushButtonCancel->setGeometry(QRect(200, 250, 93, 28));
    pushButtonCancel->setText(tr("Cancel"));

    picRead= new QImage();
    picRead = new QImage(pic.scaled( labelPicture->width(),labelPicture->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    labelPicture->setPixmap(QPixmap::fromImage(*picRead));
    labelPicture->move((this->width()-picRead->width())/2,40);
    labelPicture->setFrameStyle(0);

    connect(pushButtonOk,SIGNAL(clicked()),this, SLOT(sendPicture()));
}

PictureReader::~PictureReader()
{
    delete this;
}

void PictureReader::sendPicture(){
    picture = picRead;
    labelPicture->setPixmap(QPixmap::fromImage(*picture));
    labelPicture->resize( (labelPicture->pixmap()->scaled(picture->width(),picture->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation)).size());
    labelPicture->move((this->width()-picture->width())/2,40);
    labelPicture->setFrameStyle(0);
    qDebug()<<"bug send picture";
    emit pics(*picture);
    this->close();
}

























//    connect(pushButton, SIGNAL(doubleClicked ( const QModelIndex & )),
//                this, SLOT(askModify(const QModelIndex & )));





//PictureReader::PictureReader(QImage pic,QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::PictureReader)
//{
//    ui->setupUi(this);

//}


//PictureReader::PictureReader(QImage pic, QWidget *parent): QDialog(parent),ui(new Ui::PictureReader)
//{
//    ui->setupUi(this);
//    picRead= new QImage();
//    picRead = new QImage(pic.scaled( ui->labelPicture->width(),ui->labelPicture->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
//    ui->labelPicture->setPixmap(QPixmap::fromImage(*picRead));

//    connect(ui->pushButtonOk,SIGNAL(clicked()),this, SLOT(sendPicture()));

//}

//void PictureReader::changeEvent(QEvent* event)
//{
//    emit FormChanged(event);
//}
