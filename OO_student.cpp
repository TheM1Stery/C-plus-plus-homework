#include <iostream>



class Student
{
	char* name;
	int day, month, year;
	char* number;
	char* city_S;
	char* school;
	char* city_s;
	char* country_s;
	char* group;
public:
	Student()
	{
		size_t size = 100;
		name = new char[size];
		number = new char[size];
		city_S = new char[size];
		school = new char[size];
		city_s = new char[size];
		country_s = new char[size];
		group = new char[size];
	}

	Student(char* name, int day, int month, int year,  char* number, char* city_S, char* school, char* city_s, char* country_s, char* group, const size_t size = 100)
	{
		name = new char[size];
		number = new char[size];
		city_S = new char[size];
		school = new char[size];
		city_s = new char[size];
		country_s = new char[size];
		group = new char[size];
	}

	void set_name(const char* name)
	{
		if (name == nullptr)
		{
			return;
		}
		delete[] this->name;
		size_t length = strlen(name) + 1;
		strcpy_s(this->name, length, name);
	}

	const char* get_name(const char* name)
	{
		if (name != nullptr)
		{
			return name;

		}
	}

	void set_number(const char* number)
	{
		if (number != nullptr)
		{
			return;
		}
		delete[] this->number;
		size_t length = strlen(number) + 1;
		strcpy_s(this->number, length, number);


	}





	~Student()
	{
		delete[] name;
		delete[] number;
		delete[] city_S;
		delete[] school;
		delete[] city_s;
		delete[] country_s;
		delete[] group;
	}

	
	

};





int main()
{

}
