#include <iostream>

struct Car
{
    double length;
    double clearence;
    double engine_volume;
    double power;
    double wheel_diameter;
    int color;
    // true - automatic, false - manual
    bool transmission;
};



void create_car(Car*& car, double length, double clearence, double engine_volume, double power, double wheel_diameter, bool transmission)
{
    car->length = length;
    car->clearence = clearence;
    car->engine_volume = engine_volume;
    car->power = power;
    car->wheel_diameter = wheel_diameter;
    car->transmission = transmission;
}




// std::ostream& operator << (std::ostream& stream, Car* car)
// {
//     stream << "Car's length: " << car->length << "\n";
//     stream << "Car's clearence: " << car->clearence << "\n";
//     stream << "Car's engine volume: " << car->engine_volume << "\n";
//     stream << "Car's power: " << car->power << "\n";
//     stream << "Car's wheel diameter: " << car->wheel_diameter << "\n";
//     stream << "Car's transmission: " << (car->transmission ? "Automatic" : "Manual");
//     return stream;
// }


int main()
{
    Car* car = new Car();
    create_car(car, 100, 100, 100, 100, 100, false);
    //std::cout << car;
}