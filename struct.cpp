#include <iostream>
#include <string.h>

struct Washing_Machine
{
	char *firm;
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
	char *firm;
	char *model;
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
	char *firm;
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
	char *name;
	char *type;
	char *nickname;
	~Animal()
	{
		delete[] name;
		delete[] type;
		delete[] nickname;
	}
};

void create_boiler(Boiler *&boiler, const char *firm, int color, double power, double temperature, const size_t buffer_size)
{
	boiler->firm = new char[buffer_size];
	strcpy_s(boiler->firm, buffer_size, firm);
	boiler->color = color;
	boiler->power = power;
	boiler->temperature = temperature;
}

void creare_iron(Iron *&iron, const char *firm, const char *model, int color, double min_temp, double max_temp, bool steam, double power, const size_t buffer_size)
{
	iron->firm = new char[buffer_size];
	strcpy_s(iron->firm, buffer_size, firm);
	iron->model = new char[buffer_size];
	strcpy_s(iron->model, buffer_size, model);
	iron->color = color;
	iron->min_temp = min_temp;
	iron->max_temp = max_temp;
	iron->steam = steam;
	iron->power = power;
}

void create_washing_machine(Washing_Machine *&wash, const char *firm, int color, double width, double length,
	double height, double power, double speed, const size_t buffer_size)
{
	wash->firm = new char[buffer_size];
	strcpy_s(wash->firm, buffer_size, firm);
	wash->color = color;
	wash->width = width;
	wash->length = length;
	wash->height = height;
	wash->power = power;
	wash->speed = speed;
}

void create_animal(Animal *&animal, const char *name, const char *type, const char *nickname, const size_t buffer_size)
{
	animal->name = new char[buffer_size];
	strcpy_s(animal->name, buffer_size, name);
	animal->type = new char[buffer_size];
	strcpy_s(animal->type, buffer_size, type);
	animal->nickname = new char[buffer_size];
	strcpy_s(animal->nickname, buffer_size, nickname);
}

void animal_info(Animal *animal) // можно было бы перезагрузить оператор <<, чтобы при cout обьекта самого выводилась инфа :D
{
	std::cout << "Name: " << animal->name << "\n";
	std::cout << "Class: " << animal->type << "\n";
	std::cout << "Nickname: " << animal->nickname << "\n";
}

void animal_voice(Animal *animal, const char *voice)
{
	std::cout << voice << std::endl;
}

// с перегрузкой :D
//std::ostream& operator << (std::ostream& stream, Animal* animal)
//{
//	stream << "Name: " << animal->name << "\n";
//	stream << "Class: " << animal->type << "\n";
//	stream << "Nickname: " << animal->nickname << "\n";
//	return stream;
//}

int main()
{
	// Washing_Machine* washing_machine = new Washing_Machine();
	// create_washing_machine(washing_machine, "Beko", 0xFFFFFF, 100, 100, 100, 100, 100, 100);
	// std::cout << washing_machine->firm;
	// delete washing_machine;

	// Iron* iron = new Iron();
	// creare_iron(iron, "Beko", "1", 0xFFFFFF, 0, 100, true, 100, 100);
	// std::cout << iron->firm;
	// delete iron;

	// Boiler* boiler = new Boiler();
	// create_boiler(boiler, "Beko", 0xFFFFFF, 100, 100, 100);
	// std::cout << boiler->firm;
	// delete boiler;

	Animal *animal = new Animal();
	create_animal(animal, "Cat", "Mammal", "Mickey", 100);
	//std::cout << animal;
	animal_info(animal);
	animal_voice(animal, "Meow");
	delete animal;
}
