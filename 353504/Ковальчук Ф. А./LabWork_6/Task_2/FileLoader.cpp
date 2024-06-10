#include "FileLoader.h"

FileLoader::FileLoader(QTextBrowser* textBrowser)
    : outputStream(&outputText)
{
    pOutputTextBrowser = textBrowser;
    pStructInputDialog = new StructInputDialog(nullptr, &plant);

    for(int i =0; i < SAVE_FILES_NUM; i++){
        QFile file(SAVE_FILES_NAMES[i]);
        if (!file.exists())
        {
            if (!file.open(QIODevice::WriteOnly))
            {
                return;
            }
            file.close();
        }
    }
}

void FileLoader::SaveText(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString text = QInputDialog::getText(nullptr, "Ввод", "Введите текст:");
        for (int i = 0; i < text.length(); ++i)
        {
            fileStream << text[i];
        }
        file.close();
    }
}

void FileLoader::LoadText(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!fileStream.atEnd())
        {
            QChar tmpChar;
            fileStream >> tmpChar;
            outputStream << tmpChar;
        }
        file.close();
    }
    pOutputTextBrowser->setText(outputText);
    outputText.clear();
}

void FileLoader::SaveArray(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    int size = QInputDialog::getInt(nullptr, "Запись массива", "Кол-во элементов:");
    float f;

    for (int i = 0; i < size; ++i)
    {
        f = QInputDialog::getDouble(nullptr, "Ввод", "Ввод элемента " + QString::number(i) + ":");
        fileStream << f << ';';//Ковальчук 13 в списке символ - ;
    }
    file.close();
}

void FileLoader::LoadArray(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!fileStream.atEnd())
        {
            QString data = fileStream.readAll();
            QStringList separatedFloats = data.split(";", Qt::SkipEmptyParts);
            for (auto s : separatedFloats)
            {
                outputStream << s << " ";
            }
        }
        file.close();
    }
    pOutputTextBrowser->setText(outputText);
    outputText.clear();
}


void FileLoader::SaveStruct(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

   if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        pStructInputDialog->setModal(Qt::ApplicationModal);
        pStructInputDialog->show();

        while (pStructInputDialog->isVisible())
        {
            QCoreApplication::processEvents();
        }

        QString writedText = QString(plant.name) + "\n" + QString::number(plant.daysOfGrowing) + "\n" + QString::number(plant.height) + "\n" + (plant.isFlowering ? "true" : "false") + "\n";

        fileStream << writedText;
        file.close();
    }
}

void FileLoader::LoadStruct(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QStringList data;
        while(!fileStream.atEnd()){
            data.append(fileStream.readLine());
        }


        Plant tmp;
        for(int i =0; i < data[0].size() && i < 15; i++){
            tmp.name[i] = data[0][i];
        }
        tmp.daysOfGrowing = data[1].toInt();
        tmp.height = data[2].toDouble();
        tmp.isFlowering = data[3] == "true" ? true : false;

        outputStream << QString(tmp.name) << " | " << QString::number(tmp.daysOfGrowing) << " | " << QString::number(tmp.height) << " | " << (tmp.isFlowering ? QString("true") : QString("false"));
        file.close();
    }
    pOutputTextBrowser->setText(outputText);
    outputText.clear();
}

void FileLoader::SaveStructBin(const QString &fileName)
{
    QFile file(fileName);
    QDataStream fileStream(&file);

    if (file.open(QIODevice::WriteOnly))
    {
        pStructInputDialog->setModal(Qt::ApplicationModal);
        pStructInputDialog->show();

        while (pStructInputDialog->isVisible())
        {
            QCoreApplication::processEvents();
        }

        fileStream.writeRawData((const char*)&plant, sizeof(Plant));
        file.close();
    }
}

void FileLoader::LoadStructBin(const QString &fileName)
{
    QFile file(fileName);
    QDataStream fileStream(&file);

    if (file.open(QIODevice::ReadOnly))
    {
        Plant tmp;
        fileStream.readRawData(reinterpret_cast<char*>(&tmp) ,sizeof(Plant));
        outputStream << QString(tmp.name) << " | " << QString::number(tmp.daysOfGrowing) << " | " << QString::number(tmp.height) << " | " << (tmp.isFlowering ? QString("true") : QString("false"));

        file.close();
        pOutputTextBrowser->setText(outputText);
        outputText.clear();
    }
}


void FileLoader::SaveSentence(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QString text = QInputDialog::getText(nullptr, "Ввод", "Введите предложение:");;
        fileStream << text << "\n";
        file.close();
    }
}

void FileLoader::LoadSentence(const QString &fileName)
{
    QFile file(fileName);
    QTextStream fileStream(&file);

    if (file.open(QIODevice::ReadOnly))
    {
        while (!fileStream.atEnd())
        {
            QString s = fileStream.readLine();
            outputStream << s << "\n";
        }
        file.close();
    }
    pOutputTextBrowser->setText(outputText);
    outputText.clear();
}
