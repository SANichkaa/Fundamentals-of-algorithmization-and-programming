#ifndef HAPPINESS_H
#define HAPPINESS_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include "character.h"


namespace Ui {
class Happiness;
}

class Happiness : public QMainWindow
{
    Q_OBJECT

signals:
    void OpenMainWindow();

    void updateHappinessSignal();

public:
    explicit Happiness(QWidget *parent = nullptr);
    ~Happiness();

private slots:
    void on_pushButton_8_clicked();

    void updateHealth();

    void updateHappiness();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Happiness *ui;
};

#endif // HAPPINESS_H
