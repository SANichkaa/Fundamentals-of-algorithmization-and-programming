#include "scena.h"

Scena::Scena(QObject* parent) : QGraphicsScene{parent} {}

void Scena::Go_To_Work(int n) {
  const int first_point_for_rect_left_x = -300;
  const int first_point_for_rect_center_x = 0;
  const int first_point_for_rect_right_x = 300;
  const int height = -120;
  const int koeficient = 10;
  const int n400 = 400;
  const int n200 = 200;

  QGraphicsRectItem* rectic1 = new QGraphicsRectItem(-n400, 0, n200, 1);

  this->addItem(I = new MyRect(rectic1));
  this->addLine(first_point_for_rect_left_x, 0, first_point_for_rect_left_x, height);
  QGraphicsRectItem* rectic2 = new QGraphicsRectItem(-n200/2, 0, n200, 1);
  this->addItem(II = new MyRect(rectic2));
  this->addLine(0, 0, 0, height);
  QGraphicsRectItem* rectic3 = new QGraphicsRectItem(n200, 0, n200, 1);
  this->addItem(III = new MyRect(rectic3));
  this->addLine(first_point_for_rect_right_x, 0, first_point_for_rect_right_x, height);

  _disks_center = n;

  disks.clear();

  for (int y = n; y > 0; y--) {
    QRectF rectic(first_point_for_rect_center_x - koeficient * y,
                  koeficient * y - koeficient * n - koeficient,
                  2 * (koeficient * y), koeficient);
    QGraphicsRectItem* rect = new QGraphicsRectItem(rectic);
    MyRect* item = new MyRect(rect);
    disks.push_front(item);
    this->addItem(item);
  }

  Hanoi(n, first_point_for_rect_center_x, first_point_for_rect_right_x,
        first_point_for_rect_left_x);

  hanoi_gotov = true;
}

void Scena::Move(MyRect* rect, qint16 from_x, qint16 to_x) {
  const int first_point_for_rect_left_x = -300;
  const int first_point_for_rect_center_x = 0;
  const int first_point_for_rect_right_x = 300;
  const int height = -120;
  const int time = 2000;
  const int koeficient = 10;
  int var = 0;
  QTimer* timer = new QTimer();
  n = disks.indexOf(rect);

  if (from_x == first_point_for_rect_left_x) {
    _disks_left--;
  } else if (from_x == first_point_for_rect_center_x) {
    _disks_center--;

  } else {
    _disks_right--;
  }

   QPropertyAnimation* animation1 = new QPropertyAnimation(rect, "pos");
  animation1->setDuration(time / speed_koef);
  animation1->setStartValue(QPointF(from_x, rect->pos().y()));
  animation1->setEndValue(QPoint(rect->pos().x(), height));
  rect->setPos(animation1->endValue().toPoint().x(),
               animation1->endValue().toPoint().y());

  QPropertyAnimation* animation2 = new QPropertyAnimation(rect, "pos");
  animation2->setDuration(time / speed_koef);
  animation2->setStartValue(QPointF(rect->pos().x(), rect->pos().y()));
  animation2->setEndValue(QPointF(to_x, rect->pos().y()));
  rect->setPos(animation2->endValue().toPoint().x(),
               animation2->endValue().toPoint().y());

  QPropertyAnimation* animation3 = new QPropertyAnimation(rect, "pos");
  animation3->setDuration(time / speed_koef);
  animation3->setStartValue(QPointF(animation2->endValue().toPoint().x(),
                                    animation2->endValue().toPoint().y()));

  if (to_x == first_point_for_rect_left_x) {
    animation3->setEndValue(QPointF(to_x, first_point_for_rect_right_x));
    _disks_left++;

  } else if (to_x == first_point_for_rect_center_x) {
    animation3->setEndValue(QPointF(to_x, first_point_for_rect_right_x));
    _disks_center++;

  } else {
    animation3->setEndValue(QPointF(to_x, first_point_for_rect_right_x));
    _disks_right++;
  }

  rect->setPos(animation3->endValue().toPointF().x(),
               animation3->endValue().toPointF().y());

  animation1->start();
  QObject::connect(animation1, &QPropertyAnimation::finished,
                   [=]() { animation2->start(); });

  QObject::connect(animation2, &QPropertyAnimation::finished,
                   [=]() { animation3->start(); });

  animation_info = animation3;

  QObject::connect(animation_info, &QPropertyAnimation::finished, [=]() {
    if (collides) {
      animation_info->stop();
      animation_info = nullptr;
    }
  });

  connect(timer, SIGNAL(timeout()), this, SLOT(update_info()));
  timer->start(4*koeficient);
}

void Scena::Hanoi(int n, qint16 from_x, qint16 to_x, qint16 aux_x) {
  if (n == 1) {
    Steps step;
    step.number = n;
    step.from_x = from_x;
    step.to_x = to_x;

    steps.push_back(step);

  } else {
    Hanoi(n - 1, from_x, aux_x, to_x);

    Steps step;
    step.number = n;
    step.from_x = from_x;
    step.to_x = to_x;
    steps.push_back(step);

    Hanoi(n - 1, aux_x, to_x, from_x);
  }
}

bool Scena::Get_hanoi_gotov() { return hanoi_gotov; }

void Scena::SetSpeed(int speed_koef) { this->speed_koef = speed_koef; }

QVector<Steps> Scena::GetPlan() { return steps; }

QVector<MyRect*> Scena::GetItems() { return disks; }

bool Scena::checkCollides(MyRect* item1, MyRect* item2) {
  return item1->collidesWithItem(item2);
}

void Scena::update_info() {
  for (int y = 0; disks.size() > y; y++) {
    if (n != y and checkCollides(disks[n], disks[y])) {
      collides = true;
    }
  }

  if (checkCollides(disks[n], I) or checkCollides(disks[n], II) or
      checkCollides(disks[n], III)) {
    collides = true;
  }

  if (collides) {
    animation_info->stop();
  }
}
