#ifndef SCENA_H
#define SCENA_H

#include <QEventLoop>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QGraphicsObject>
#include <QTimer>
#include <QVector>
#include <QRandomGenerator>

#include "myrect.h"
#include "steps.h"

class Scena : public QGraphicsScene {
  Q_OBJECT
 public:
  explicit Scena(QObject* parent = nullptr);
  void Go_To_Work(int n);
  void Move(MyRect *rect, qint16 from_x, qint16 to_x);
  void Hanoi(int n, qint16 from_x, qint16 to_x, qint16 aux_x);
  bool Get_hanoi_gotov();
  void SetSpeed(int speed_koef);
  QVector<Steps> GetPlan();
  QVector<MyRect*> GetItems();
  bool checkCollides(MyRect* item1, MyRect* item2);
 private:
  bool hanoi_gotov = false;
  int n, _disks_left = 0, _disks_center = 0, _disks_right = 0, speed_koef = 1, h = 0;
  QVector<MyRect*> disks;
  QVector<Steps> steps;
  MyRect* I;
  MyRect* II;
  MyRect* III;
  bool collides = false;



  QPropertyAnimation* animation_info;
private slots:
  void update_info();

};

#endif  // SCENA_H
