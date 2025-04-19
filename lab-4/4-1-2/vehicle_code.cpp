#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "vehicle.h"
using namespace std;

int main()
{
    Vehicle** vehicle_arr = new Vehicle* [10];
    int num_vehicles = 0;

    while (num_vehicles < 10)
    {
        string name;
        cin >> name;
        if (name == "0") break;

        int age, numstripes;
        cin >> age >> numstripes;

        Vehicle* new_Vehicle = new Vehicle(name, age, numstripes);
        vehicle_arr[num_vehicles] = new_Vehicle;
        num_vehicles += 1;
    }

    while (1)
    {
        char y_or_n;
        cout << "Update?" << endl;
        cin >> y_or_n;
        if (y_or_n == 'n') return 0;

        string line_input;
        getline(cin, line_input); 

        istringstream stream(line_input);
        vector<string> inputs;  
        string input;

        while (stream >> input) {
            inputs.push_back(input);
        }

        cout << inputs.size() << endl;

        int index = int(atoi(inputs[0].c_str()));
        int b = int(atoi(inputs[1].c_str()));

        if (inputs.size() == 3)
        {
            int c = int(atoi(inputs[2].c_str()));
            vehicle_arr[index]->updateMileage(b, c);
        }
        else vehicle_arr[index]->updateMileage(b);

        for (int i=0; i<num_vehicles; i++)
        {
            vehicle_arr[i]->printVehicle();
        }
    }
    return 0;
}
