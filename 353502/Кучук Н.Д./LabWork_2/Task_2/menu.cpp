#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;

}

void Menu::loadMenu(QList<MenuItem*>* menuItems)
{
    this->menuItems = menuItems;
    QSet<QString> categories;
    ui->tableWidget->setRowCount(menuItems->size());
    for(auto i = 0; i < menuItems->size(); ++i) {
        MenuItem* item = (*menuItems)[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(item->getName()));
        ui-> tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(item->getPrice())));
        categories.insert(item->getCategory());
    }
    ui->menuComboBox->addItem("All");
    for (const QString &category : categories) {
        ui->menuComboBox->addItem(category);
    }
}

void Menu::on_menuComboBox_currentTextChanged(const QString &arg1)
{
    ui->tableWidget->clearContents();
    int j = 0;
    for (auto i = 0; i < menuItems->size(); ++i){
         MenuItem* item = (*menuItems)[i];
        if(arg1 == "All" || arg1 ==item->getCategory()){
            if (j >= ui->tableWidget->rowCount()) {
                ui->tableWidget->insertRow(j);
            }
            ui->tableWidget->setItem(j, 0, new QTableWidgetItem(item->getName()));
            ui-> tableWidget->setItem(j, 1, new QTableWidgetItem(QString::number(item->getPrice())));
            ++j;
        }
    }
    ui->tableWidget->setRowCount(j);

}

