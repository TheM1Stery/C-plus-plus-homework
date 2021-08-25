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

int find_count_of_sentences(char* str)
{
	const char *punctuation_marks = ".?!";
	int count = 0;
	char* temp = strpbrk(str, punctuation_marks);
	if (temp == nullptr)
	{
		return 0;
	}
	while (temp != nullptr)
	{
		temp = strpbrk(temp + 1, punctuation_marks);
		if (temp != nullptr && (temp[1] == '?' || temp[1] == '!' || temp[1] == '.'))
		{
			temp = strpbrk(temp + 1, punctuation_marks);
			count++;
			continue;
		}
		count++;
	}
	return count;
}

int find_count_of_punc(char* str)
{
	int i = 0;
	size_t length = strlen(str);
	const char* punc = ".,";
	char* temp = strpbrk(str, punc);
	while(temp != nullptr)
	{
		temp = strpbrk(temp + 1, punc);
		i++;
	}
	return i;
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

char* strrevsentence(char* str)
{
	char punc_marks[] = ".?!";
	char* temp = strpbrk(str, punc_marks);
	int index = temp - str;
	for (int i = 0; i < (index + 1) / 2; i++)
	{
		std::swap(str[i], str[index - i - 1]);
	}
	char* temp2 = strpbrk(temp + 1, punc_marks);
	while(temp2 != nullptr)
	{
		temp++;
		while(true)
		{
			if (temp[0] != ' ')
			{
				break;
			}
			temp++;
		}
		index = temp2 - temp;
		for (int i = 0; i < index  / 2; i++)
		{
			std::swap(temp[i], temp[index - i - 1]);
		}
		temp = strpbrk(temp + 1, punc_marks);
		temp2 = strpbrk(temp2 + 1, punc_marks);
	}
	return str;

}

int main()
{
	// char* str = new char[40];
	// char* str2 = new char[20];
	// std::cin.getline(str, 40);
	// std::cin.getline(str2, 20);
	// std::cout << find_count_of_words(str, str2);
	// delete[] str;
	// delete[] str2;
	// char str[] = "Hello, my name is seymur. I'm a programmer! I hope, i will be a good one. Maybe?";
	// std::cout << find_count_of_punc(str) << std::endl;
	// std::cout << find_count_of_sentences(str) << std::endl;
	// std::cout << strrev(str) << std::endl; // or mystrrev(str)
	// std::cout << strrevsentence(str) << std::endl;
}