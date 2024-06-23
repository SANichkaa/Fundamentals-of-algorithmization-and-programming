#include "readfile.h"
#include "ui_readfile.h"

ReadFile::ReadFile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReadFile)
{
    ui->setupUi(this);
}

ReadFile::~ReadFile()
{
    delete ui;
}

void ReadFile::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "File not open");
    }
    else{
        QTextStream in(&file);
        QString text = in.readAll();
        emit dataSignal(text);
        file.close();
    }
}

QString ReadFile::openFileName(QString fileName)
{
    QString text = "";
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "File not open");
    }
    else{
        QTextStream in(&file);
        text = in.readAll();
        //emit dataSignal(text);
        file.close();
    }
    return text;
}
