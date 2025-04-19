#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "shapes.h"
using namespace std;

int main()
{
    MyCalendar my_clock;
    string initial_input;

    while(1)
    {
        getline(cin, initial_input);
        istringstream iss(initial_input);

        string command;
        iss >> command;
        if (command == "set")
        {
            vector<int> time;
            string token;
            while (getline(iss, token, '.'))
            {
                time.push_back(stoi(token));
            }

            my_clock.SetDate(time[0], time[1], time[2]);
            my_clock.printDate();
        }
        if (command == "next")
        {
            string offset;
            iss >> offset;
            if (offset == "day")
            {
                my_clock.NextDay(1);
            }
            else
            {
                int day_delta = stoi(offset);
                my_clock.NextDay(day_delta);
            }
            my_clock.printDate();
        }
        if (command == "quit")
        {
            return 0;
        }
        
    }
    return 0;
}