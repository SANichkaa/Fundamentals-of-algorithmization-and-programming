#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu = new Menu();
    order = new NewOrder;
    orderLists = new QList<Order*>;
    menuItems = new QList<MenuItem*>;
    connect(this, &MainWindow::loadMenuSignal, menu, &Menu::loadMenu);
    connect(this, &MainWindow::loadMenuSignal, order, &NewOrder::loadOrder);
    connect(order, &NewOrder::addOrder, this, &MainWindow::addOrder);
    loadMenu();
    //readFile = new ReadFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuButton_clicked()
{
    menu->show();
}

void MainWindow::loadMenu()
{
    QString fileName = "//home//not-a-whale//lab2task2/Menu.txt";


    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split('\t');

        if (fields.size() != 3) {
            qDebug() << "Invalid line format";
            continue;
        }

        QString name = fields[0];
        QString category = fields[1];
        bool ok;
        double price = fields[2].toDouble(&ok);

        if (!ok) {
            qDebug() << "Invalid price format";
            continue;
        }
        menuItems->append(new MenuItem(name, category, price));
    }
    emit loadMenuSignal(menuItems);
}

void MainWindow::addWidgetOrder(Order* item)
{
    int i = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(i + 1);
    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(item->getTableNum())));
    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(item->getPrice())));
    ui->tableWidget->setItem(i, 2, new QTableWidgetItem(item->getText()));

}

void MainWindow::sortOrderd()
{
    ui->tableWidget->setRowCount(0);
    std::sort(orderLists->begin(), orderLists->end(), &Order::compareByPrice);
    for (int i = 0; i < orderLists->size(); ++i){
        Order* val = (*orderLists)[i];
        addWidgetOrder(val);
    }
}

void MainWindow::saveOrders()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Orders File");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, "Error", "Cannot save file");
        return;
    }

    QTextStream out(&file);
    for(auto value : *orderLists){
        out << value->getTableNum() << '\t' << value->getPrice() << '\t' << value->getText() << '\t';
    }
    file.close();
}


void MainWindow::on_newOrderButton_clicked()
{
    order->show();

}

void MainWindow::addOrder(QString text, double price, int table)
{
    Order* a =  new Order(text, price, table);
    std::sort(menuItems->begin(), menuItems->end(), &MenuItem::compareByOrders);
    ui->popularDish->setText((*menuItems)[0]->getName());
    orderLists->append(a);
    addWidgetOrder(a);

}


void MainWindow::on_sortButton_clicked()
{
    sortOrderd();
}


void MainWindow::on_saveButton_clicked()
{
    saveOrders();
}

