#include <iostream>


template <typename T> size_t find(T* arr, T item, const int size)
{

	for (int i = 0; i < size; i++)
	{
		if (item == arr[i])
		{
			return i;
		}
	}
	return -1;
}


template <typename T> void remove(T*& arr, T remove,  size_t& size)
{
	
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == remove)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		return;
	}
	T* new_arr = new int[size - 1];
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			new_arr[c] = arr[i];
			c++;
		}

	}
	size--;
	delete[] arr;
	arr = new_arr;
}


template <typename T> void insert(T*& arr, T index,T insert, size_t& size)
{
	T* new_arr = new T[size + 1];
	int c = 0;
	for (int i = 0; i < size + 1; i++)
	{
		if (i != index)
		{
			new_arr[c] = arr[i];
			c++;
		}else
		{
			new_arr[c++] = insert;
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

template <typename T> void shift(T*& arr, size_t& size)
{
	T* new_arr = new int[size - 1];
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
		{
			new_arr[c] = arr[i];
			c++;
		}

	}
	size--;
	delete[] arr;
	arr = new_arr;
}


template <typename T> void pop(T*& arr, size_t& size)
{
	T* new_arr = new int[size - 1];
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
		{
			new_arr[c] = arr[i];
			c++;
		}

	}
	size--;
	delete[] arr;
	arr = new_arr;
}


template <typename T> void pop(T*& arr, int index, size_t& size)
{
	if (index >= size || index < 0)
	{
		return;
	}
	T* new_arr = new int[size - 1];
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			new_arr[c] = arr[i];
			c++;
		}
		
	}
	size--;
	delete[] arr;
	arr = new_arr;
}

template <typename T> void append(T*& arr, T append, size_t& size)
{
	size++;
	T* r_arr = new int[size];
	r_arr[size - 1] = append;
	for (int i = 0; i < size - 1; i++)
	{
		r_arr[i] = arr[i];
	}
	delete[] arr;
	arr = r_arr;
}

template <typename T> void prepend(T*& arr,T prepend, size_t& size)
{
	size++;
	T* r_arr = new int[size];
	r_arr[0] = prepend;
	for (int i = 1; i < size; i++)
	{
		r_arr[i] = arr[i - 1];
	}
	delete[] arr;
	arr = r_arr;
}

template <typename T> T* extend(T*& arr, T* arr2, size_t& size1, const size_t size2)
{
	
	T* r_arr = new int[size1 + size2];
	int c = 0;
	for (int i = 0; i < size1 + size2; i++)
	{
		if (i < size1)
		{
			r_arr[i] = arr[i];
		}
		if (i >= size1)
		{
			r_arr[i] = arr2[c++];
		}
	}
	size1 += size2;
	delete[] arr;
	arr = r_arr;
}

template <typename T>void reverse(T*& arr, size_t& size)
{
	for (int i = 0; i < size / 2; i++)
	{
		std::swap(*(arr + i), *(arr + size - i - 1));
	}
		
}

template <typename T> void print_array(T* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	size_t size = 10;
	int* arr = new int[size] { 1,2,3,4,5,6,7,8,9,10 };
	// int* arr2 = new int[6] { 11,12,13,14,15, 16};
	print_array(arr, size);
	append(arr, 10, size);
	print_array(arr, size);

}