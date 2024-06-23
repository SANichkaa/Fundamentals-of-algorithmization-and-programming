#include "date.h"


Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date::Date() {}

Date Date::NextDay() const
{
    QDate date(year, month, day);
    date = date.addDays(1);
    return Date(date.day(), date.month(), date.year());
}

Date Date::PreviousDay() const
{
    QDate date(year, month, day);
    date = date.addDays(-1);
    return Date(date.day(), date.month(), date.year());
}

bool Date::IsLeap() const
{
    QDate date(year, month, day);
    return date.isLeapYear(year);
}

bool Date::IsValid(int y, int m, int d)
{
    return QDate::isValid(y, m, d);
}


int Date::WeekNumber() const
{
    QDate date(year, month, day);
    return date.weekNumber();
}

int Date::DaysTillYourBirthday(const Date &birthday) const
{
    QDate currentDate(year, month, day);
    QDate birthDate(currentDate.year(), birthday.month, birthday.day);

    if (currentDate > birthDate) {
        birthDate = birthDate.addYears(1);
    }

    return currentDate.daysTo(birthDate);
}

int Date::Duration(const Date &date) const
{
    QDate currentDate(year, month, day);
    QDate otherDate(date.year, date.month, date.day);
    return qAbs(currentDate.daysTo(otherDate));
}

QString Date::ToString(int y, int m , int d )
{
    QString string = QString("%1.%2.%3").arg(d, 2, 10, QChar('0')).arg(m, 2, 10, QChar('0')).arg(y, 4, 10, QChar('0'));
    return string;
}

Date Date::fromString(const QString &dateStr)
{
    QStringList dateParts = dateStr.split(".");
    int d = dateParts[0].toInt();
    int m = dateParts[1].toInt();
    int y = dateParts[2].toInt();
    return Date(d, m, y);
}
