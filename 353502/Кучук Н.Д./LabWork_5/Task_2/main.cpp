#include "mystring.h"

//#include <QApplication>

int main()
{
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
