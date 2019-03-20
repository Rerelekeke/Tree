/********************************************************************************
** Form generated from reading UI file 'tree.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREE_H
#define UI_TREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Tree
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Tree)
    {
        if (Tree->objectName().isEmpty())
            Tree->setObjectName(QStringLiteral("Tree"));
        Tree->resize(400, 300);
        buttonBox = new QDialogButtonBox(Tree);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Tree);
        QObject::connect(buttonBox, SIGNAL(accepted()), Tree, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Tree, SLOT(reject()));

        QMetaObject::connectSlotsByName(Tree);
    } // setupUi

    void retranslateUi(QDialog *Tree)
    {
        Tree->setWindowTitle(QApplication::translate("Tree", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Tree: public Ui_Tree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREE_H
