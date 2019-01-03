#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

#include <QDialog>

namespace Ui {
class TreeInterface;
}

class TreeInterface : public QDialog
{
    Q_OBJECT

public:
    explicit TreeInterface(QWidget *parent = nullptr);
    ~TreeInterface();

private:
    Ui::TreeInterface *ui;
};

#endif // TREEINTERFACE_H
