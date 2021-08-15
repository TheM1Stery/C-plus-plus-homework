#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>

std::default_random_engine eng(time(nullptr));
std::uniform_int_distribution<int> range(0, 15);

enum MENU
{
    MAX = 1,
    MIN,
    AVG,
    RST = 1337
};

template <typename T, typename R> R fmax(T* arr, const size_t size)
{
    T max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}


template <typename T, typename R> R fmin(T* arr, const size_t size)
{
    T min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

template <typename T, typename R> R faverage(T* arr, const size_t size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}



template <typename T, typename R>
using func_ptr = R(*)(T*, const size_t);

template <typename T, typename R> R Action(T* arr, const size_t size, func_ptr<T, R> ptr)
{
    return ptr(arr, size);
}

template <typename T> void fill_array(T* arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = range(eng);
    }
}

template <typename T> void print_array(T* arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    func_ptr<int, double> ptr_to_func[3] = { fmax, fmin, faverage };
    size_t size = 10;
    int* arr = new int[size];
    int choice;
    fill_array(arr, size);
    do
    {
        print_array(arr, size);
        std::cout << "Enter 1337 to reset the array\n\n";
        std::cout << "1. Find the max element of the array\n2. Find the min element of the array\n3. Find the average of the array\n0. Exit\n";
        std::cout << "> ";
        std::cin >> choice;
        switch (choice)
        {
            case 0:
                break;
            case MAX:
                system("cls");
                std::cout << "Max element of the array: " << Action<int, double>(arr, size, ptr_to_func[choice - 1]) << "\n";
                break;
            case MIN:
                system("cls");
                std::cout << "Min element of the array: " << Action<int, double>(arr, size, ptr_to_func[choice - 1]) << "\n";
                break;
            case AVG:
                system("cls");
                std::cout<< "Average of the array: " << Action<int, double>(arr, size, ptr_to_func[choice - 1]) << "\n";
                break;
            case RST:
                system("cls");
                fill_array(arr, size);
                break;
            default:
                
                std::cout << "Wrong input. Try again!" << "\n";

        }
        std::cout << "\n\n";



    } while (choice != 0);
    delete[] arr;

}
