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
		Fraction(int numerator, int denominator) : m_numerator{ numerator }, m_denominator{ denominator }
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
}

int main()
{
	Arithmetic::main();
    return 0;
}

