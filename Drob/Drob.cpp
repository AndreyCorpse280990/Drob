#include <iostream>

class Fraction
{
	int numerator; // Числитель
	int denominator; // Знаменатель
public:
	Fraction();
	~Fraction();
};

Fraction::Fraction()
{
}

Fraction::~Fraction()
{
}
int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Hello World!\n";
}

