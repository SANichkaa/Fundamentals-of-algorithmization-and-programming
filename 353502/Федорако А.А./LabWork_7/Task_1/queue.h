#ifndef QUEUE_H
#define QUEUE_H

#include <QDebug>
#include <QVector>

template <typename T>

class Queue {
  struct Node {
    T value;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(T _value, Node* _next = nullptr, Node* _prev = nullptr)
        : value(_value), next(_next), prev(_prev) {}
  };
  Node* top = nullptr;
  Node* tail = nullptr;

 public:
  Queue() {}

  void push(T value) {
    Node* node = new Node(value, top);
    if (top) {
      top->prev = node;
    }
    top = node;
  }

  T pop() {
    if (!top) {
      throw "Queue is empty";
    } else {
      Node* temp = top;
      top = top->next;
      return temp->value;
      delete temp;
    }
  }

  bool isEmpty() { return !top; }

  int size() {
    int result = 0;
    Node* temp = top;
    while (temp) {
      result++;
      temp = temp->next;
    }
    return result;
  }

  void clear() {
    while (top) {
      pop();
    }
  }

  void deleteAtPosition(int position) {
    if (position < 0 || position >= size()) {
      return;
    }

    if (position == size() - 1) {
      pop();
    } else {
      Node* temp = top;
      for (int i = 0; i < position; ++i) {
        temp = temp->next;
      }
      if (temp) {
        if (temp->prev) {
          temp->prev->next = temp->next;
        }
        if (temp->next) {
          temp->next->prev = temp->prev;
        }
        delete temp;
        return;
      }
    }
  }

  void insertAtPosition(int position, T value) {
    if (position < 0 || position > size()) {
      return;
    }

    Node* newNode = new Node(value);

    if (position == 0) {
      newNode->next = top;
      if (top) {
        top->prev = newNode;
      }
      top = newNode;
    } else {
      Node* temp = top;
      for (int i = 0; i < position - 1; ++i) {
        temp = temp->next;
      }
      newNode->next = temp->next;
      newNode->prev = temp;
      if (temp->next) {
        temp->next->prev = newNode;
      }
      temp->next = newNode;
    }
  }

  QVector<T> toVector() {
    QVector<T> result;
    Node* temp = top;
    while (temp) {
      result.push_back(temp->value);
      temp = temp->next;
    }
    return result;
  }

  virtual ~Queue() { clear(); }
};

#endif  // QUEUE_H
