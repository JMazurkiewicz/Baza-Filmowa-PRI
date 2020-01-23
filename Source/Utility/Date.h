#pragma once

#include "String.h"

typedef struct Date {

    int year;
    int month;
    int day;
    int hour;
    int minute;

} Date;

void currentDate(Date* date);

long long dateToLongLong(const Date* date);
void longLongToDate(long long value, Date* date);

void printDate(const Date* date);
