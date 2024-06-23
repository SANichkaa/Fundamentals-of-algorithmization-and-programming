#include "task5.h"
#include "ui_task5.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

struct FolderInfo {
    int folderCount;
    int fileCount;
};

FolderInfo countFoldersAndFiles(const fs::path& path) {
    FolderInfo info = {0, 0};

    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry.status())) {
                info.folderCount++;
                FolderInfo subInfo = countFoldersAndFiles(entry.path());
                info.folderCount += subInfo.folderCount;
                info.fileCount += subInfo.fileCount;
            } else if (fs::is_regular_file(entry.status())) {
                info.fileCount++;
            }
        }
    }

    return info;
}
Task5::Task5(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task5)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Task5::selectFolder);
}

Task5::~Task5()
{
    delete ui;
}

void Task5::selectFolder()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");
    //qDebug() << folderPath;
    if (!folderPath.isEmpty()) {
       FolderInfo info = countFoldersAndFiles(folderPath.toStdString());
       ui->folders->setText(QString::number(info.folderCount));
       ui->files->setText(QString::number(info.fileCount));
       ui->path->setText(folderPath);

    }
}
