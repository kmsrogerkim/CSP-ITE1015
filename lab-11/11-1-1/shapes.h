#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <iostream>

class MyClock{
    public:
        void Tick(int seconds = 1)
        {
            // pile everything up to sec
            _sec += seconds;
            _sec += _hour * 3600;
            _sec += _min * 60;
            // then convert sec to hh:mm:ss
            _hour = _sec / 3600;
            int remaining_seconds = _sec % 3600;      
            _min = remaining_seconds / 60;              
            _sec = remaining_seconds % 60;              

            if (_hour < 0) while (_hour < 0) _hour = 23 + _hour;
            if (_min < 0) while (_min < 0) _min = 59 + _min;
            if (_sec < 0) while (_sec < 0) _sec = 60 + _sec;

            if (_hour > 23) while (_hour > 23) _hour -= 24;
        };
        bool SetTime(int hour, int minute, int second){
            if (hour > 23 || minute > 59 || second > 59 || hour < 0 || minute < 0 || second < 0)
            {
                std::cout << "Invalid Time: " <<hour<<":"<<minute<<":"<<second << std::endl;
                return false;
            }
            _hour = hour;
            _min = minute;
            _sec = second;
            return true;
        };
        int hour() const {return _hour;};
        int minute() const {return _min;};
        int second() const {return _sec;};
        void printTime()
        {
            std::cout << _hour << ":" << _min << ":" << _sec << std::endl;
        }
    private:
        int _hour = 0, _min = 0, _sec = 0;
        // You can add any function if needed
};

//The format for input/output is hh:mm:ss
std::ostream& operator<<(std::ostream& out, const MyClock& c);
std::istream& operator>>(std::istream& in, MyClock& c);

#endif