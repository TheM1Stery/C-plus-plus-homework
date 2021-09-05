#include <iostream>

struct Washing_Machine
{
	char* firm;
	int color;
	double width;
	double length;
	double height;
	double power;
	double speed;
	double temperature;
	~Washing_Machine()
	{
		delete[] firm;
	}

	
};

struct Iron
{
	char* firm;
	char* model;
	int color;
	double min_temp;
	double max_temp;
	bool steam;
	double power;
	~Iron()
	{
		delete[] firm;
		delete[] model;
	}
};

struct Boiler
{
	char* firm;
	int color;
	double power;
	double volume;
	double temperature;
	~Boiler()
	{
		delete[] firm;
	}
};


struct Animal
{
	char* name;
	char* type;
	char* nickname;

};


void create_washing_machine(Washing_Machine*& wash, const char* firm, int color, double width, double length,
	double height, double power, double speed)
{
	wash->firm = new char[100];
	strcpy(wash->firm, firm);
	wash->color = color;
	wash->width = width;
	wash->length = length;
	wash->height = height;
	wash->power = power;
	wash->speed = speed;
}

void create_animal(Animal*& animal, const char* name, const char* type, const char* nickname)
{
	animal->name = new char[100];
	strcpy(animal->name, name);
	animal->type = new char[100];
	strcpy(animal->type, type);
	animal ->
}

int main()
{
	Washing_Machine* wash_machine = new Washing_Machine;
	create_washing_machine(wash_machine, "Samsung", 0xFFFFFF, 100, 100, 100, 100, 100);
	
}
