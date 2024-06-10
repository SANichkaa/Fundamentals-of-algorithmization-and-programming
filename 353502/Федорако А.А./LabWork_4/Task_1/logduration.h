#ifndef LOGDURATION_H
#define LOGDURATION_H

#include <QString>
#include <chrono>
#include <iostream>

class LogDuration {
 public:
  LogDuration(QString id);
  ~LogDuration();
  long time();
  QString result();

 private:
  const QString _id;
  const std::chrono::steady_clock::time_point start_time_ =
      std::chrono::steady_clock::now();
};

#endif  // LOGDURATION_H
