#include "customstring.h"
#include <QDebug>

CustomString::CustomString() {
  _size = 0;
  _capacity = 1;
}

CustomString::CustomString(size_t size) {
  reserve(size + 1);
}

CustomString::CustomString(QString& line) {
  resize(line.size());
  const char* cstr = line.toStdString().c_str();
  int i = 0;
  while (i < line.size()) {
    _array[i] = *(cstr + i);
    i++;
  }
}

void CustomString::push_back(char symbol) {
  if (_size + 1 >= _capacity)
    reserve(2 * _size + 1);
  _array[_size] = symbol;
  _size++;
  _array[_size] = '\0';
}

CustomString::~CustomString() {
  _array = make_unique<char[]>(0);
  _capacity = 0;
  _size = 0;
}

CustomString::CustomString(char* str) {
  size_t size = 0;
  while (str[size + 1] != '\0' && str[size] != '\0') {
    size++;
  }

  reserve(size);

  for (int i = 0; i < size; i++) {
    _array[i] = str[i];
  }
  _size = size;
  _capacity = size;
  _array[_size] = '\0';
}

void CustomString::assign(size_t size, char symbol) {
  clear();
  resize(size, symbol);
}

void CustomString::resize(size_t size, char symbol) {
  if (size > _capacity)
    reserve(size);
  int i = _size;
  while (i < size) {
    _array[i] = symbol;
    i++;
    qDebug() << i << size;
  }
  i = size;
  while (i < _size) {
    ~(_array[i]);
    i++;
    qDebug() << i << _size;
  }
  _size = size;
}

void CustomString::swap(CustomString& string) {
  std::swap(_array, string._array);
  std::swap(_size, string._size);
  std::swap(_capacity, string._capacity);
}

void CustomString::clear() {
  resize(0);
}

void CustomString::pop_back() {
  _size--;
  ~(_array[_size]);
}

char& CustomString::front() {
  return _array[0];
}

char& CustomString::back() {
  return _array[_size - 1];
}

char& CustomString::at(size_t number) {
  if (number > _size) {
    throw "";
  } else {
    return _array[number];
  }
}

void CustomString::reserve(size_t size) {
  if (size <= _capacity)
    return;
  std::unique_ptr<char[]> temp = make_unique<char[]>(size);
  for (int i = 0; i < _size; i++) {
    temp[i] = _array[i];
  }
  _array = std::move(temp);
  _capacity = size;
}

bool CustomString::empty() const {
  return _size;
}

char& CustomString::operator[](size_t number) {
  return _array[number];
}

CustomString::CustomString(CustomString& line) {
  _size = line._size;
  _capacity = line._capacity;
  resize(_capacity);
}

size_t CustomString::capacity() const {
  return _capacity;
}

size_t CustomString::size() const {
  return _size;
}
