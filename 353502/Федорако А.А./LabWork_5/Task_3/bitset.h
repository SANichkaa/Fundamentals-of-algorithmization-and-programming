#ifndef BITSET_H
#define BITSET_H

#include <QString>

class BitSet {
 private:
  const int ELEMENT_SIZE = sizeof(unsigned int) * 8;
  unsigned int* _bitset;
  int _size;

 public:
  BitSet(int size);
  ~BitSet();
  bool all() const;
  bool any() const;
  int count() const;
  void flip();
  void flip(int pos);
  bool none() const;
  void reset();
  void reset(int pos);
  void set();
  void set(int pos);
  int size() const;
  bool test(int pos) const;
  QString to_string();
  unsigned long long to_ullong() const;
  unsigned long to_ulong() const;
  bool operator[](int pos);
};

#endif  // BITSET_H
