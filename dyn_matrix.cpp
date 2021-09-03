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


// size1 and size2 - dimensions of the first matrix
// size3 and size4 - dimensions of the second matrix
int** multiply_matrices(int** matrix, int** matrix2, const size_t size1, const size_t size2, const size_t size3, const size_t size4)
{
	// Если число столбцов у первой матрицы не равна числу строк второй, то эти матрицы не умножаются
	if (size2 != size3)
	{
		return nullptr;
	}
	int** mult_matrix = nullptr;
	// Есть такое правило, что результат произведения матрицы это число строк первой матрицы x число столбцов второй матрицы
	initiliaze(mult_matrix, size1, size4);
	double dot_product = 0;
	for (int i = 0; i < size1; i++)
	{
		
		for (int j = 0; j < size4; j++)
		{
			dot_product = 0;
			for (int k = 0; k < size2; k++)
			{
				dot_product += (matrix[i][k] * matrix2[k][j]);
			}
			mult_matrix[i][j] = dot_product;
		}
	}
	return mult_matrix;
}

void delete_pointers(int**& matrix, size_t size)
{
	if (matrix == nullptr)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
}


int main()
{
	int** matrix = nullptr;
	// size_t size = 3;
	/*initiliaze(matrix, size, 10);
	fill(matrix, size, 10);
	print(matrix, size, 10);
	delete_zero_str(matrix, size, 10);
	print(matrix, size, 10);*/
	int** matrix2 = nullptr;
	size_t size1 = 2, size2 = 4, size3 = 2, size4 = 2;
	initiliaze(matrix,size1, size2);
	initiliaze(matrix2, size3, size4);
	fill(matrix, size1, size2);
	fill(matrix2, size3, size4);
	print(matrix, size1, size2);
	print(matrix2, size3, size4);
	// int** matrix3 = sum(matrix, matrix2, 3, 3);
	// print(matrix3, size, 3);
	int** matrix3 = multiply_matrices(matrix, matrix2, size1, size2, size3, size4);
	if (matrix3 != nullptr)
	{
		print(matrix3, size1,size4);
	}
	if (matrix3 == nullptr)
	{
		std::cout << "These matrices cannot be multiplied\n";
	}
	delete_pointers(matrix, size1);
	delete_pointers(matrix2, size3);
	delete_pointers(matrix3, size1);
}

