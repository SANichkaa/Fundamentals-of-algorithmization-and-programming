#ifndef FILELOADER_H
#define FILELOADER_H

#include <QStringList>
#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <fstream>
#include <QMessageBox>
#include <QCoreApplication>
#include <QInputDialog>
#include <Plant.h>
#include <StructInputDialog.h>

#define SAVE_FILES_NUM 5
const QString SAVE_FILES_NAMES[] =
    {
    "KovalchukLab6.txt",
    "KovalchukLab6_0.txt",
    "KovalchukLab6_1.txt",
    "KovalchukLab6_2.bin",
    "KovalchukLab6_3.txt"
};

class FileLoader
{
public:
    FileLoader(QTextBrowser* textBrowser);

    QString inputText;

    void SaveText(const QString& fileName);
    void LoadText(const QString& fileName);

    void SaveArray(const QString& fileName);
    void LoadArray(const QString& fileName);

    void SaveStruct(const QString& fileName);
    void LoadStruct(const QString& fileName);

    void SaveStructBin(const QString& fileName);
    void LoadStructBin(const QString& fileName);

    void SaveSentence(const QString& fileName);
    void LoadSentence(const QString& fileName);
private:
    Plant plant;
    StructInputDialog* pStructInputDialog;

    QTextBrowser* pOutputTextBrowser;
    QTextStream outputStream;
    QString outputText;
};

#endif // FILELOADER_H
