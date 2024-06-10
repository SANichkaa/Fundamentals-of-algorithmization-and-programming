#ifndef TEXTPARAGRAPH_H
#define TEXTPARAGRAPH_H

#include <QDebug>
#include <QString>
#include <fstream>
#include <sstream>

class TextParagraph {
 public:
  TextParagraph();
  void addText(QString text);
  QString getText();
  const QString FILE_NAME = "ФедоракоЛаб20.txt";
};

#endif  // TEXTPARAGRAPH_H
