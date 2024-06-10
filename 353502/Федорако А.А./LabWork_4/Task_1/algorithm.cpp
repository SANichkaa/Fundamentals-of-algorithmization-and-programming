#include "algorithm.h"

Algorithm::Algorithm() {}

long Algorithm::BinSearch(long* arr, long value, long l, long r) {
  if (l > r) {
    return -1;
  }
  long mid = l + (r - l) / 2;
  if (arr[mid] == value) {
    return mid;
  } else if (arr[mid] > value) {
    return BinSearch(arr, value, l, mid - 1);
  } else {
    return BinSearch(arr, value, mid + 1, r);
  }
}

long long Algorithm::BinPow(long value, long n, long mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    long long res = BinPow(value, n / 2, mod) % mod;
    return (res * res) % mod;
  }
  return ((BinPow(value, n - 1, mod) % mod) * (value % mod)) % mod;
}
