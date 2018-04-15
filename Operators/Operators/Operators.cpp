// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace Arithmetic {
	class Fraction 
	{
	private:
		int m_numerator;
		int m_denominator;
		static int gcd(int a, int b) {
			return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
		}
	public:
		Fraction(int numerator=0, int denominator=1) : m_numerator{ numerator }, m_denominator{ denominator }
		{
		}
		void print() {
			std::cout << m_numerator << "/" << m_denominator << "\n";
		}
		Fraction& reduce() {
			int divisor = gcd(m_numerator, m_denominator);
			m_numerator /= divisor;
			m_denominator /= divisor;
			return *this;
		}
		friend Fraction operator*(const Fraction& frac, int multiplier);
		friend Fraction operator*(int multiplier, const Fraction& frac);
		friend Fraction operator*(const Fraction& f1, const Fraction& f2);

		friend std::ostream& operator<<(std::ostream &out, const Fraction &frac);
		friend std::istream& operator>>(std::istream &in, Fraction &frac);

	};
	Fraction operator*(const Fraction& frac, int multiplier)
	{
		return Fraction(frac.m_numerator * multiplier, frac.m_denominator).reduce();
	}
	Fraction operator*(int multiplier, const Fraction& frac)
	{
		return frac * multiplier;
	}
	Fraction operator*(const Fraction& f1, const Fraction& f2) 
	{
		return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator).reduce();
	}

	std::ostream& operator<<(std::ostream &out, const Fraction &frac) 
	{
		out << frac.m_numerator << "/" << frac.m_denominator;
		return out;
	}
	std::istream& operator>>(std::istream &in, Fraction &frac)
	{
		in >> frac.m_numerator;
		in >> frac.m_denominator;
		return in;
	}
	void main() 
	{
		Fraction f1(2, 5);
		f1.print();

		Fraction f2(3, 8);
		f2.print();

		Fraction f3 = f1 * f2;
		f3.print();

		Fraction f4 = f1 * 2;
		f4.print();
		 
		Fraction f5 = 2 * f2;
		f5.print();

		Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
		f6.print();
	}
	void mainA() {
		Fraction f1;
		std::cout << "Enter fraction 1: ";
		std::cin >> f1;

		Fraction f2;
		std::cout << "Enter fraction 2: ";
		std::cin >> f2;

		std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
	}
}

int main()
{
	//Arithmetic::main();
	Arithmetic::mainA();
    return 0;
}

