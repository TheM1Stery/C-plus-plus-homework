#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <windows.h>

char *replace(char *str, size_t buffer_size,  const char *word, const char *replace)
{
    char *temp = strstr(str, word);
    if (temp == nullptr)
    {
        return nullptr;
    }
    // char* temp2 = strchr(str, word[strlen(word) - 1]);
    // int first_index = (temp != nullptr ? temp - str: -1);
    // int last_index = (temp != nullptr && temp2 != nullptr ? temp2 - temp: -1);
    // memmove(&str[first_index], &str[last_index + 1], strlen(&str[first_index]));
    memmove(temp, temp + strlen(word), strlen(temp)); // убирает заменяемое слово из строки
    memmove(temp + strlen(replace), temp, strlen(temp)); // увеличивает строку так, чтобы новое слово поместилось
    memcpy(temp, replace, strlen(replace)); // вставка слова
    return str;
}
int main()
{
    char *str = new char[40];
    std::cin.getline(str, 40);
    const char *word = "world";
    const char *user_word = "vivalavida";
    while(replace(str, 40, word, user_word));
    std::cout << str << std::endl;
    
}