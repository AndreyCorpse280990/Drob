#include <iostream>

class Fraction
{
	int numerator; // Числитель
	int denominator; // Знаменатель
public:

	// Функция для печати дроби
	void print() const
	{
		std::cout << numerator << "/" << denominator;
	}

	// Конструктор класса для инициализации дроби
	Fraction(int num, int denom);

	// Функция для сложения дробей
	Fraction add(Fraction other) const;


    // Функция для вычитания дробей
    Fraction subtract(Fraction other) const;


    // Функция для умножения дробей
    Fraction multiply(Fraction other) const;

    // Функция для деления дробей
	Fraction divide(Fraction other) const;

    // Перегрузка оператора сложения
    Fraction operator+(const Fraction& other) const
    {
        return add(other);
    }

    // Перегрузка оператора вычитания
    Fraction operator-(const Fraction& other) const
    {
        return subtract(other);
    }

    // перегрузка оператора умножения
    Fraction operator*(const Fraction& other) const
    {
        return multiply(other);
    }

    // Перегрузка оператора деления
    Fraction operator/(const Fraction& other) const
    {
        return divide(other);
    }

};



int main()
{
    setlocale(LC_ALL, "rus");

    int num1, denom1, num2, denom2;

    std::cout << "Введите числитель первой дроби: ";
    std::cin >> num1;

    std::cout << "Введите знаменатель первой дроби: ";
    std::cin >> denom1;

    std::cout << "Введите числитель второй дроби: ";
    std::cin >> num2;

    std::cout << "Введите знаменатель второй дроби: ";
    std::cin >> denom2;

    Fraction frac1(num1, denom1);
    Fraction frac2(num2, denom2);

    Fraction resultAdd = frac1.add(frac2);
    Fraction resultMultiply = frac1.multiply(frac2);
    Fraction resultSubtract = frac1.subtract(frac2);
    Fraction resultDivide = frac1.divide(frac2);

    std::cout << "Сложение: ";
    resultAdd.print();
    std::cout << std::endl;

    std::cout << "Умножение: ";
    resultMultiply.print();
    std::cout << std::endl;

    std::cout << "Вычитание: ";
    resultSubtract.print();
    std::cout << std::endl;

    std::cout << "Деление: ";
    resultDivide.print();
    std::cout << std::endl;

    return 0;
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom)
{
	if (denominator == 0)
	{
		std::cout << "Знаменатель не может быть нулем." << std::endl;
		std::exit(1);
	}
}

Fraction Fraction::add(Fraction other) const
{
	int newNumerator = numerator * other.denominator + other.numerator * denominator;
	int newDenominator = denominator * other.denominator;
	return Fraction(newNumerator, newDenominator);
}


Fraction Fraction::subtract(Fraction other) const
{
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}


Fraction Fraction::multiply(Fraction other) const
{
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);

}


Fraction Fraction::divide(Fraction other) const
{

    int newNumerator = numerator * other.denominator;
    int newDenominator = denominator * other.numerator;
    return Fraction(newNumerator, newDenominator);
}