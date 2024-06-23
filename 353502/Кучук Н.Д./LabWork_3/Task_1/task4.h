#ifndef TASK4_H
#define TASK4_H

#include <QWidget>

namespace Ui {
class Task4;
}

class Task4 : public QWidget
{
    Q_OBJECT

public:
    explicit Task4(QWidget *parent = nullptr);
    ~Task4();
    void moveDisk(int n, char fromPeg, char toPeg);
    void hanoi(int n, char fromPeg, char toPeg, char auxPeg);


private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Task4 *ui;
};

#endif // TASK4_H
