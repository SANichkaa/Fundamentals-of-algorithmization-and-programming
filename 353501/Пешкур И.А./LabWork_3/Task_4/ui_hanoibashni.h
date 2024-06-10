/********************************************************************************
** Form generated from reading UI file 'hanoibashni.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANOIBASHNI_H
#define UI_HANOIBASHNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_HanoiBashni
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButtonStart;
    QLabel *label;
    QSlider *horizontalSlider;

    void setupUi(QDialog *HanoiBashni)
    {
        if (HanoiBashni->objectName().isEmpty())
            HanoiBashni->setObjectName(QString::fromUtf8("HanoiBashni"));
        HanoiBashni->resize(1270, 605);
        graphicsView = new QGraphicsView(HanoiBashni);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 0, 1220, 510));
        pushButtonStart = new QPushButton(HanoiBashni);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(150, 520, 151, 61));
        label = new QLabel(HanoiBashni);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 540, 51, 17));
        horizontalSlider = new QSlider(HanoiBashni);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(370, 540, 861, 16));
        horizontalSlider->setMinimum(100);
        horizontalSlider->setMaximum(100000);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(HanoiBashni);

        QMetaObject::connectSlotsByName(HanoiBashni);
    } // setupUi

    void retranslateUi(QDialog *HanoiBashni)
    {
        HanoiBashni->setWindowTitle(QCoreApplication::translate("HanoiBashni", "Dialog", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("HanoiBashni", "Start", nullptr));
        label->setText(QCoreApplication::translate("HanoiBashni", "Speed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HanoiBashni: public Ui_HanoiBashni {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANOIBASHNI_H
