#include <iostream>
#include <string.h>
#include <random>
#include <ctime>

std::default_random_engine engine(time(nullptr));
std::uniform_int_distribution<int> range(0, 9);


void initiliaze(int**& matrix, const size_t size, const size_t size2)
{
    int** matrix2 = new int* [size];

    for (int i = 0; i < size; i++)
    {
        matrix2[i] = new int[size];
    }
    delete[] matrix;
    matrix = matrix2;
}

void free_mem(int** matrix, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void push_back(int**& matrix, int* row, size_t& size)
{
    size++;
    int** r_arr = new int*[size];
    int* new_arr = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        new_arr[i] = row[i];
    }
    r_arr[size - 1] = new_arr;
    for (int i = 0; i < size - 1; i++)
    {
        r_arr[i] = matrix[i];
    }
    delete[] matrix;
    matrix = r_arr;
}


void push_front(int**& matrix, int* row, size_t& size)
{
    size++;
    int** r_arr = new int*[size];
    int* new_arr = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        new_arr[i] = row[i];
    }
    r_arr[0] = new_arr;
    for (int i = 1; i < size; i++)
    {
        r_arr[i] = matrix[i - 1];
    }
    delete[] matrix;
    matrix = r_arr;
}

void insert(int**& arr, int pos, int* insertable, size_t& size)
{
    int** new_arr = new int*[size + 1];
    int* insert_arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        insert_arr[i] = insertable[i];
    }
    int c = 0;
    for (int i = 0; i < size + 1; i++)
    {
        if (i != pos)
        {
            new_arr[c] = arr[i];
            c++;
        }
        else
        {
            new_arr[c++] = insert_arr;
            if (i < size)
            {
                new_arr[c++] = arr[i];
            }

        }
    }
    size++;
    delete[] arr;
    arr = new_arr;
}


void pop(int**& arr, int pos, size_t& size)
{
    if (pos >= size || pos < 0)
    {
        return;
    }
    int** new_arr = new int*[size - 1];
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (i != pos)
        {
            new_arr[c] = arr[i];
            c++;
        }

    }
    size--;
    delete[] arr;
    arr = new_arr;
}


void fill_random(int** arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = range(engine);
        }
    }
}
void print_matrix(int** arr, size_t size, size_t size2)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}







int main()
{
    size_t size = 3;
    int** matrix = nullptr;
    initiliaze(matrix, size, size);
    fill_random(matrix, size);
    int* arr = new int[3]{ 1,2,3 };
    print_matrix(matrix, size, 3);
    push_back(matrix, arr, size);
    push_front(matrix, arr, size);
    insert(matrix, 1, arr, size);
    print_matrix(matrix, size, 3);
    pop(matrix, 1, size);
    print_matrix(matrix, size, 3);
    free_mem(matrix, size);
}
