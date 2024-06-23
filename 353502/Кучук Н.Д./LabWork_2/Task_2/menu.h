#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <MenuItem.h>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;
    QList<MenuItem*>* menuItems;

public slots:
    void loadMenu(QList<MenuItem*>* menuItems);
private slots:
    void on_menuComboBox_currentTextChanged(const QString &arg1);
};

#endif // MENU_H
