#ifndef DATE_H
#define DATE_H

#include <QObject>
#include <QString>

class Date : public QObject
{
    Q_OBJECT
public:
    Date();
    int Days_in_month(int month, int year);
    QString Today();
    QString NextDay();
    QString PreviousDay();
    bool IsLeap();
    int WeekNumber();
    QString DaysTillYourBithday(QString date);
    QString Duration(QString date1, QString date2);
    QString GetToday();

private:
    QString day, month_named, year, month_numbers;
    enum months { n1 = 1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12 };
    enum days_in_month { n28 = 28, n29, n30, n31 };
};

#endif // DATE_H
