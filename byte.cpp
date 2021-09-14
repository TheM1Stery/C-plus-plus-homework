#include <iostream>


union USSR
{
	long num;
	char buffer[10];
	
};




int main()
{
	USSR ussr{ 10 };
	strcpy_s(ussr.buffer, 10, "123456789");
	char* addr = (char*) &ussr;
	for (int i = 0; i < sizeof(ussr); i++)
	{
		std::cout << *addr++;
	}
	
	
}
