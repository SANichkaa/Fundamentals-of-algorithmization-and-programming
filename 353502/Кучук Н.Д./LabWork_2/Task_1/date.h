#ifndef DATE_H
#define DATE_H
#include <QDate>
#include <QApplication>
#include <sstream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y);
    Date();

    Date NextDay() const;

    Date PreviousDay() const;

    bool IsLeap() const ;

    static bool IsValid(int y, int m , int d );

    int WeekNumber() const ;

    int DaysTillYourBirthday(const Date &birthday) const ;

    int Duration(const Date &date) const ;

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    static QString ToString(int y, int m , int d );

    static Date fromString(const QString &dateStr);
};

#endif // DATE_H
