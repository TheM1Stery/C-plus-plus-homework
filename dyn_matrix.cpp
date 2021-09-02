#include <iostream>
#include <string.h>
#include <random>
#include <ctime>


std::default_random_engine engine(time(nullptr));
std::uniform_int_distribution<int> range(0, 9);

void initiliaze(int**& str, const size_t size, const size_t buffer_size)
{
	int** str2 = new int* [size];

	for (int i = 0; i < size; i++)
	{
		str2[i] = new int[buffer_size];
	}
	delete[] str;
	str = str2;
}

void fill(int** matrix, const size_t size, const size_t str_len)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < str_len; j++)
		{
			matrix[i][j] = range(engine);
		}
	}
	
}
void print(int** str, const size_t size, const size_t size2)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			std::cout << "\t" << str[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void delete_zero_str(int**& matrix, size_t& size, const size_t size2)
{
	size_t temp_size = size;
	for (int i = 0; i < size; i++)
	{
		bool check = false;
		for (int j = 0; j < size2; j++)
		{
			if (matrix[i][j] == 0)
			{
				check = true;
			}
		}
		if (check)
		{
			matrix[i] = nullptr;
			temp_size--;
		}
	}
	int** str2 = new int* [temp_size];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (matrix[i] == nullptr)
		{
			continue;
		}
		str2[j] = matrix[i];
		j++;
	}
	delete[] matrix;
	matrix = str2;
	size = temp_size;

}

int** sum(int** matrix, int** matrix2, const int size1, const int size2)
{
	int** sum_arr = nullptr;
	initiliaze(sum_arr, size1, size2);
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			sum_arr[i][j] = matrix[i][j] + matrix2[i][j];
		}
	}
	return sum_arr;
}

int** multiply_matrices(int** matrix, int** matrix2, const int size1, const int size2, const int size3, const int size4)
{
	if (size2 != size3)
	{
		return nullptr;
	}
	int** mult_matrix = nullptr;
	initiliaze(mult_matrix, size1, size4);
	
}

int main()
{
	int** matrix = nullptr;
	size_t size = 3;
	/*initiliaze(matrix, size, 10);
	fill(matrix, size, 10);
	print(matrix, size, 10);
	delete_zero_str(matrix, size, 10);
	print(matrix, size, 10);*/
	int** matrix2 = nullptr;
	initiliaze(matrix, size, 3);
	initiliaze(matrix2, size, 3);
	fill(matrix, size, 3);
	fill(matrix2, size, 3);
	print(matrix, size, 3);
	print(matrix2, size, 3);
	int** matrix3 = sum(matrix, matrix2, 3, 3);
	print(matrix3, size, 3);
	
}

