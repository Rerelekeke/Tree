#ifndef PICTUREREADER_H
#define PICTUREREADER_H

#include <QDialog>

namespace Ui {
class pictureReader;
}

class pictureReader : public QDialog
{
    Q_OBJECT

public:
    explicit pictureReader(QWidget *parent = nullptr);
    ~pictureReader();

private:
    Ui::pictureReader *ui;
};

#endif // PICTUREREADER_H
