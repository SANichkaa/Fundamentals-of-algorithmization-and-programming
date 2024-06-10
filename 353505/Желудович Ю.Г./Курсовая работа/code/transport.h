#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class Transport;
}

class Transport : public QMainWindow
{
    Q_OBJECT

public:
    explicit Transport(QWidget *parent = nullptr);
    ~Transport();

signals:
    void OpenMainWindow();

    void updateTransportSignal();

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
    Ui::Transport *ui;
};

#endif // TRANSPORT_H
