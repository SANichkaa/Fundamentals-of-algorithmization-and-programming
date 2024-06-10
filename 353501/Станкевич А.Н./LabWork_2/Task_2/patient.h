#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <iostream>

class Patient
{
public:
    QString name;
    QString gender;
    QString diagnosis;
    long long number;
    long long age;

    Patient();
    ~Patient();
    Patient(QString a, QString b, long long c, QString d, long long e) : name(a), gender(b), diagnosis(d), number(e), age(c) {}
};

#endif // PATIENT_H
