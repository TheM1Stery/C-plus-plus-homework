#include <iostream>
#include <string.h>


char* pop(char* str, int number)
{

	const size_t length = strlen(str);
	if (number > length || number == 0)
	{
		return str;
	}
	int index = number - 1;
	char* temp = &str[index];
	int i = 0;
	while (temp[i] != '\0')
	{
		temp[i] = temp[i + 1];
		i++;
	}
	// memmove(temp, temp + 1, length); // memcpy(temp, temp + 1, length)
	return str;
}

char* remove_all(char* str, char symbol)
{
	const size_t length = strlen(str);
	char* temp = strchr(str, symbol);
	if (temp == nullptr)
	{
		return str;
	}
	while (temp != nullptr)
	{
		int i = 0;
		while (temp[i] != '\0')
		{
			temp[i] = temp[i + 1];
			i++;
		}
		temp = strchr(temp, symbol);
	}
	return str;
}

char* insert(char*& str, int pos, char symbol, size_t buffer_size)
{
	size_t length = strlen(str);
	if (buffer_size < length + 1)
	{
		char* new_str = (char*) operator new[](length + 100);
		memcpy(new_str, str, length + 1);
		delete[] str;
		str = new_str;
	}
	char* temp = &str[pos];
	int move = temp[0];
	temp[0] = symbol;
	int i = 1;
	while (i < length + 1)
	{
		int move_next = move;
		move = temp[i];
		temp[i] = move_next;
		i++;
	}
	return str;
}

char* replace_chr(char* str, char symbol, char rep_symbol)
{
	char* temp = strchr(str, symbol);
	if (temp == nullptr)
	{
		return str;
	}
	while (temp != nullptr)
	{
		temp[0] = rep_symbol;
		temp = strchr(temp, symbol);
	}
	return str;
}

int cchar(char* str, char fsymbol)
{
	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == fsymbol)
		{
			count++;
		}
		i++;
	}
	return count;
}

void find_count_of_chars(char* str, int& c_letter, int& c_numbers, int& c_other)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			c_letter++;
		}
		else if ((str[i] >= '0' && str[i] <= '9'))
		{
			c_numbers++;
		}
		else
		{
			c_other++;
		}
		i++;
	}
}


int main()
{
    // char* str = new char[100];
    // std::cin.getline(str, 100);
    // std::cout << pop(str, 1) << "\n";
    // std::cout << remove_all(str, 'h') << "\n";
    // std::cout << insert(str, 0, 'h', 100) << "\n";
    // std::cout << replace_chr(str, ' ', 'h') << "\n";
    // std::cout << cchar(str, 'h') << "\n";
    // int alpha = 0, num = 0, other = 0;
    // find_count_of_chars(str, alpha, num, other);
    // std::cout << "Count of letters: " << alpha << "\nCount of number characters: " << num << "\nOther: " << other << std::endl;
    // delete[] str;
}