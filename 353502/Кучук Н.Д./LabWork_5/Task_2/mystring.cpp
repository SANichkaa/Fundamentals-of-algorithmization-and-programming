#include "mystring.h"


String::String() : data(nullptr), size(0) {}

String::String(const char* s) : size(strlen(s)) {
    data = std::make_unique<char[]>(size + 1);
    strcpy(data.get(), s);
}

String::String(const String& other) : size(other.size) {
    data = std::make_unique<char[]>(size + 1);
    strcpy(data.get(), other.data.get());
}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    data = std::make_unique<char[]>(size + 1);
    strcpy(data.get(), other.data.get());
    return *this;
}

String::String(String&& other) noexcept : data(std::move(other.data)), size(other.size) {
    other.size = 0;
}

String& String::operator=(String&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    data = std::move(other.data);
    size = other.size;
    other.size = 0;
    return *this;
}

String::~String() = default;

size_t String::length() const {
    return size;
}

const char* String::c_str() const {
    return data.get();
}

char& String::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char& String::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

String::Iterator::Iterator(char* p) : ptr(p) {}

char& String::Iterator::operator*() const {
    return *ptr;
}

String::Iterator& String::Iterator::operator++() {
    ++ptr;
    return *this;
}

String::Iterator String::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

bool String::Iterator::operator==(const Iterator& other) const {
    return ptr == other.ptr;
}

bool String::Iterator::operator!=(const Iterator& other) const {
    return ptr != other.ptr;
}

String::Iterator String::begin() {
    return Iterator(data.get());
}

String::Iterator String::end() {
    return Iterator(data.get() + size);
}

// Реализация функций
void* memcpy(void* s1, const void* s2, size_t n) {
    return std::memcpy(s1, s2, n);
}

void* memmove(void* s1, const void* s2, size_t n) {
    return std::memmove(s1, s2, n);
}

char* strcpy(char* s1, const char* s2) {
    return std::strcpy(s1, s2);
}

char* strncpy(char* s1, const char* s2, size_t n) {
    return std::strncpy(s1, s2, n);
}

char* strcat(char* s1, const char* s2) {
    return std::strcat(s1, s2);
}

char* strncat(char* s1, const char* s2, size_t n) {
    return std::strncat(s1, s2, n);
}

int memcmp(const void* s1, const void* s2, size_t n) {
    return std::memcmp(s1, s2, n);
}

int strcmp(const char* s1, const char* s2) {
    return std::strcmp(s1, s2);
}

int strcoll(const char* s1, const char* s2) {
    return std::strcoll(s1, s2);
}

int strncmp(const char* s1, const char* s2, size_t n) {
    return std::strncmp(s1, s2, n);
}

size_t strxfrm(char* s1, const char* s2, size_t n) {
    return std::strxfrm(s1, s2, n);
}

char* strtok(char* s1, const char* s2) {
    return std::strtok(s1, s2);
}

void* memset(void* s, int c, size_t n) {
    return std::memset(s, c, n);
}

char* strerror(int errnum) {
    return std::strerror(errnum);
}

size_t strlen(const char* s) {
    return std::strlen(s);
}

// Пример использования в main.cpp
int main() {
    String str1("Hello");
    String str2("World");
    String str3 = str1;
    str3 = str2;

    for (auto it = str1.begin(); it != str1.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Length of str1: " << str1.length() << std::endl;

    return 0;
}
