#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <iostream>
#include <map>

class MyCalendar{
    public:
        MyCalendar()
        {
            _year = 0;
            _month = 1;
            _day = 1; 
        };
        MyCalendar(int year, int month, int day)
        {
            if (!SetDate(year,month,day))
            {
               _year = 0;
               _month = 1;
               _day = 1; 
            }
        };

        bool NextDay(int n = 1)
        {
            int original_year = _year;
            int original_month = _month;
            int original_day = _day;
            _day += n;

            // Handle positive or zero values for `n`
            while (_day > 0) 
            {
                int maxDay = days_for_month[_month];
                if (_month == 2 && isLeapYear(_year)) 
                {
                    maxDay = 29; 
                }

                if (_day <= maxDay) 
                {
                    break; 
                }

                _day -= maxDay;
                _month += 1;
                if (_month > 12) 
                {
                    _month = 1;
                    _year += 1;
                }
            }
            // Handle negative values for `n`
            while (_day <= 0) 
            {
                _month -= 1;

                if (_month <= 0) 
                {
                    _month = 12;
                    _year -= 1;
                }

                int maxDay = days_for_month[_month];
                if (_month == 2 && isLeapYear(_year)) 
                {
                    maxDay = 29;
                }
                _day += maxDay;
            }

            if (_year > 9999 || _year < 0)
            {
                printInvalidDate(_year, _month, _day);
                _year = original_year;
                _month = original_month;
                _day = original_day;
                return false;
            }
            return true;
        };
        bool SetDate(int year, int month, int day)
        {
            if (!checkConditions(year,month,day)) return false;
            _year = year;
            _month = month;
            _day = day;
            return true;
        };

        int year() const {return _year;};
        int month() const {return _month;};
        int day() const {return _day;};

        bool checkConditions(int year, int month, int day)
        {
            if (year > 9999 || year < 0 || month < 1 || month > 12 || day < 1)
            {
                printInvalidDate(year,month,day);
                return false;
            }

            if (isLeapYear(year) && month == 2)
            {
                if (day > days_for_month[month] + 1) 
                {
                    printInvalidDate(year,month,day);
                    return false;
                }
            }
            else if (day > days_for_month[month])
            {
                printInvalidDate(year,month,day);
                return false;
            }
            return true;
        };
        void printDate()
        {
            std::cout << _year << "." << _month << "." << _day << std::endl;
        };
    private:
        static int GetDaysInYear(int year);
        static int ComputeDaysFromYearStart(int year, int month, int day);
        int _year, _month, _day;
        std::map<int, int> days_for_month = {
            {1, 31},
            {2, 28},
            {3, 31},
            {4, 30},
            {5, 31},
            {6, 30},
            {7, 31},
            {8, 31},
            {9, 30},
            {10, 31},
            {11, 30},
            {12, 31}
        };
        void printInvalidDate(int year, int month, int day)
        {
            std::cout << "Invalid date: " <<year<<"."<<month<<"."<<day<< std::endl;
        };
        bool isLeapYear(int year) 
        {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        };
};

//The format for input/output is hh:mm:ss
std::ostream& operator<<(std::ostream& out, const MyCalendar& c);
std::istream& operator>>(std::istream& in, MyCalendar& c);

#endif