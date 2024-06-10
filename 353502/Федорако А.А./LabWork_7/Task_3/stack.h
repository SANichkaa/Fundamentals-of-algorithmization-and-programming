#ifndef STACK_H
#define STACK_H

#include <QVector>

template <typename T>

class Stack {
  struct Node {
    T value;
    Node* next = nullptr;
    Node(T _value, Node* _next = nullptr) : value(_value), next(_next) {}
  };
  Node* top;

 public:
  Stack() { top = nullptr; }
  void push(T value) {
    Node* temp = new Node(value);
    if (!temp) {
      throw "Stack overflow";
    }
    temp->next = top;
    top = temp;
  }
  T pop() {
    Node* temp;
    if (!top) {
      throw "Stack overflow";
    } else {
      temp = top;
      top = top->link;
      free(temp);
    }
  }
  bool isEmpty() { return !top; }
  T peek() { return top; }
  QVector<T> toVector() {
    QVector<T> result;
    Node* temp = top;
    while (temp) {
      result.push_back(temp->value);
      temp = temp->next;
    }
    return result;
  }
};

#endif  // STACK_H
