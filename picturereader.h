#ifndef PICTUREREADER_H
#define PICTUREREADER_H

#include <QDialog>
#include <person.h>
#include <QLabel>


class PictureReader : public QDialog, private Person
{
    Q_OBJECT

public:
    //    explicit PictureReader(QWidget *parent = 0);
    PictureReader(QImage pic);
    ~PictureReader();


signals:
    void pics(QImage picture);

public slots:
    void sendPicture();	




private:
    QImage *picRead;
    QLabel *labelPicture;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
};

#endif // PICTUREREADER_H
