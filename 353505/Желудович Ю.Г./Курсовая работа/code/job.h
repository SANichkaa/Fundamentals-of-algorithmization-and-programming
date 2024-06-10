#ifndef JOB_H
#define JOB_H

#include <QMainWindow>
#include "character.h"
#include <QTimer>

namespace Ui {
class Job;
}

class Job : public QMainWindow
{
    Q_OBJECT

public:
    explicit Job(QWidget *parent = nullptr);
    ~Job();

signals:
    void OpenMainWindow();

    void updateJobSignal();

private slots:
    void on_pushButton_8_clicked();

    void updateHealth();

    void updateHappiness();

    void on_pushButton_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_59_clicked();

private:
    Ui::Job *ui;
};

#endif // JOB_H
