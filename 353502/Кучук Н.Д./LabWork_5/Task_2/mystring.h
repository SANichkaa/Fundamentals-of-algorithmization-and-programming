#ifndef MYSTRING_H
#define MYSTRING_H

#include <memory>
#include <cstring>
#include <iostream>>
#include <stdexcept>

class String {
private:
    std::unique_ptr<char[]> data;
    size_t size;

public:
    String();
    String(const char* s);

    String(const String& other);

    String& operator=(const String& other);

    String(String&& other) noexcept;

    String& operator=(String&& other) noexcept;

    ~String();

    size_t length() const;
    const char* c_str() const;

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    class Iterator {
    private:
        char* ptr;
    public:
        Iterator(char* p);
        char& operator*() const;
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

void* memcpy(void* s1, const void* s2, size_t n);
void* memmove(void* s1, const void* s2, size_t n);
char* strcpy(char* s1, const char* s2);
char* strncpy(char* s1, const char* s2, size_t n);
char* strcat(char* s1, const char* s2);
char* strncat(char* s1, const char* s2, size_t n);
int memcmp(const void* s1, const void* s2, size_t n);
int strcmp(const char* s1, const char* s2);
int strcoll(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);
size_t strxfrm(char* s1, const char* s2, size_t n);
char* strtok(char* s1, const char* s2);
void* memset(void* s, int c, size_t n);
char* strerror(int errnum);
size_t strlen(const char* s);


#endif // MYSTRING_H
