#include "textparagraph.h"

TextParagraph::TextParagraph() {}

void TextParagraph::addText(QString _text) {
  std::wofstream file("ФедоракоЛаб20.txt");

  if (file.is_open()) {
    std::wstring text = _text.toStdWString();

    for (wchar_t ch : text) {
      file << ch;
    }

    file.close();
    qDebug() << "Текст успешно записан в файл " + FILE_NAME;
  } else {
    qDebug() << "Не удалось открыть файл для записи";
  }
}

QString TextParagraph::getText() {
  std::wifstream file("ФедоракоЛаб20.txt");
  std::wstring content;

  if (file.is_open()) {
    std::wstringstream buffer;
    buffer << file.rdbuf();
    content = buffer.str();
    file.close();
  } else {
    qDebug() << "Не удалось открыть файл для чтения";
  }
  return QString::fromStdWString(content);
}
