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
	int mix{};
	int numerator;
	int denominator;
};


int greatest_common_divider(int a, int b)
{
	int remainder;
	a = abs(a);
	b = abs(b);
	while (a % b > 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return b;
	
}

int least_common_divisor(int a, int b)
{
	return abs(a * b) / greatest_common_divider(a, b);
}




void print_fraction(Fraction* fraction)
{
	if (fraction->mix != 0)
	{
		std::cout << fraction->mix << " " << fraction->numerator << "|" << fraction->denominator;
	}
	if (fraction->mix == 0)
	{
		std::cout << fraction->numerator << "|" << fraction->denominator;
	}
	
}


void reduce(Fraction* fraction)
{
	int c = greatest_common_divider(fraction->numerator, fraction->denominator);
	if (c > 1)
	{
		fraction->numerator /= c;
		fraction->denominator /= c;
	}
}

void convert_to_mix(Fraction* fraction)
{
	// 12 / 5 - 2 
	int number{};
	if (fraction->numerator > fraction->denominator)
	{
		number = fraction->numerator % fraction->denominator;
		fraction->numerator -= (fraction->denominator * number);
	}
	fraction->mix = number;
}

Fraction* sum_fractions(Fraction* fraction1, Fraction* fraction2) // было бы прикольно оверлоднуть оператор +, чтобы он делал то что я щас делаю в функции
{
	Fraction* fraction_result = new Fraction();
	int lcm = least_common_divisor(fraction1->denominator, fraction2->denominator);
	int a = fraction1->numerator;
	int b = fraction2->numerator;
	if (fraction1->denominator != fraction2->denominator)
	{
		a = (lcm / fraction1->denominator) * fraction1->numerator;
		b = (lcm / fraction2->denominator) * fraction2->numerator;
	}
	fraction_result->numerator = a + b;
	fraction_result->denominator = lcm;
	reduce(fraction_result);
	convert_to_mix(fraction_result);
	return fraction_result;
}

Fraction* subtract_fractions(Fraction* fraction1, Fraction* fraction2)
{
	Fraction* fraction_result = new Fraction();
	int lcm = least_common_divisor(fraction1->denominator, fraction2->denominator);
	int a = fraction1->numerator;
	int b = fraction2->numerator;
	if (fraction1->denominator != fraction2->denominator)
	{
		a = (lcm / fraction1->denominator) * fraction1->numerator;
		b = (lcm / fraction2->denominator) * fraction2->numerator;
	}
	fraction_result->numerator = a - b;
	fraction_result->denominator = lcm;
	reduce(fraction_result);
	convert_to_mix(fraction_result);
	return fraction_result;
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
	Fraction* fraction = new Fraction();
	Fraction* fraction2 = new Fraction();
	fraction->numerator = 5;
	fraction->denominator = 8;
	fraction2->numerator = 10;
	fraction2->denominator = 25;
	Fraction* fraction3 = sum_fractions(fraction, fraction2);
	print_fraction(fraction3);
	
}
