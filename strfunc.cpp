#include <iostream>
#include <string.h>


void initiliaze(char**& str, const size_t size, const size_t buffer_size)
{
    char** str2 = new char* [size];

    for (int i = 0; i < size; i++)
    {
        str2[i] = new char[buffer_size];
    }
    delete[] str;
    str = str2;
}

void free_mem(char** arr, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}


void push_back(char**& arr, char* str, size_t& size)
{
    char** new_arr = new char* [size + 1];
    int i;
    for (i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[i] = str;
    delete[] arr;
    arr = new_arr;
    size++;
}


void push_front(char**& arr, char* str, size_t& size)
{
    char** new_arr = new char* [size + 1];
    int i = 0;
    new_arr[i++] = str;
    for (; i < size + 1; i++)
    {
        new_arr[i] = arr[i - 1];
    }
    delete[] arr;
    arr = new_arr;
    size++;
}

void insert(char**& arr, int pos, char* insertable, size_t& size)
{
    char** new_arr = new char* [size + 1];
    initiliaze(new_arr, size + 1, 100);
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    char** temp = &arr[pos];
    char* move = temp[0];
    temp[0] = insertable;
    int i = 1;
    for (; i < size; i++)
    {
        char* move_next = move;
        move = temp[i];
        temp[i] = move_next;
    }
    size++;
}


void print_arr(char** arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}





int main()
{
    size_t size = 3;
    char** arr = new char* [size];
    initiliaze(arr, size, 100);
    char* str = new char[100];
    char* str2 = new char[100];
    char* str3 = new char[100];
    strcpy_s(str, 14, "Disco Odyssey");
    strcpy_s(str2, 15, "!!!!!!!!!!!!!!");
    strcpy_s(str3, 19, "AAAAAAAAAAAAAAAAAA");
    strcpy_s(arr[0], 13, "The Magician");
    strcpy_s(arr[1], 6, "Hello");
    strcpy_s(arr[2], 6, "Hello");
    print_arr(arr, size);
    push_back(arr, str, size);
    push_front(arr, str2, size);
    insert(arr, 1, str3, size);
    print_arr(arr, size);
    free_mem(arr, size);

}