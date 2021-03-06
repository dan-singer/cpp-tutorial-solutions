// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdexcept>

class Fraction {
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator, int denominator)
	{
		if (denominator == 0) {
			throw std::runtime_error("Zero denominator is not allowed");
		}
		m_numerator = numerator;
		m_denominator = denominator;
	}
};

int main()
{
	int num, denom;
	std::cout << "Enter a numerator: ";
	std::cin >> num;
	std::cout << "Enter a denominator: ";
	std::cin >> denom;
	try {
		Fraction frac(num, denom);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}