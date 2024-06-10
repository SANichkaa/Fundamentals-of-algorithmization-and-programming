#include "date.h"

Date::Date() = default;

int Date::Days_in_month(int month, int year) {
  bool vis = false;

  if (year % 4 == 0) {
    vis = true;
  } else {
    vis = false;
  }

  if (month == n1 or month == n3 or month == n5 or month == n7 or month == n8 or
      month == n10 or month == n12) {
    return n31;
  } else if (month == n2) {
    return (n28 + vis);
  } else {
    return n30;
  }
}

QString Date::Today() {
  const int n16 = 16;
  QString mes;

  time_t timer = time(nullptr);
  QString today = asctime(localtime(&timer));

  today.remove(0, 4);

  QString month;
  month.append(today[0]);
  month.append(today[n1]);
  month.append(today[n2]);

  QString day;
  day.append(today[n4]);
  day.append(today[n5]);

  if (month == "Jan") {
    mes = "01";
  } else if (month == "Feb") {
    mes = "02";
  } else if (month == "Mar") {
    mes = "03";
  } else if (month == "Apr") {
    mes = "04";
  } else if (month == "May") {
    mes = "05";
  } else if (month == "Jun") {
    mes = "06";
  } else if (month == "Jul") {
    mes = "07";
  } else if (month == "Aug") {
    mes = "08";
  } else if (month == "Sep") {
    mes = "09";
  } else if (month == "Oct") {
    mes = "10";
  } else if (month == "Nov") {
    mes = "11";
  } else {
    mes = "12";
  }

  today.remove(0, n16);

  this->day = day;
  month_named = month;
  month_numbers = mes;
  year = today;

  return day + ' ' + month + ' ' + today;
}

QString Date::NextDay() {
  const int day_up = 24 * 3600, n16 = 16;

  time_t timer = time(nullptr) + day_up;
  QString today = asctime(localtime(&timer));

  today.remove(0, 4);

  QString month;
  month.append(today[0]);
  month.append(today[1]);
  month.append(today[2]);

  QString day;
  day.append(today[4]);
  day.append(today[n5]);

  today.remove(0, n16);

  return day + ' ' + month + ' ' + today;
}

QString Date::PreviousDay() {
  const int day_down = -24 * 3600, n16 = 16;

  time_t timer = time(nullptr) + day_down;
  QString today = asctime(localtime(&timer));

  today.remove(0, 4);

  QString month;
  month.append(today[0]);
  month.append(today[1]);
  month.append(today[2]);

  QString day;
  day.append(today[4]);
  day.append(today[n5]);

  today.remove(0, n16);

  return day + ' ' + month + ' ' + today;
}

bool Date::IsLeap() {
  int x = year.toInt() % 4;

  if (x == 0) {
    return true;
  } else {
    return false;
  }
}

int Date::WeekNumber() {
  int days = day.toInt();
  int mes = month_numbers.toInt();
  const int day_in_week = 7;

  while (mes != n1) {
    days += Days_in_month(mes, year.toInt());

    mes--;
  }

  return days / day_in_week + 1;
}

QString Date::DaysTillYourBithday(QString date) {
  const int days_in_year = 365;

  QString date_day;
  date_day.append(date[0]);
  date_day.append(date[n1]);

  date.remove(0, n3);

  QString date_month;
  date_month.append(date[0]);
  date_month.append(date[n1]);

  date.remove(0, n3);

  QString date_year;
  date_year = date;

  int days1 = date_day.toInt() + date_month.toInt() * n30;

  int days = day.toInt() + month_numbers.toInt() * n30;

  if (days1 - days >= 0) {
    return QString::fromStdString(std::to_string(days1 - days) + " дней");
  } else {
    return QString::fromStdString(std::to_string(days1 - days + days_in_year) +
                                  " дней");
  }
}

QString Date::Duration(QString date1, QString date2) {
  QString date1_day;
  date1_day.append(date1[0]);
  date1_day.append(date1[n1]);

  date1.remove(0, n3);

  QString date1_month;
  date1_month.append(date1[0]);
  date1_month.append(date1[n1]);

  date1.remove(0, n3);

  QString date1_year;
  date1_year = date1;

  QString date2_day;
  date2_day.append(date2[0]);
  date2_day.append(date2[n1]);

  date2.remove(0, n3);

  QString date2_month;
  date2_month.append(date2[0]);
  date2_month.append(date2[n1]);

  date2.remove(0, n3);

  QString date2_year;
  date2_year = date2;

  int day1 = date1_day.toInt(), day2 = date2_day.toInt(),
      month1 = date1_month.toInt(), month2 = date2_month.toInt(),
      year1 = date1_year.toInt(), year2 = date2_year.toInt(), years = 0,
      month = 0, days = 0;

  if (year1 > year2) {
    years = year1 - year2;

    if (day1 >= day2 and month1 >= month2) {
      days = day1 - day2;

      month = month1 - month2;

    }

    else if (day1 >= day2 and month1 < month2) {
      years--;

      days = day1 - day2;

      month = month1 - month2 + n12;

    }

    else if (day1 < day2 and month1 >= month2) {
      month = month1 - month2;

      if (month1 != month2) {
        days =
            day1 - day2 + Days_in_month(month1 != 1 ? month1 - 1 : n12, year1);

      } else {
        years--;

        month = n11;

        days = day1 - day2 + Days_in_month(n10, year1);
      }

    }

    else {
      years--;

      month = month1 - month2 + n11;

      days = day1 - day2 + Days_in_month(month1--, year1);
    }
  }

  else if (year1 == year2) {
    if (day1 > day2 and month1 > month2 or day1 < day2 and month1 < month2) {
      days = qAbs(day1 - day2);

      month = qAbs(month1 - month2);

    }

    else if (day1 > day2 and month1 < month2 or
             day1 < day2 and month1 > month2) {
      days = qAbs(day1 - day2 + Days_in_month(month1, year1));

      month = qAbs(month1 - month2 - 1);

    }

    else if (month1 == month2) {
      days = qAbs(day1 - day2);
    } else {
      month = qAbs(month1 - month2);
    }
  } else {
    years = year2 - year1;

    if (day2 >= day1 and month2 >= month1) {
      days = day2 - day1;

      month = month2 - month1;

    }

    else if (day2 >= day1 and month2 < month1) {
      years--;

      days = day2 - day1;

      month = month2 - month1 + n12;

    }

    else if (day2 < day1 and month2 >= month1) {
      month = month2 - month1;

      if (month1 != month2) {
        days =
            day2 - day1 + Days_in_month(month2 != 1 ? month2 - 1 : n12, year2);

      } else {
        years--;

        month = n11;

        days = day2 - day1 + Days_in_month(n10, year2);
      }

    }

    else {
      years--;

      month = month2 - month1 + n11;

      days = day2 - day1 + Days_in_month(month2--, year2);
    }
  }

  QString result;

  if (days != 0 and days != 1) {
    result.append(QString::number(days) + " дней ");
  }
  if (days == 1) {
    result.append("1 день ");
  }

  if (month != 0 and month != 1) {
    result.append(QString::number(month) + " месяцев ");
  }
  if (month == 1) {
    result.append(" 1 месяц ");
  }
  if (years != 0 and years != 1) {
    result.append(QString::number(years) + " годиков ");
  }
  if (years == 1) {
    result.append(" 1 год ");
  }

  return result;
}

QString Date::GetToday() { return day + '.' + month_numbers + '.' + year; }
