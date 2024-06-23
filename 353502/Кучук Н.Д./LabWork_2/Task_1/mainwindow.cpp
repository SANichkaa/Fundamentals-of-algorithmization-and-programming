#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Error");
    msgBox.setText("Invalid date");
    QDate cd = QDate::currentDate();
    today = Date(cd.day(), cd.month(), cd.year());
    cd = ui->dateEdit->date();
    birthday = Date(cd.day(), cd.month(), cd.year());
    ui->today->setText(Date::ToString(today.getYear(), today.getMonth(), today.getDay()));
    ui->tillBirtday->setText(QString::number(today.DaysTillYourBirthday(birthday)));
    readFile = new ReadFile();
    connect(ui->openFileButton, &QPushButton::clicked, readFile, &ReadFile::openFile);
    connect(readFile, &ReadFile::dataSignal, this, &MainWindow::dateData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dateData(QString string)
{
    QStringList datesStr = string.split(' ');
    for (const QString& dateStr : datesStr) {
        if (!addData(dateStr)){
            msgBox.exec();
            break;
        }
    }

}

void MainWindow::on_addData_clicked()
{
    if (!addData(ui->userDate->text())){
        msgBox.exec();
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int currentIndex = ui->listWidget->currentRow();
    QListWidgetItem* currentItem = item;
    QListWidgetItem* nextItem = item;
    if(currentIndex < ui->listWidget->count() - 1) {
        nextItem = ui->listWidget->item(currentIndex + 1);
    }
    infoUpdate(Date::fromString(currentItem->text()), Date::fromString(nextItem->text()));
}

void MainWindow::infoUpdate(Date date, Date nextDate)
{
    Date date2 = date.NextDay();
    ui->nextDay->setText(Date::ToString(date2.getYear(), date2.getMonth(), date2.getDay()));
    date2 = date.PreviousDay();
    ui->PreviousDay->setText(Date::ToString(date2.getYear(), date2.getMonth(), date2.getDay()));
    if (date.IsLeap()){
        ui->isLeap->setText("Yes");
    }
    else {
        ui->isLeap->setText("No");
    }
    ui->nextDate->setText(QString::number(date.Duration(nextDate)));
    ui->weekNum->setText(QString::number(date.WeekNumber()));
    ui->tillToday->setText(QString::number(date.Duration(today)));
}

bool MainWindow::addData(QString string)
{
    QStringList dateParts = string.split(".");
    if (dateParts.size() == 3) {
        int day = dateParts[0].toInt();
        int month = dateParts[1].toInt();
        int year = dateParts[2].toInt();
        if (Date::IsValid(year, month, day)){
            ui->listWidget->addItem(Date::ToString(year, month, day));
            return true;
        } else {
            return false;

        }
    } else {
        return false;
    }
}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    birthday = Date(date.day(), date.month(), date.year());
    ui->tillBirtday->setText(QString::number(today.DaysTillYourBirthday(birthday)));
}

