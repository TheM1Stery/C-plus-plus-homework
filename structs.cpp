#include <iostream>
#include <cmath>
struct Rectangle
{
	double x_axis_pos;
	double y_axis_pos;
	double length;
	double width;
};

struct Axis
{
	double x;
	double y;
};

struct Fraction
{
	int numerator;
	int denominator;
};


int greatest_common_divider(int a, int b)
{
	int remainder;
	while (a % b > 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return b;
	
}


void print_fraction(Fraction* fraction)
{
	// 12 / 5 - 2 
	int number{};
	if (fraction->numerator > fraction->denominator)
	{
		number = fraction->numerator % fraction->denominator;
	}
	int c = greatest_common_divider(fraction->numerator, fraction->denominator);
	if (number > 0)
	{
		std::cout << number;
	}

	std::cout << fraction->numerator << " \\ " << fraction->denominator;
	
}











double distance(Axis* coord, Axis* coord2)
{
	return sqrt(pow((coord2->x - coord->x), 2) + pow((coord2->y - coord->y), 2));
}



void move_axis(Rectangle* rectangle, double x, double y)
{
	rectangle->x_axis_pos = x;
	rectangle->y_axis_pos = y;
}

void change_measurements(Rectangle* rectangle, double length, double width)
{
	rectangle->length = length;
	rectangle->width = width;
}


void print_rectangle(Rectangle* rectangle)
{
	for (int i = 0; i < rectangle->width; i++)
	{
		for (int j = 0; j < rectangle->length; i++)
		{

		}
	}
}



int main()
{
	
}
