#include "textstruct.h"

TextStruct::TextStruct() {}

void TextStruct::addText(QString _text) {
  qDebug() << "text = " << _text;
  std::wofstream file("ФедоракоЛаб20_1.txt", std::ios::app);
  if (file.is_open()) {
    std::wstring text = _text.toStdWString();
    file << text << std::endl;
    qDebug() << "Текст успешно записан в файл " + FILE_NAME;
  } else {
    qDebug() << "Не удалось открыть файл для записи";
  }
}

QString TextStruct::getText() {
  std::wifstream file("ФедоракоЛаб20_1.txt");
  std::wstring content;
  if (file.is_open()) {
    wchar_t ch;
    while (file.get(ch)) {
      content += ch;
    }
    file.close();
  } else {
    qDebug() << "Не удалось открыть файл для чтения";
  }
  return QString::fromStdWString(content);
}
