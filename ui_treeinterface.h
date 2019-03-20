/********************************************************************************
** Form generated from reading UI file 'treeinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEINTERFACE_H
#define UI_TREEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TreeInterface
{
public:
    QLineEdit *lineEditName;
    QLabel *labelTitle;
    QLineEdit *lineEditBackupPath;
    QLabel *labelName;
    QLabel *labelPath;
    QLineEdit *lineEditPath;
    QCheckBox *checkBoxBackupPath;
    QPushButton *pushButtonBrowsePath;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonBrowseBackupPath;

    void setupUi(QDialog *TreeInterface)
    {
        if (TreeInterface->objectName().isEmpty())
            TreeInterface->setObjectName(QStringLiteral("TreeInterface"));
        TreeInterface->resize(513, 300);
        lineEditName = new QLineEdit(TreeInterface);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(130, 81, 231, 31));
        labelTitle = new QLabel(TreeInterface);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(130, 10, 221, 16));
        labelTitle->setAlignment(Qt::AlignCenter);
        lineEditBackupPath = new QLineEdit(TreeInterface);
        lineEditBackupPath->setObjectName(QStringLiteral("lineEditBackupPath"));
        lineEditBackupPath->setEnabled(false);
        lineEditBackupPath->setGeometry(QRect(130, 180, 231, 31));
        labelName = new QLabel(TreeInterface);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(20, 85, 55, 16));
        labelPath = new QLabel(TreeInterface);
        labelPath->setObjectName(QStringLiteral("labelPath"));
        labelPath->setGeometry(QRect(18, 130, 81, 20));
        lineEditPath = new QLineEdit(TreeInterface);
        lineEditPath->setObjectName(QStringLiteral("lineEditPath"));
        lineEditPath->setGeometry(QRect(130, 130, 231, 31));
        checkBoxBackupPath = new QCheckBox(TreeInterface);
        checkBoxBackupPath->setObjectName(QStringLiteral("checkBoxBackupPath"));
        checkBoxBackupPath->setGeometry(QRect(20, 184, 101, 20));
        pushButtonBrowsePath = new QPushButton(TreeInterface);
        pushButtonBrowsePath->setObjectName(QStringLiteral("pushButtonBrowsePath"));
        pushButtonBrowsePath->setGeometry(QRect(400, 130, 93, 31));
        pushButtonOk = new QPushButton(TreeInterface);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(150, 240, 93, 28));
        pushButtonCancel = new QPushButton(TreeInterface);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(250, 240, 93, 28));
        pushButtonBrowseBackupPath = new QPushButton(TreeInterface);
        pushButtonBrowseBackupPath->setObjectName(QStringLiteral("pushButtonBrowseBackupPath"));
        pushButtonBrowseBackupPath->setEnabled(false);
        pushButtonBrowseBackupPath->setGeometry(QRect(400, 180, 93, 31));

        retranslateUi(TreeInterface);

        QMetaObject::connectSlotsByName(TreeInterface);
    } // setupUi

    void retranslateUi(QDialog *TreeInterface)
    {
        TreeInterface->setWindowTitle(QApplication::translate("TreeInterface", "Dialog", nullptr));
        labelTitle->setText(QApplication::translate("TreeInterface", "Create an analogic Tree", nullptr));
        labelName->setText(QApplication::translate("TreeInterface", "Name", nullptr));
        labelPath->setText(QApplication::translate("TreeInterface", "Path", nullptr));
        checkBoxBackupPath->setText(QApplication::translate("TreeInterface", "Backup Path", nullptr));
        pushButtonBrowsePath->setText(QApplication::translate("TreeInterface", "Browse", nullptr));
        pushButtonOk->setText(QApplication::translate("TreeInterface", "Ok", nullptr));
        pushButtonCancel->setText(QApplication::translate("TreeInterface", "Cancel", nullptr));
        pushButtonBrowseBackupPath->setText(QApplication::translate("TreeInterface", "Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeInterface: public Ui_TreeInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEINTERFACE_H
