#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <QMainWindow>
#include "character.h"

namespace Ui {
class Relationship;
}

class Relationship : public QMainWindow
{
    Q_OBJECT

public:
    explicit Relationship(QWidget *parent = nullptr);
    ~Relationship();

signals:
    void OpenMainWindow();

    void updateRelationshipSignal();

private slots:
    void on_pushButton_8_clicked();

    void updateHealth();

    void updateHappiness();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Relationship *ui;
};

#endif // RELATIONSHIP_H
