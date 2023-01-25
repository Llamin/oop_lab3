#ifndef DATE_H
#define DATE_H

class Date
{
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day);
    Date(const Date& d);
    int getYear();
    int getMonth();
    int getDay();
    void showDate();
    void setCurrentDate();
    void operator ++();
    void operator --();
    void operator ++(int);
    void operator --(int);
    bool operator == (const Date& temp);
    bool operator != (const Date& temp);
    void operator = (const Date& temp);
};

#endif // DATE_H
