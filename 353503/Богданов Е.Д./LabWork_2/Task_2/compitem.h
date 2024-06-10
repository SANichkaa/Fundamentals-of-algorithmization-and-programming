#ifndef COMPITEM_H
#define COMPITEM_H

#include <QFile>
#include <QVector>

class CompItem {
 public:
  CompItem();
  void Set_Vector(QString str);
  QVector<QString> Get_Vector();
  bool File_isOpen();

 private:
  QVector<QString> mass_str;
};

inline void CompItem::Set_Vector(QString str) {

  mass_str.push_back(str);

}

inline QVector<QString> CompItem::Get_Vector() {

  return mass_str;

}

#endif  // COMPITEM_H
