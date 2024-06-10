#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

}

void MainWindow::listFoldersAndFiles(const QString &path, QTextStream &stream,
                                     int &totalFolders, int &totalFiles) {
  QDir dir(path);
  if (!dir.exists()) {
    stream << "Directory does not exist: " << path << "\n";
    return;
  }

  QStringList folders = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
  QStringList files = dir.entryList(QDir::Files);

  stream << "Folder: " << path << "\n";

  stream << "Files:"
         << "\n";

  for (const QString &file : files) {
    stream << "- " << file << "\n";
    totalFiles++;
  }

  stream << "Subfolders:"
         << "\n";

  for (const QString &folder : folders) {
    totalFolders++;
    listFoldersAndFiles(path + "/" + folder, stream, totalFolders, totalFiles);
  }
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {

  QString rootPath = "/home/QT1";
  QFile outputFile("output.txt");
  if (outputFile.exists() and outputFile.open(QIODevice::ReadWrite | QIODevice::Text)) {

    outputFile.remove();

    QTextStream stream(&outputFile);

    int totalFolders = 1;
    int totalFiles = 0;

    listFoldersAndFiles(rootPath, stream, totalFolders, totalFiles);

    stream << "Total folders: " << totalFolders << "\n";
     ui->label_4->setText(stream.readLine());
    stream << "Total files: " << totalFiles << "\n";
    ui->label_3->setText(stream.readLine());




    outputFile.close();
  }

}
