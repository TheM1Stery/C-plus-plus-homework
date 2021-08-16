#include <iostream>
#include <string.h>
#include <cmath>




int mystrcmp(const char * str1, const char * str2)
{
    int i = 0;
    while(true)
    {
        if (str1[i] > str2[i])return 1;
        if (str1[i] < str2[i]) return -1;
        if (str1[i] == '\0') return 0;
        i++;
        
    }
}



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
    int length = 0;
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
    char* str = new char[100]{ 0 };
    if (number == 0)
    {
        str[0] = '0';
        return str;
    }
    int digits = 0;
    int temp = number;

    while (temp != 0)
    {
        temp /= 10;
        digits++;
    }

    int j = 0;
    if (number < 0)
    {
        str[j] = '-';
        j++;
        number *= -1;
    }
    for (int i = digits; i > 0; i--)
    {
        long long temp = pow(10, i - 1);
        int num = (number / temp) % 10;
        str[j] = 48 + num;
        j++;
    }
    //str[j] = '\0';
    return str;
}

char* Uppercase(char* str1)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] -= 32;
        }
        i++;
    }
    return str1;
}

char* Lowercase(char* str1)
{
    int i = 0;
    while (str1[i] != 0)
    {
        if (str1[i] >= 'A' && str1[i] <= 'Z')
        {
            str1[i] += 32;
        }
        i++;
    }
    return str1;
}

char* mystrrev(char* str1)
{
   int length = strlen(str1);
   for (int i = 0; i < length / 2; i++)
   {
       std::swap(str1[i], str1[length - i - 1]);
   }
   return str1;
}

int main()
{
    // char* str = new char[30];
    // std::cin.getline(str, 30);
    // std::cout << StringToNumber(number);
    //std::cout << NumberToString(0) << "\n";
    //std::cout << Uppercase(str) << "\n";
    //std::cout << Lowercase(str) << "\n";
    // std::cout << mystrrev(str) << "\n";
    std::cout << mystrcmp("AAAAAA", "B");

}
