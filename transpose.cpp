#include <iostream>
#include <string.h>

template <typename T> void init(T**& matrix, const size_t row, const size_t column)
{
    T** matr = new T * [row];
    for (int i = 0; i < row; i++)
    {
        matr[i] = new T[column];
    }
    delete[] matrix;
    matrix = matr;
}



/*

        a^T (j,i) = a(i,j)
        1 2 3
        4 5 6
        7 8 9
          |
          | TRANSPOSE
          |
        1 4 7
        2 5 8
        3 6 9


*/
void transpose(int**& matrix, size_t& row, size_t& column)
{
    int** transpose_m = nullptr;
    // меняем местами кол-во столбцов и строк
    init(transpose_m, column, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            transpose_m[j][i] = matrix[i][j];
        }
    }
    delete[] matrix;
    matrix = transpose_m;
    std::swap(row, column);


}

void print_m(int** matrix, const size_t row, const size_t column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}
void fill(int** matrix, const size_t row, const size_t column)
{
    int c = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = c++;
        }
    }

}


void push_back(char**& arr, char* str,const size_t buffer_size,  size_t& size)
{
    char** new_arr = new char* [size + 1];
    char* str2 = new char[buffer_size];
    strcpy_s(str2, buffer_size, str);
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

void print_s(char** matrix, const size_t size)
{
    for (int i = 0; i < size  * 2; i += 2)
    {
        std::cout << matrix[i] << " " << matrix[i + 1] << "\n";
    }
    std::cout << "\n";
}


// если s_type будет true, то будет поиск по именам, если false то по номерам
char** search(char** matrix, char* search,const size_t buffer_size, const size_t size, bool s_type,size_t &map_size)
{
    size_t size_ap = 0;
    char** store = new char* [size];
    int div = s_type ? 0 : 1;
    int other = s_type ? 1 : -1;
    char* str = new char[buffer_size];
    int length = strlen(search);
    strcpy_s(str,length + 1, search);
    char* temp;
    bool check = false;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == div)
        {
            temp = strstr(matrix[i], str);
            if (temp != nullptr)
            {
                push_back(store, matrix[i], buffer_size, size_ap);
                push_back(store, matrix[i + other], buffer_size, size_ap);
                map_size++;
                check = true;
            }
        }
    }
    if (check == false)
    {
        return nullptr;
    }
    return store;
}



// type = true - name; type = false - number
void change_info(char** matrix,const size_t size, char* change, int element_pos, bool type)
{
    
    int index = (element_pos - 1) * 2;
    if (index == -1 || element_pos > size)
    {
        return;
    }
    for (int i = 0; change[i] != '\0'; i++)
    {
        if (!isdigit(change[i]) && !type)
        {
            return;
        }
        if (!isalpha(change[i]) && type)
        {
            return;
        }
    }
    int check_type = type ? 0 : 1;
    matrix[index + check_type] = change;
    
}


int main()
{
    //int** matrix = nullptr;
    // size_t row = 4;
    // size_t column = 3;
    // init(matrix, row, column);
    // fill(matrix, row, column);
    // print_m(matrix, row, column);
    // transpose(matrix, row, column);
    // print_m(matrix, row, column);
    char** idk = new char* [3];
    init(idk, 6, 1000); // четные номера будут хранить имена, а нечетные номера. фиговая имитация std::vector<std::pair> или std::unordered_map
    strcpy_s(idk[0], 12, "Ren Amamiya");
    strcpy_s(idk[1], 7, "765432");
    strcpy_s(idk[2], 16, "Geralt of Rivia");
    strcpy_s(idk[3], 7, "321001");
    strcpy_s(idk[4], 14, "Ezio Auditore");
    strcpy_s(idk[5], 7, "727272");
    char* str = new char[100];
    strcpy_s(str, 13, "Kazuma Kiryu");
    print_s(idk, 3);
    // size_t map_size = 0;
    // char** search_res = search(idk, str,1000, 6, false, map_size);
    // if (search_res!= nullptr)
    // {
    //     print_s(search_res, map_size);
    // }
    change_info(idk, 6, str, 1, false);
    print_s(idk, 3);
    std::cout << "hello world";

}