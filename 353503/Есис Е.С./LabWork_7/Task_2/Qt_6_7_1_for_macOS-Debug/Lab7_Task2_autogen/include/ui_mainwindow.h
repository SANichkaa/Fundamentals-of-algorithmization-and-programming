/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QSpinBox *spb_val;
    QLabel *label;
    QLineEdit *lineEditText;
    QPushButton *bnt_remove;
    QPushButton *bnt_search;
    QPushButton *bnt_add_item;
    QPushButton *bnt_balanse;
    QPushButton *bnt_cnt_of_list;
    QPushButton *bnt_in;
    QPushButton *bnt_post;
    QPushButton *bnt_pre;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 436);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(10, 10, 341, 371));
        spb_val = new QSpinBox(centralwidget);
        spb_val->setObjectName("spb_val");
        spb_val->setGeometry(QRect(500, 30, 42, 22));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 30, 51, 16));
        lineEditText = new QLineEdit(centralwidget);
        lineEditText->setObjectName("lineEditText");
        lineEditText->setGeometry(QRect(610, 70, 113, 21));
        bnt_remove = new QPushButton(centralwidget);
        bnt_remove->setObjectName("bnt_remove");
        bnt_remove->setGeometry(QRect(620, 110, 100, 32));
        bnt_search = new QPushButton(centralwidget);
        bnt_search->setObjectName("bnt_search");
        bnt_search->setGeometry(QRect(620, 150, 100, 32));
        bnt_add_item = new QPushButton(centralwidget);
        bnt_add_item->setObjectName("bnt_add_item");
        bnt_add_item->setGeometry(QRect(440, 150, 100, 32));
        bnt_balanse = new QPushButton(centralwidget);
        bnt_balanse->setObjectName("bnt_balanse");
        bnt_balanse->setGeometry(QRect(450, 190, 100, 32));
        bnt_cnt_of_list = new QPushButton(centralwidget);
        bnt_cnt_of_list->setObjectName("bnt_cnt_of_list");
        bnt_cnt_of_list->setGeometry(QRect(450, 230, 100, 32));
        bnt_in = new QPushButton(centralwidget);
        bnt_in->setObjectName("bnt_in");
        bnt_in->setGeometry(QRect(450, 270, 100, 32));
        bnt_post = new QPushButton(centralwidget);
        bnt_post->setObjectName("bnt_post");
        bnt_post->setGeometry(QRect(640, 200, 100, 32));
        bnt_pre = new QPushButton(centralwidget);
        bnt_pre->setObjectName("bnt_pre");
        bnt_pre->setGeometry(QRect(650, 250, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Key:", nullptr));
        bnt_remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        bnt_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        bnt_add_item->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        bnt_balanse->setText(QCoreApplication::translate("MainWindow", "Balanse", nullptr));
        bnt_cnt_of_list->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        bnt_in->setText(QCoreApplication::translate("MainWindow", "In", nullptr));
        bnt_post->setText(QCoreApplication::translate("MainWindow", "Post", nullptr));
        bnt_pre->setText(QCoreApplication::translate("MainWindow", "Pre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
