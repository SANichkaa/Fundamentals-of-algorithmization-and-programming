#ifndef FILEPROCESSING_H
#define FILEPROCESSING_H

#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>
#include <QVector>
#include <QWidget>
#include <vector>

class FileProcessing {
 public:
  FileProcessing();
  bool setFilePath();
  QString getText();

 private:
  void setFileText();
  QString filePath;
  bool isFileOpen;
  QString fileText;
};

#endif  // FILEPROCESSING_H
