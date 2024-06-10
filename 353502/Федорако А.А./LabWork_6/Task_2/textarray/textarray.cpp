#include "textarray.h"

TextArray::TextArray() {}

void TextArray::addText(QString _text) {
  std::wofstream file("ФедоракоЛаб20_0.txt");

  if (file.is_open()) {
    std::wstring text = _text.toStdWString();

    for (wchar_t ch : text) {
      if (ch == ' ') {
        ch = '>';
      }
      file << ch;
    }

    file.close();
    qDebug() << "Текст успешно записан в файл " + FILE_NAME;
  } else {
    qDebug() << "Не удалось открыть файл для записи";
  }
}

QString TextArray::getText() {
  std::wifstream file("ФедоракоЛаб20_0.txt");
  std::wstring content;

  if (file.is_open()) {
    wchar_t ch;
    while (file.get(ch)) {
      if (ch == '<') {
        content.append(L" ");
      } else {
        content += ch;
      }
    }
    file.close();
  } else {
    qDebug() << "Не удалось открыть файл для чтения";
  }
  return QString::fromStdWString(content);
}
