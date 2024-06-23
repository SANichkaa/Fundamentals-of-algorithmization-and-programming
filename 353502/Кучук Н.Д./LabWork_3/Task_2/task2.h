#ifndef TASK2_H
#define TASK2_H

#include <QWidget>

namespace Ui {
class Task2;
}

class Task2 : public QWidget
{
    Q_OBJECT

public:
    explicit Task2(QWidget *parent = nullptr);
    ~Task2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Task2 *ui;
    int ackermann(int m, int n);
};

#endif // TASK2_H
