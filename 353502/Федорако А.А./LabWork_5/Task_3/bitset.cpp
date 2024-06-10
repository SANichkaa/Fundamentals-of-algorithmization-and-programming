#include "bitset.h"

BitSet::BitSet(int size) : _size(size) {
  _bitset = new unsigned int[size / ELEMENT_SIZE + 1];
  for (int i = 0; i < size / ELEMENT_SIZE + 1; i++) {
    _bitset[i] = 0;
  }
}

BitSet::~BitSet() {
  delete[] _bitset;
  _size = 0;
}

int BitSet::size() const {
  return _size;
}

void BitSet::set(int number) {
  int index = number / ELEMENT_SIZE;
  int pos = number % number;
  _bitset[index] |= (1 << pos);
}

void BitSet::reset() {
  for (int i = 0; i < _size / ELEMENT_SIZE; i++) {
    _bitset[i] = 0;
  }
}

void BitSet::flip() {
  for (int i = 0; i < _size; i++) {
    _bitset[i] = ~_bitset[i];
  }
}

bool BitSet::operator[](int number) {
  if (number < 0 || number >= _size) {
    throw std::out_of_range("Index is out of range");
  }
  int index = number / ELEMENT_SIZE;
  int pos = index % ELEMENT_SIZE;
  return _bitset[index] & (1 << pos);
}

QString BitSet::to_string() {
  QString result;
  for (int i = 0; i < _size; i++) {
    int index = i / ELEMENT_SIZE;
    int pos = i % ELEMENT_SIZE;
    result.push_back((_bitset[index] & (1 << pos)) ? "1" : "0");
  }
  return result;
}

bool BitSet::all() const {
  for (int i = 0; i < _size / ELEMENT_SIZE; i++) {
    if (_bitset[i] != ~0) {
      return false;
    }
  }
  return true;
}

bool BitSet::test(int number) const {
  int index = number / ELEMENT_SIZE;
  int pos = number % number;
  return _bitset[index] & (1 << pos);
}

void BitSet::reset(int number) {
  int index = number / ELEMENT_SIZE;
  int pos = number % number;
  _bitset[index] &= ~(1 << pos);
}

bool BitSet::any() const {
  for (int i = 0; i < _size / ELEMENT_SIZE; i++) {
    if (_bitset[i] != 0) {
      return true;
    }
  }
  return false;
}

int BitSet::count() const {
  int result = 0;
  for (int i = 0; i < _size / ELEMENT_SIZE; i++) {
    unsigned int value = _bitset[i];
    while (value) {
      result += value & 1;
      value >>= 1;
    }
  }
  return result;
}

void BitSet::set() {
  for (int i = 0; i < _size / ELEMENT_SIZE; i++) {
    _bitset[i] = ~0;
  }
}

unsigned long long BitSet::to_ullong() const {
  if (_size > sizeof(unsigned long long) * 8) {
    throw std::overflow_error(
        "BitSet size is too large to represent as unsigned long long");
  }
  unsigned long long result = 0;
  for (int i = 0; i < _size; i++) {
    int index = i / ELEMENT_SIZE;
    int pos = i % ELEMENT_SIZE;
    if (_bitset[index] & (1 << pos)) {
      result |= 1ULL << i;
    }
  }
  return result;
}

bool BitSet::none() const {
  return !any();
}

void BitSet::flip(int number) {
  int index = number / ELEMENT_SIZE;
  int pos = number % number;
  _bitset[index] ^= (1 << pos);
}

unsigned long BitSet::to_ulong() const {
  if (_size > sizeof(unsigned long) * 8) {
    throw std::overflow_error(
        "BitSet size is too large to represent as unsigned long");
  }
  unsigned long result = 0;
  for (int i = 0; i < _size; i++) {
    int index = i / ELEMENT_SIZE;
    int pos = i % ELEMENT_SIZE;
    if (_bitset[index] & (1 << pos)) {
      result |= 1UL << i;
    }
  }
  return result;
}
