#include "fileprocessing.h"

FileProcessing::FileProcessing() : fileText("") {}

bool FileProcessing::setFilePath() {

  isFileOpen = false;
  filePath = QFileDialog::getOpenFileName();

  QFile file(filePath);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return false;
  } else {
    QFileInfo check_file(filePath);
    if (check_file.suffix() == "txt") {
      setFileText();
      isFileOpen = true;
    } else {
      return false;
    }
  }
  return true;
}

void FileProcessing::setFileText() {
  QFile file(filePath);

  if (file.open(QIODevice::ReadOnly)) {
    QTextStream in(&file);
    while (!in.atEnd()) {
      fileText += in.readLine();
    }
  }
}

QString FileProcessing::getText() {
  return fileText;
}
