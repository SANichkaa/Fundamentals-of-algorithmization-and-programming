#ifndef STRUCTINPUTDIALOG_H
#define STRUCTINPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <Plant.h>

namespace Ui {
class StructInputDialog;
}

class StructInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StructInputDialog(QWidget* parent, Plant* pPlant);
    ~StructInputDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::StructInputDialog *ui;
    Plant* pPlant;
    Plant inpPlant;
};

#endif // STRUCTINPUTDIALOG_H
