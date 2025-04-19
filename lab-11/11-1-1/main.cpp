#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "shapes.h"
using namespace std;

int main()
{
    MyClock my_clock;
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
            while (getline(iss, token, ':'))
            {
                time.push_back(stoi(token));
            }

            my_clock.SetTime(time[0], time[1], time[2]);
            my_clock.printTime();
        }
        if (command == "tick")
        {
            int time_delta;
            if (iss>>time_delta)
            {
                my_clock.Tick(time_delta);
                my_clock.printTime();
            }
            else 
            {
                my_clock.Tick();
                my_clock.printTime();
            }
        }
        if (command == "quit")
        {
            return 0;
        }
        
    }
    return 0;
}