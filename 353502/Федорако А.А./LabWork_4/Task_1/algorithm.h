#ifndef ALGORITHM_H
#define ALGORITHM_H

class Algorithm {
 public:
  Algorithm();
  static long BinSearch(long* arr, long value, long l, long r);
  static long long BinPow(long value, long n, long mod);
};

#endif  // ALGORITHM_H
