/********************************************************************************
** Form generated from reading UI file 'picturereader.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREREADER_H
#define UI_PICTUREREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PictureReader
{
public:
    QLabel *labelPicture;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *PictureReader)
    {
        if (PictureReader->objectName().isEmpty())
            PictureReader->setObjectName(QStringLiteral("PictureReader"));
        PictureReader->resize(400, 300);
        labelPicture = new QLabel(PictureReader);
        labelPicture->setObjectName(QStringLiteral("labelPicture"));
        labelPicture->setGeometry(QRect(30, 20, 341, 201));
        labelPicture->setFrameShape(QFrame::Box);
        labelPicture->setAlignment(Qt::AlignCenter);
        pushButtonOk = new QPushButton(PictureReader);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(90, 250, 93, 28));
        pushButtonCancel = new QPushButton(PictureReader);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(200, 250, 93, 28));

        retranslateUi(PictureReader);

        QMetaObject::connectSlotsByName(PictureReader);
    } // setupUi

    void retranslateUi(QDialog *PictureReader)
    {
        PictureReader->setWindowTitle(QApplication::translate("PictureReader", "Dialog", 0));
        labelPicture->setText(QString());
        pushButtonOk->setText(QApplication::translate("PictureReader", "Ok", 0));
        pushButtonCancel->setText(QApplication::translate("PictureReader", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class PictureReader: public Ui_PictureReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREREADER_H
