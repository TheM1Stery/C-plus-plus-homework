#include <iostream>

using ushort = unsigned short;
#define SIZE 5


struct Student
{
	char* surname;
	char* group;
	int grades[SIZE];
	~Student()
	{
		delete[] surname;
		delete[] group;
	}
};


struct Date
{
	ushort day;
	ushort month;
	ushort year;
	
};


struct Person
{
	char* name;
	char* surname;
	int age;
	Date date_of_birth;
	~Person()
	{
		delete[] name;
		delete[] surname;
	}
};



template <typename T> void push_back(T**& arr, T* obj, size_t& size)
{
	T** new_arr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[size] = obj;
	delete[] arr;
	arr = new_arr;
	size++;
}

template <typename T> void pop_back(T**& arr,size_t& size)
{
	T** new_arr = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	size--;
}

template<typename T> void erase(T**& arr, int pos, size_t& size)
{
	T** new_arr = new int[size - 1];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == pos)
		{
			continue;
		}
		new_arr[index] = arr;
		index++;
	}
	delete[] arr;
	arr = new_arr;
	size--;
}


enum class STUDENT_TYPE
{
	A,
	B
};

double get_grade_average(Student* student)
{
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += student->grades[i];
	}
	return (double) sum / (SIZE * 5) * 100;
}

void type_list(Student** arr, const size_t size, STUDENT_TYPE type)
{
	 
}



int main()
{

}
