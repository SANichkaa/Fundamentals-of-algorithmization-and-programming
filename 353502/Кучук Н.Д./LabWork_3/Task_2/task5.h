#ifndef TASK5_H
#define TASK5_H
#include <QFileDialog>

#include <QWidget>

namespace Ui {
class Task5;
}

class Task5 : public QWidget
{
    Q_OBJECT

public:
    explicit Task5(QWidget *parent = nullptr);
    ~Task5();

private:
    Ui::Task5 *ui;
    void selectFolder();
};

#endif // TASK5_H
