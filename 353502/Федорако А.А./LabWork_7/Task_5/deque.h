#ifndef DEQUE_H
#define DEQUE_H
#include <stdexcept>

template <typename T>
class Deque {
 private:
  static const int NUMBER_ELENENTS_IN_BLOCK = 4;

  class Node {
   public:
    int _size;
    Node* prev;
    Node* next;
    T* data;
    Node()
        : _size(0),
          prev(nullptr),
          next(nullptr),
          data(new T[NUMBER_ELENENTS_IN_BLOCK]){};
  };

  Node* top;
  Node* tail;
  size_t _size = 0;
  size_t _capacity = 0;

 public:
  Deque() {}
  ~Deque() {}

  void push_front(T data) {
    if (!_capacity) {
      top = new Node;
      tail = new Node;
      top->data[0] = data;
      top->_size++;
      _capacity++;
      _size++;
    } else {
      if (top->_size < NUMBER_ELENENTS_IN_BLOCK) {
        int i = top->_size - 1;
        while (i >= 0) {
          top->data[i + 1] = top->data[i];
          i--;
        }
        top->data[0] = data;
        top->_size++;
        _size++;
      } else {
        top->prev = new Node;
        top->prev->next = top;
        top = top->prev;
        top->_size++;
        top->data[0] = data;
        _capacity++;
        _size++;
      }
    }
  }

  void push_back(T data) {
    if (!_capacity) {
      top = new Node;
      tail = top;
      tail->_size++;
      tail->data[0] = data;
      _capacity++;
      _size++;
    } else {
      if (tail->_size < NUMBER_ELENENTS_IN_BLOCK) {
        tail->data[tail->_size] = data;
        tail->_size++;
        _size++;
      } else {
        tail->next = new Node;
        tail->next->prev = tail;
        tail = tail->next;
        tail->_size++;
        tail->data[0] = data;
        _capacity++;
        _size++;
      }
    }
  }

  size_t capacity() const { return _capacity; }
  size_t size() const { return _size; }

  bool isEmpty() const { return !_size; }

  void pop_back() {
    if (top) {
      if (tail->_size > 1) {
        tail->_size--;
      } else {
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
          delete temp;
          tail->next = nullptr;
        } else {
          clear();
        }
      }
      _size--;
    } else {
      throw "Deque is empty";
    }
  }

  void pop_front() {
    if (top) {
      if (top->_size > 1) {
        for (int i = 0; i + 1 < top->_size; i++) {
          top->data[i] = top->data[i + 1];
        }
        top->_size--;
      } else {
        Node* temp = top;
        top = top->next;
        if (top) {
          delete temp;
          top->prev = nullptr;
        } else {
          clear();
        }
      }
      _size--;
    } else {
      throw "Deque is empty";
    }
  }

  void clear() {
    while (!isEmpty()) {
      pop_back();
    }
  }

  class Iterator {
    Node* node;
    size_t number;

   public:
    Iterator(Node* node, size_t index) : node(node), number(index) {}

    Iterator& operator--() {
      if (node && number) {
        node = node->prev;
        if (node) {
          number = node->_size - 1;
        } else {
          number = 0;
        }
      } else if (node) {
        number--;
      }
      return *this;
    }

    Iterator& operator++() {
      if (node && number == node->_size - 1) {
        node = node->next;
        number = 0;
      } else if (node) {
        number++;
      }
      return *this;
    }

    T& operator*() const { return node->data[number]; }

    bool operator==(const Iterator& iterator) const {
      return node == iterator.node;
    }

    bool operator!=(const Iterator& iterator) const {
      return !(node == iterator.node);
    }
  };

  Iterator begin() { return Iterator(top, 0); }

  Iterator end() { return Iterator(0, 0); }
};

#endif  // DEQUE_H
