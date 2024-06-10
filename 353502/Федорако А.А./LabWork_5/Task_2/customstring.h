#ifndef STRING_CUSTOMSTRING_H
#define STRING_CUSTOMSTRING_H

#include <QString>
#include <cstdint>
#include <cstring>
#include <memory>
#include "../Lab4_4/iterator.h"
#include "../Lab4_4/reverceiterator.h"

template <typename T>
std::unique_ptr<T> make_unique(std::size_t size) {
  return std::unique_ptr<T>(new typename std::remove_extent<T>::type[size]);
}

class CustomString {

 private:
  std::unique_ptr<char[]> _array = make_unique<char[]>(1);
  size_t _size = 0;
  size_t _capacity = 1;

 public:
  using b_iterator = Iterator<char>;
  using r_iterator = ReverceIterator<char>;
  using c_iterator = Iterator<const char>;

  CustomString();
  CustomString(size_t size);
  CustomString(QString& line);
  CustomString(CustomString& line);
  CustomString(char* str);
  ~CustomString();
  void push_back(char temp);
  void assign(size_t size, char temp);
  void clear();
  void pop_back();
  char& front();
  char& back();
  char& at(size_t pos_);
  size_t capacity() const;
  size_t size() const;
  void resize(size_t size, char temp = char());
  void reserve(size_t size);
  bool empty() const;
  void swap(CustomString& string);

  void operator=(const char*);
  char& operator[](size_t number);

  b_iterator begin();
  b_iterator end();
  r_iterator rbegin();
  r_iterator rend();
};

#endif  //STRING_CUSTOMSTRING_H
