#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

void showinfo(Patient a)
{
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->cancell_2, SIGNAL(clicked()), this, SLOT(on_cancell_2_clicked()));
    connect(ui->selectfilebutton, SIGNAL(pressed()), this, SLOT(on_selectfilebutton_2_clicked()));
    connect(ui->findbynamebutton_2, SIGNAL(clicked()), this, SLOT(on_findbynamebutton_2_clicked()));
    connect(ui->findbyamountbutton_2, SIGNAL(clicked()), this, SLOT(on_findbyamountbutton_2_clicked()));

    ui->findbyamountedit_2->setMaximum(999999999);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatetable()
{
    ui->tableWidget->setRowCount(cnt2 + 1);
    ui->tableWidget->setColumnCount(5);
    for (int i = 0; i <= cnt2; i++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(patient[i].name);
        ui->tableWidget->setItem(i, 0, itm);
    }
    for (int i = 0; i <= cnt2; i++)
    {

        QTableWidgetItem *itm = new QTableWidgetItem(patient[i].gender);
        ui->tableWidget->setItem(i, 1, itm);
    }
    for (int i = 0; i <= cnt2; i++)
    {

        QTableWidgetItem *itm = new QTableWidgetItem(QString::number(patient[i].age));
        ui->tableWidget->setItem(i, 2, itm);
    }
    for (int i = 0; i <= cnt2; i++)
    {

        QTableWidgetItem *itm = new QTableWidgetItem(patient[i].diagnosis);
        ui->tableWidget->setItem(i, 3, itm);
    }
    for (int i = 0; i <= cnt2; i++)
    {

        QTableWidgetItem *itm = new QTableWidgetItem(QString::number(patient[i].number));
        ui->tableWidget->setItem(i, 4, itm);
    }
}

void MainWindow::on_selectfilebutton_2_clicked()
{
    file.setFileName(QFileDialog::getOpenFileName(this, tr("Open file")));
    file.open(QIODevice::ReadWrite);
    QString txt = ".txt";
    QString filename = file.fileName();

    if (!filename.contains(txt))
    {
        return;
    }

    QString s;
    QString subs;
    int cnt = 0;
    while (!file.atEnd())
    {
        int minicnt = 0;
        subs = "";
        s = file.readLine();
        s.remove(s.length() - 1, 1);
        s.append('$');
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ' || s[i] == '$')
            {
                if (minicnt == 0)
                {
                    patient[cnt].name = subs;
                }
                if (minicnt == 3)
                {
                    patient[cnt].diagnosis = subs;
                }
                if (minicnt == 1)
                {
                    patient[cnt].gender = subs;
                }
                if (minicnt == 2)
                {
                    patient[cnt].age = subs.toInt();
                }

                if (minicnt == 4)
                {
                    patient[cnt].number = subs.toInt();
                }
                subs = "";
                minicnt++;
                continue;
            }
            subs += s[i];
        }

        cnt++;
    }
    cnt -= 1;
    cnt2 = cnt;


    file.close();
    updatetable();
}

void MainWindow::on_cancell_2_clicked()
{
    if (file.fileName() == "")
    {
        return;
    }
    int n = ui->tableWidget->rowCount();
    for (int i = 0; i < n; i++)
    {
        ui->tableWidget->showRow(i);
    }
    updatetable();
    ui->lineEdit_2->setText("");
    ui->findbyamountedit_2->setValue(0);
}

void MainWindow::on_button_2_clicked()
{
    if (file.fileName() == "")
    {
        return;
    }
    int n = ui->tableWidget->rowCount();
    QString ss = ui->lineEdit_2->text();
    if (ss == "")
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        QString s = ui->tableWidget->item(i, 0)->text();
        QString s1 = ui->tableWidget->item(i, 3)->text();
        if (!ss.contains(s) && !ss.contains(s1))
        {
            ui->tableWidget->hideRow(i);
        }
    }
}

void MainWindow::on_findbyamountbutton_2_clicked()
{
    if (file.fileName() == "")
    {
        return;
    }
    int am = ui->findbyamountedit_2->value();
    QString s = QString::number(am);
    if (s == "")
    {
        return;
    }
    int n = ui->tableWidget->rowCount();
    for (int i = 0; i < n; i++)
    {
        QString sam = ui->tableWidget->item(i, 4)->text();
        if (am != sam.toInt())
        {
            ui->tableWidget->hideRow(i);
        }
    }
}
