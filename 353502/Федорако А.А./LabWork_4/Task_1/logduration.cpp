#include "logduration.h"

LogDuration::LogDuration(QString id) : _id(std::move(id)) {}

long LogDuration::time() {
  const auto end_time = std::chrono::steady_clock::now();
  const auto dur = end_time - start_time_;
  return std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
}

QString LogDuration::result() {
  return _id + ": " + QString::number(time()) + " мс";
}

LogDuration::~LogDuration() {}
