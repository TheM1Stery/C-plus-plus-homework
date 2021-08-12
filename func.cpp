#include <iostream>


template <typename T>void reverse(T* arr, const int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		std::swap(*(arr + i), *(arr + size - i - 1));
	}
		
}

template <typename T> T* remove(T* arr, int remove,  int* const size)
{
	T* new_arr = new int[*size - 1];
	int c = 0;
	int index = -1;
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] == remove)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		return arr;
	}
	for (int i = 0; i < *size; i++)
	{
		if (i != index)
		{
			new_arr[c] = arr[i];
			c++;
		}

	}
	(*size)--;
	return new_arr;
}

template <typename T> T* shift(T* arr, int* const size)
{
	T* new_arr = new int[*size - 1];
	int c = 0;
	for (int i = 0; i < *size; i++)
	{
		if (i != 0)
		{
			new_arr[c] = arr[i];
			c++;
		}

	}
	(*size)--;
	return new_arr;
}


template <typename T> T* pop(T* arr, int* const size)
{
	T* new_arr = new int[*size - 1];
	int c = 0;
	for (int i = 0; i < *size; i++)
	{
		if (i != *size - 1)
		{
			new_arr[c] = arr[i];
			c++;
		}

	}
	(*size)--;
	return new_arr;
}


template <typename T> T* pop(T* arr, int index, int* const size)
{
	
	T* new_arr = new int[*size - 1];
	if (index >= *size || index < 0)
	{
		return arr;
	}
	int c = 0;
	for (int i = 0; i < *size; i++)
	{
		if (i != index)
		{
			new_arr[c] = arr[i];
			c++;
		}
		
	}
	(*size)--;
	return new_arr;
}

template <typename T> T* append(T* arr, int append, int* const size)
{
	(*size)++;
	T* r_arr = new int[*size];
	r_arr[*size - 1] = append;
	for (int i = 0; i < *size - 1; i++)
	{
		r_arr[i] = arr[i];
	}
	return r_arr;
}

template <typename T> T* prepend(T* arr,int prepend, int* const size)
{
	(*size)++;
	T* r_arr = new int[*size];
	r_arr[0] = prepend;
	for (int i = 1; i < *size; i++)
	{
		r_arr[i] = arr[i - 1];
	}
	return r_arr;
}

template <typename T> T* extend(T arr[], T arr2[], int* const size1, const int size2)
{
	
	T* r_arr = new int[*size1 + size2];
	int c = 0;
	for (int i = 0; i < *size1 + size2; i++)
	{
		if (i < *size1)
		{
			r_arr[i] = arr[i];
		}
		if (i >= *size1)
		{
			r_arr[i] = arr2[c++];
		}
	}
	*size1 = *size1 + size2;
	return r_arr;
}


template <typename T> void print_array(T arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	int* arr = new int[10] { 1,2,3,4,5,6,7,8,9,10 };
	//int* arr2 = new int[6] { 11,12,13,14,15, 16};
	int size = 10;
	//int size2 = 6;
	arr = remove(arr, 3, &size);
	print_array(arr, size);
}