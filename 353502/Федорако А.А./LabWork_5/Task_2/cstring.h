#ifndef CSTRING_H
#define CSTRING_H

#include <cstddef>

class CString {
 public:
  CString();

  static void* my_memcpy(void* dest, const void* src, size_t size) {
    char* first = static_cast<char*>(dest);
    const char* second = static_cast<const char*>(src);

    for (size_t i = 0; i < size; i++) {
      first[i] = second[i];
    }
  }

  static void* my_memmove(void* dest, void* src, size_t size) {
    char* first = static_cast<char*>(dest);
    char* second = static_cast<char*>(src);

    if (first < second) {
      for (size_t i = 0; i < size; i++) {
        first[i] = second[i];
      }
    }
    if (first > second) {
      for (size_t i = size; i > 0; i--) {
        first[i - 1] = second[i - 1];
      }
    }
    return dest;
  }

  static char* my_strcat(char* dest, char* src) {
    char* line = dest;
    while (*line != '\0') {
      line++;
    }
    while (*src != '\0') {
      *line = *src;
      line++;
      src++;
    }
    *line = '\0';
    return dest;
  }

  static char* my_strncat(char* dest, char* src, size_t size) {
    char* line = dest;
    while (*line != '\0') {
      line++;
    }
    while (*src != '\0' && size--) {
      *line = *src;
      line++;
      src++;
    }
    *line = '\0';
    return dest;
  }

  static void* my_memset(void* ptr, int value, size_t size) {
    char* temp = static_cast<char*>(ptr);
    char v = static_cast<char>(value);
    size_t i = 0;
    while (i < size) {
      temp[i] = v;
      i++;
    }
    temp[size] = '\0';
    return ptr;
  }

  static int my_memcmp(void* dest, void* src, size_t n) {
    char* left = static_cast<char*>(dest);
    char* right = static_cast<char*>(src);
    while (*left == *right && n--) {
      left++;
      right++;
    }
    if (*left > *right)
      return 1;
    if (*left < *right)
      return -1;
    return 0;
  }

  static size_t my_strlen(const char* s) {
    size_t n = 0;
    do {
      n++;
      s++;
    } while (*s != '\0');
    return n;
  }

  static int my_strcmp(const char* left, char* right) {

    while (*left == *right && *left != '\0' && *right != '\0') {
      left++;
      right++;
    }

    if (*left > *right) {
      return 1;
    }
    if (*left < *right) {
      return -1;
    }
    return 0;
  }

  static int my_strncmp(const char* left, const char* right, size_t size) {
    while (*left == *right && *left != '\0' && *right != '\0' && size--) {
      left++;
      right++;
    }
    if (*left > *right) {
      return 1;
    }
    if (*left < *right) {
      return -1;
    }
    return 0;
  }
};

#endif  // CSTRING_H
