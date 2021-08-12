#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

int find_count_of_words(char* str, const char* word)
{
	int i = 0;
	
	while (str != nullptr)
	{
		str = strstr(str, word);
		char* temp_str = str;
		const int size = strlen(word);
		if (temp_str++ != nullptr)
		{
			for (int j = 0; j < size; j++)
			{
				str++;
			}
		}
		else
		{
			break;
		}
		
		i++;
	}
	return i;
}

int main()
{
	char* str = new char[40];
	char* str2 = new char[20];
	std::cin.getline(str, 40);
	std::cin.getline(str2, 20);
	std::cout << find_count_of_words(str, str2);
}