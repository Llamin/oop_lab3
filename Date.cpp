#include <iostream>
#include <ctime>

#include "Date.h"

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(const Date& d)
{
    year = d.year;
    month = d.month;
    day = d.day;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::showDate()
{
    std::cout << "Date: " << day << '.' << month << '.' << year << std::endl;
}

void Date::setCurrentDate()
{
    time_t t = time(NULL);

    tm* timePtr = localtime(&t);

    year = timePtr->tm_year + 1900;
    month = timePtr->tm_mon + 1;
    day = timePtr->tm_mday;
}

void Date::operator ++()
{
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
    {
        day = 1;
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
        {
            month++;
        }
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        month++;
        day = 1;
    }
    else if (month == 2)
    {
        bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
        if ((leap && day == 29) || (!leap && day == 28))
        {
            day = 1;
            month++;
        }
    }
    else
    {
        day++;
    }

}

void Date::operator --()
{
    if (day == 1)
    {
        if(month == 5 || month == 7 || month == 10 || month == 12)
        {
            day = 30;
        }
        else if((month == 1 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11))
        {
            if (month == 1)
            {
                year--;
                month = 12;
            }
            else
            {
                month--;
            }
            day = 31;
        }
        else if (month == 3)
        {
            month--;
            bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
            if (leap)
            {
                day = 29;

            }
            else if (!leap)
            {
                day = 28;
            }
        }
    }
    else
    {
        day--;
    }
}

void Date::operator ++(int)
{
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
    {
        day = 1;
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
        {
            month++;
        }
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        month++;
        day = 1;
    }
    else if (month == 2)
    {
        bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
        if ((leap && day == 29) || (!leap && day == 28))
        {
            day = 1;
            month++;
        }
    }
    else
    {
        day++;
    }

}

void Date::operator -- (int)
{
    if (day == 1)
    {
        if(month == 5 || month == 7 || month == 10 || month == 12)
        {
            day = 30;
        }
        else if((month == 1 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11))
        {
            if (month == 1)
            {
                year--;
                month = 12;
            }
            else
            {
                month--;
            }
            day = 31;
        }
        else if (month == 3)
        {
            month--;
            bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
            if (leap)
            {
                day = 29;

            }
            else if (!leap)
            {
                day = 28;
            }
        }
    }
    else
    {
        day--;
    }
}

bool Date::operator == (const Date& temp)
{
    bool result = false;
    if(this->day == temp.day)
        if(this->month == temp.month)
            if(this->year == temp.year)
                result = true;

    return result;
}

bool Date::operator != (const Date& temp)
{
    return this->day != temp.day || this->month != temp.month || this->year != temp.year;

}

void Date::operator = (const Date& temp)
{
    this->day = temp.day;
    this->month = temp.month;
    this->year = temp.year;
}
