#include <iostream>
#include <random>
#include <ctime>

std::default_random_engine engine(time(nullptr));
std::uniform_int_distribution<int> range(1, 30);



template<typename T> T* create_dynamic_memory(size_t size)
{
    T* arr = new int[size];
    return arr;
}

template <typename T> void fill_array(T* arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = range(engine);
    }

}

template <typename T> void print_array(T* arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
template <typename T> void delete_arr(T*& arr)
{
    delete[] arr;
}

template <typename T> void push_back(T*& arr, T item, size_t& size)
{
    T* copied_arr = new int[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        copied_arr[i] = arr[i];
        if (i == size)
        {
            copied_arr[i] = item;
        }
    }
    delete[] arr;
    arr = copied_arr;
    size++;
}

template <typename T> void insert(T*& arr, T item, T insert_index, size_t& size)
{
    T* copied_arr = new int[size + 1];
    bool check = false;
    for (int i = 0; i < size; i++)
    {
        if (i == insert_index)
        {
            copied_arr[i] = item;
            
            check = true;

        }
        if (!check)
        {
            copied_arr[i] = arr[i];
        }
        if (check)
        {
            copied_arr[i + 1] = arr[i];
        }
    }
    delete[] arr;
    arr = copied_arr;
    size++;
}

template <typename T> void erase(T*& arr, T index, size_t& size)
{
    T* new_arr = new int[size - 1];
	if (index >= size || index < 0)
	{
		return;
	}
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			new_arr[c] = arr[i];
			c++;
		}
		
	}
    delete[] arr;
	arr = new_arr;
    size--;
}


template <typename T> void prime_number_del(T*& arr, size_t& size)
{
    for (int i = 0; i < size; i++)
    {
        bool check = true;
        for (int j = arr[i] - 1; j >= 2; j--)
        {
            if (arr[i] % j == 0)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            erase(arr, i, size);
            i--;
        }

    }
}



template <typename T> void neg_pos_null(T arr[], const size_t size)
{
    size_t size1 = 0;
    size_t size2 = 0;
    size_t size3 = 0;
    T* neg_arr = create_dynamic_memory<T>(size1);
    T* pos_arr = create_dynamic_memory<T>(size2);
    T* zero_arr = create_dynamic_memory<T>(size3);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            push_back(zero_arr, arr[i], size3);
        }
        if (arr[i] > 0)
        {
           push_back(pos_arr, arr[i], size2);
        }
        if (arr[i] < 0)
        {
            push_back(neg_arr, arr[i], size1);
        }
    }
    std::cout << "Array that contains negative numbers: ";
    print_array(neg_arr, size1);
    std::cout << "Array that contains positive numbers: ";
    print_array(pos_arr, size2);
    std::cout << "Array that contains negative numbers: ";
    print_array(zero_arr, size3);
    delete_arr(neg_arr);
    delete_arr(pos_arr);
    delete_arr(zero_arr);
}


int main()
{
    size_t size = 6;
    // int* arr = create_dynamic_memory<int>(size);
    // int* arr = new int[size] {1,2,3,5,7,4};
    int arr[size] = {0,0, 1,2, -3,-5};
    // fill_array(arr, size);
    print_array(arr, size);
    // prime_number_del(arr, size);
    // print_array(arr, size);
    neg_pos_null(arr, size);
    // delete[] arr;
}