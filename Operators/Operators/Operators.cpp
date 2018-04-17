// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
namespace Unary {
	class Point
	{
	private:
		double m_x, m_y, m_z;

	public:
		Point(double x = 0.0, double y = 0.0, double z = 0.0) :
			m_x(x), m_y(y), m_z(z)
		{
		}

		// Convert a Point into its negative equivalent
		Point operator- () const;

		Point operator+ () const;

		// Return true if the point is set at the origin
		bool operator! () const;

		friend std::ostream& operator<< (std::ostream &out, const Point &pt);


		double getX() { return m_x; }
		double getY() { return m_y; }
		double getZ() { return m_z; }
	};

	// Convert a Point into its negative equivalent 
	Point Point::operator- () const
	{
		return Point(-m_x, -m_y, -m_z);
	}
	
	Point Point::operator+ () const 
	{
		return Point(*this);
	}

	// Return true if the point is set at the origin, false otherwise
	bool Point::operator! () const
	{
		return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
	}

	std::ostream& operator<< (std::ostream &out, const Point &pt) 
	{
		out << "Point(" << pt.m_x << ", " << pt.m_y << ", " << pt.m_z << ")";
		return out;
	}


	int main()
	{
		Point point; // use default constructor to set to (0.0, 0.0, 0.0)

		if (!point)
			std::cout << "point is set at the origin.\n";
		else
			std::cout << "point is not set at the origin.\n";

		std::cout << "+point is " << +point << "\n";

		return 0;
	}
}

namespace Comparison {
	namespace One {
		class Cents
		{
		private:
			int m_cents;

		public:
			Cents(int cents) { m_cents = cents; }

			friend bool operator> (const Cents &c1, const Cents &c2);
			friend bool operator<= (const Cents &c1, const Cents &c2);

			friend bool operator< (const Cents &c1, const Cents &c2);
			friend bool operator>= (const Cents &c1, const Cents &c2);
		};

		bool operator> (const Cents &c1, const Cents &c2)
		{
			return c1.m_cents > c2.m_cents;
		}

		bool operator>= (const Cents &c1, const Cents &c2)
		{
			return c1.m_cents >= c2.m_cents;
		}

		bool operator< (const Cents &c1, const Cents &c2)
		{
			return !(c1 >= c2);
		}

		bool operator<= (const Cents &c1, const Cents &c2)
		{
			return !(c1 > c2);
		}

		void main()
		{
			Cents dime(10);
			Cents nickle(5);

			if (nickle > dime)
				std::cout << "a nickle is greater than a dime.\n";
			if (nickle >= dime)
				std::cout << "a nickle is greater than or equal to a dime.\n";
			if (nickle < dime)
				std::cout << "a dime is greater than a nickle.\n";
			if (nickle <= dime)
				std::cout << "a dime is greater than or equal to a nickle.\n";
		}
	}
	namespace Two {
		class Car
		{
		private:
			std::string m_make;
			std::string m_model;

		public:
			Car(std::string make, std::string model)
				: m_make(make), m_model(model)
			{
			}

			friend bool operator== (const Car &c1, const Car &c2);
			friend bool operator!= (const Car &c1, const Car &c2);
			friend bool operator< (const Car &c1, const Car &c2);

			friend std::ostream& operator<< (std::ostream& out, const Car &car);

		};

		bool operator== (const Car &c1, const Car &c2)
		{
			return (c1.m_make == c2.m_make &&
				c1.m_model == c2.m_model);
		}

		bool operator!= (const Car &c1, const Car &c2)
		{
			return !(c1 == c2);
		}

		bool operator< (const Car &c1, const Car &c2)
		{
			return (c1.m_make + c1.m_model) < (c2.m_make + c2.m_model);
		}

		std::ostream& operator<< (std::ostream& out, const Car &car)
		{
			out << "(" << car.m_make << ", " << car.m_model << ")";
			return out;
		}

		void main() {
			std::vector<Car> v;
			v.push_back(Car("Toyota", "Corolla"));
			v.push_back(Car("Honda", "Accord"));
			v.push_back(Car("Toyota", "Camry"));
			v.push_back(Car("Honda", "Civic"));

			std::sort(v.begin(), v.end()); // requires an overloaded operator<

			for (auto &car : v)
				std::cout << car << '\n'; // requires an overloaded operator<<
		}
	}
}

int main()
{
	//Arithmetic::main();
	//Arithmetic::mainA();
	//Unary::main();
	//Comparison::One::main();
	Comparison::Two::main();
    return 0;
}

