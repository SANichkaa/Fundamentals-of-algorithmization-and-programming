#ifndef HEALTH_H
#define HEALTH_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class Health;
}

class Health : public QMainWindow
{
    Q_OBJECT

public:
    explicit Health(QWidget *parent = nullptr);
    ~Health();

signals:
    void OpenMainWindow();

    void updateHealthSignal();

private slots:
    void on_pushButton_8_clicked();

    void updateHealth();

    void updateHappiness();

//    void updateMoney();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Health *ui;
};

#endif // HEALTH_H
