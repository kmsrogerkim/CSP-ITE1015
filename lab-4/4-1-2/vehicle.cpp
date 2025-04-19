#include <iostream>
#include "vehicle.h"

Vehicle::Vehicle()
{
    brand = "Undefined";
    year = 0;
    mileage = 0;
}

Vehicle::Vehicle(std::string _brand, int _year, int _mileage)
{
    brand = _brand;
    year = _year;
    mileage = _mileage;
}

void Vehicle::printVehicle()
{
    std::cout << "Brand: " << brand << ", Year: " << year << ", Mileage: " << mileage << std::endl;
}

void Vehicle::updateMileage(int newMileage)
{
    mileage = newMileage;
}

void Vehicle::updateMileage(int currentMileage, int distance)
{
    if (mileage == currentMileage)
    {
        mileage += distance;
    }
    else
    {
        throw std::invalid_argument("");
    }
}