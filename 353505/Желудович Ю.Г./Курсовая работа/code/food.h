#ifndef FOOD_H
#define FOOD_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class Food;
}

class Food : public QMainWindow
{
    Q_OBJECT

public:
    explicit Food(QWidget *parent = nullptr);
    ~Food();

signals:
    void OpenMainWindow();

    void updateFoodSignal();

private slots:
    void on_pushButton_8_clicked();

    void updateHealth();

    void updateHappiness();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Food *ui;
};

#endif // FOOD_H
