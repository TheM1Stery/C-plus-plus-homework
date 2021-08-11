#include <iostream>
#include <string.h>
#include <cmath>

auto StringToNumber(char* str)
{
    // long long number = 0;
    // int j = strlen(str) - 1;
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     long long temp = std::pow(10, j--);
    //     int num = (str[i] + 2) - 50; // 0 - 48, (48 + 2) - 50 = 0; 1 - 49, (49 + 2) - 50 = 1;
    //     number += (temp * num);
    // }
    // return number;
    long long number = 0;
    long long ten = 1;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == '-')
        {
            number *= -1;
            break;
        }
        int num = (str[i] + 2) - 50; // 0 - 48, (48 + 2) - 50 = 0; 1 - 49, (49 + 2) - 50 = 1;
        number += (ten * num);
        ten *= 10;
    }
    return number;
}

char* NumberToString(long long number)
{
    char* str = new char[100];
    if (number == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    int digits = 0;
    int temp = number;
    
    while(temp != 0)
    {
        temp /= 10;
        digits++;
    }
    
    int j = 0;
    if (number < 0)
    {
        str[j++] = '-';
        number *= -1;
    }
    for (int i = digits; i > 0; i--)
    {
        long long temp = pow(10, i - 1);
        int num = (number / temp) % 10;
        str[j++] = 48 + num;
    }
    return str;
}


int main()
{
    // char* number = new char[30];
    // std::cin.getline(number, 30);
    // std::cout << StringToNumber(number);
    std::cout << NumberToString(12);
}