#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <string>

class Vehicle{
    public:
        Vehicle();
        Vehicle(std::string _brand, int _year, int _mileage);
        void printVehicle();
        void updateMileage(int newMileage);
        void updateMileage(int currentMileage, int distance);
        
    private:
        std::string brand;
        int year;
        int mileage;
};

#endif