#ifndef READFILE_H
#define READFILE_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>;
#include <QMessageBox>
#include <QDir>

namespace Ui {
class ReadFile;
}

class ReadFile : public QWidget
{
    Q_OBJECT

public:
    explicit ReadFile(QWidget *parent = nullptr);
    ~ReadFile();

public slots:
    void openFile();

private:
    Ui::ReadFile *ui;

signals:
    void dataSignal(QString);
};

#endif // READFILE_H
