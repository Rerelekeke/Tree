#ifndef PERSONINTERFACE_H
#define PERSONINTERFACE_H

#include <QDialog>

namespace Ui {
class PersonInterface;
}

class PersonInterface : public QDialog
{
    Q_OBJECT

public:
    explicit PersonInterface(QWidget *parent = nullptr);
    ~PersonInterface();

private:
    Ui::PersonInterface *ui;
};

#endif // PERSONINTERFACE_H
