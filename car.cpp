#include <iostream>
#include <string.h>


enum class ENG_TRANSMISS
{
	MANUAL,
	AUTOMATIC,
	CVT
};



struct Car
{
	char* name;
	double length;
	double clearence;
	double engine_volume;
	double power;
	double wheel_diameter;
	int color;
	// true - automatic, false - manual
	ENG_TRANSMISS transmission;
	~Car()
	{
		delete[] name;
	}
};


void create_object_arr(Car**& cars, const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cars[i] = new Car;
	}
}


void delete_objects(Car**& cars, const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		delete cars[i];
	}
}

void push_back(Car**& cars, Car*& car, size_t& size)
{
	Car** cars2 = new Car * [size + 1];
	for (int i = 0; i < size; i++)
	{
		cars2[i] = cars[i];
	}
	cars2[size] = car;
	delete[] cars;
	cars = cars2;
	size++;
}



Car** search(Car** car_arr, const char* search, const size_t size, size_t& res_size)
{
	size_t srch_size = 0;
	Car** search_result = new Car * [srch_size];
	char* temp;
	for (int i = 0; i < size; i++)
	{
		temp = strstr(car_arr[i]->name, search);
		if (temp != nullptr)
		{
			push_back(search_result, car_arr[i], srch_size);
			res_size++;
		}
	}
	
	return search_result;
}

void create_car(Car*& car, const char* name, double length, double clearence, double engine_volume, double power, double wheel_diameter, ENG_TRANSMISS transmission, const size_t buffer_size = 1000)
{
	car->name = new char[buffer_size];
	strcpy_s(car->name, buffer_size, name);
	car->length = length;
	car->clearence = clearence;
	car->engine_volume = engine_volume;
	car->power = power;
	car->wheel_diameter = wheel_diameter;
	car->transmission = transmission;
}


std::ostream& operator << (std::ostream& stream, Car* car)
{
	stream << "Car's name: " << car->name << "\n";
	stream << "Car's length: " << car->length << "\n";
	stream << "Car's clearence: " << car->clearence << "\n";
	stream << "Car's engine volume: " << car->engine_volume << "\n";
	stream << "Car's power: " << car->power << "\n";
	stream << "Car's wheel diameter: " << car->wheel_diameter << "\n";
	stream << "Car's transmission: ";
	switch (car->transmission)
	{
		case ENG_TRANSMISS::MANUAL:
		{
			stream << "Manual" << std::endl;
			break;
		}
		case ENG_TRANSMISS::AUTOMATIC:
		{
			stream << "Automatic" << std::endl;
			break;
		}
		case ENG_TRANSMISS::CVT:
		{
			stream << "CVT" << std::endl;
			break;
		}
		default:
		{
			stream << "Undefined" << std::endl;
			break;
		}
	}
	return stream;
}


void print_objects(Car** cars, const size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << cars[i] << std::endl;
	}
}

int main()
{
	size_t size = 3;
	Car** cars = new Car * [size];
	create_object_arr(cars, size);

	create_car(cars[0], "Mercedes", 100, 100, 100, 100, 100, ENG_TRANSMISS::AUTOMATIC);
	create_car(cars[1], "BMW", 100, 100, 100, 100, 100, ENG_TRANSMISS::CVT);
	create_car(cars[2], "Mercedes", 150, 100, 100, 100, 100, ENG_TRANSMISS::MANUAL);
	//print_objects(cars, size);
	size_t res_size = 0;
	Car** search_result = search(cars, "Me", size, res_size);
	print_objects(search_result, res_size);
	delete_objects(cars, size);
	delete[] cars;
	delete[] search_result;
}