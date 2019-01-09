#pragma once

#include "Utility/String.h"

typedef struct Date {

    int year;
    int month;
    int day;
    int hour;
    int minute;

} Date;

void currentDate(Date* date);

void dateToString(const Date* date, String target);
long long dateToLongLong(const Date* date);
void longLongToDate(long long value, Date* date);
