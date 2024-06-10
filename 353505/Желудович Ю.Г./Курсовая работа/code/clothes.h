#ifndef CLOTHES_H
#define CLOTHES_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class Clothes;
}

class Clothes : public QMainWindow
{
    Q_OBJECT
signals:
    void OpenMainWindow();

    void updateClothesSignal();

public:
    explicit Clothes(QWidget *parent = nullptr);
    ~Clothes();

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

private:
    Ui::Clothes *ui;

};

#endif // CLOTHES_H
