#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair {
 public:
  T1 first;
  T2 second;
  Pair() {}
  Pair(T1 firstNumber, T2 secondNumber)
      : first(firstNumber), second(secondNumber) {}
  static Pair make_pair(T1 firstNumber, T2 secondNumber) {
    return Pair(firstNumber, secondNumber);
  }
  Pair tuple_size() { return sizeof(T1) + sizeof(T2); }
};

#endif  // PAIR_H
