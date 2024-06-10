#ifndef HOUSING_H
#define HOUSING_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class Housing;
}

class Housing : public QMainWindow
{
    Q_OBJECT

public:
    explicit Housing(QWidget *parent = nullptr);
    ~Housing();

signals:
    void OpenMainWindow();

    void updateHousingSignal();

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

    void on_pushButton_9_clicked();

private:
    Ui::Housing *ui;
};

#endif // HOUSING_H
