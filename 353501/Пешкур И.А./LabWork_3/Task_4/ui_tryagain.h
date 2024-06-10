/********************************************************************************
** Form generated from reading UI file 'tryagain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRYAGAIN_H
#define UI_TRYAGAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TryAgain
{
public:
    QPushButton *pushButtonAgain;
    QPushButton *pushButtonStop;

    void setupUi(QDialog *TryAgain)
    {
        if (TryAgain->objectName().isEmpty())
            TryAgain->setObjectName(QString::fromUtf8("TryAgain"));
        TryAgain->resize(400, 300);
        pushButtonAgain = new QPushButton(TryAgain);
        pushButtonAgain->setObjectName(QString::fromUtf8("pushButtonAgain"));
        pushButtonAgain->setGeometry(QRect(30, 110, 88, 81));
        pushButtonStop = new QPushButton(TryAgain);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(230, 110, 88, 81));

        retranslateUi(TryAgain);

        QMetaObject::connectSlotsByName(TryAgain);
    } // setupUi

    void retranslateUi(QDialog *TryAgain)
    {
        TryAgain->setWindowTitle(QCoreApplication::translate("TryAgain", "Dialog", nullptr));
        pushButtonAgain->setText(QCoreApplication::translate("TryAgain", "Again", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("TryAgain", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TryAgain: public Ui_TryAgain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRYAGAIN_H
