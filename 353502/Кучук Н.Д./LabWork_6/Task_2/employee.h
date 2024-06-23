#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    int id;
    double salary;
    char grade;
    bool isActive;
    static const int nameLength = 50;
    char name[nameLength];
    static const int scoresCount = 3;
    int scores[scoresCount];

};
#endif // EMPLOYEE_H
