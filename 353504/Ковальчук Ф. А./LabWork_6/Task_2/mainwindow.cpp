#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileLoader.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pFileLoader = new FileLoader(ui->textBrowser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_menu_clicked()
{
    int menuChoice = QInputDialog::getInt(this, "Меню",
        "Enter:\n1 - Сохранить текст в файл"
        "\n2 - Загрузить текст из файла"
        "\n3 - Сохранить массив в файл"
        "\n4 - Загрузить массив из файла"
        "\n5 - Созранить структуру в файл"
        "\n6 - Загрузить структуру из файла"
        "\n7 - Сохранить структуру в бинарный файл"
        "\n8 - Загрузить структуру из бинарного файла"
        "\n9 - Сохранить предложение в файл"
        "\n10 - Загрузить предложение из файла"
    );

    switch (menuChoice)
    {
    case 1:
        pFileLoader->SaveText(SAVE_FILES_NAMES[0]);
        break;
    case 2:
        pFileLoader->LoadText(SAVE_FILES_NAMES[0]);
        ui->label_3->setText("Файл - " + SAVE_FILES_NAMES[0]);
        break;
    case 3:
        pFileLoader->SaveArray(SAVE_FILES_NAMES[1]);
        break;
    case 4:
        pFileLoader->LoadArray(SAVE_FILES_NAMES[1]);
        ui->label_3->setText("Файл - " + SAVE_FILES_NAMES[1]);
        break;
    case 5:
        pFileLoader->SaveStruct(SAVE_FILES_NAMES[2]);
        break;
    case 6:
        pFileLoader->LoadStruct(SAVE_FILES_NAMES[2]);
        ui->label_3->setText("Файл - " + SAVE_FILES_NAMES[2]);
        break;
    case 7:
        pFileLoader->SaveStructBin(SAVE_FILES_NAMES[3]);
        break;
    case 8:
        pFileLoader->LoadStructBin(SAVE_FILES_NAMES[3]);
        ui->label_3->setText("Файл - " + SAVE_FILES_NAMES[3]);
        break;
    case 9:
        pFileLoader->SaveSentence(SAVE_FILES_NAMES[4]);
        break;
    case 10:
        pFileLoader->LoadSentence(SAVE_FILES_NAMES[4]);
        ui->label_3->setText("Файл - " + SAVE_FILES_NAMES[4]);
        break;
    default:
        break;
    }
}
