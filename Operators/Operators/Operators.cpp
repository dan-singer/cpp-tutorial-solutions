// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

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
		return *this;
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
namespace Subscript {
	struct StudentGrade {
		std::string name;
		char grade;
	};
	class GradeMap {
	private:
		std::vector<StudentGrade> m_map;
	public:
		GradeMap()
		{

		}
		char& operator[] (const std::string& key);
	};
	char& GradeMap::operator[] (const std::string& key) 
	{
		for (auto &student : m_map) {
			if (student.name == key) {
				return student.grade;
			}
		}
		StudentGrade newStudent{ key };
		m_map.push_back(newStudent);
		return m_map.back().grade;
	}

	void main() 
	{
		GradeMap grades;
		grades["Joe"] = 'A';
		grades["Frank"] = 'B';
		std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
		std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
	}
}
namespace Parenthesis {
	class Mystring {
	private:
		std::string m_string;
	public:
		Mystring(std::string string) : m_string{ string }
		{

		}

		std::string operator() (int index, int length)
		{
			assert(index + length < m_string.length());
			std::string substring;
			for (int i = index; i < index + length; ++i) {
				substring += m_string[i];
			}
			return substring;
		}
	};

	void main() 
	{
		Mystring string("Hello, world!");
		std::cout << string(7, 5); // start at index 7 and return 5 characters
	}
}
namespace Quiz {
	namespace One
	{
		/*Question 1.
		a) friend
		b) member
		c) friend
		d) member
		*/
	}
	namespace Two {
		class Average {
		private:
			std::int32_t m_sum;
			std::int8_t m_length;
		public:
			Average() : m_sum(0), m_length(0)
			{
			}
			double getAvg() const
			{
				return (static_cast<double>(m_sum) / m_length);
			}
			Average& operator+=(int num);
		};
		Average& Average::operator+=(int num)
		{
			m_sum += num;
			++m_length;
			return *this;
		}
		std::ostream& operator<<(std::ostream &out, const Average &avg)
		{
			out << avg.getAvg();
			return out;
		}
		void main() 
		{
			Average avg;

			avg += 4;
			std::cout << avg << '\n'; // 4 / 1 = 4

			avg += 8;
			std::cout << avg << '\n'; // (4 + 8) / 2 = 6

			avg += 24;
			std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

			avg += -10;
			std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

			(avg += 6) += 10; // 2 calls chained together
			std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

			Average copy = avg;
			std::cout << copy << '\n';
		}
	}
	namespace Three {

		class IntArray {
		private:
			int *m_arr;
			int m_length;
		public:
			IntArray(int length) : m_length(length)
			{
				assert(length > 0);
				m_arr = new int[m_length];
			}
			IntArray(const IntArray& other) : m_length(other.m_length)
			{
				m_arr = new int[m_length];
				for (int i = 0; i < m_length; ++i)
					m_arr[i] = other.m_arr[i];
			}

			~IntArray() 
			{
				delete[] m_arr;
			}

			int& operator[] (int index);
			IntArray& operator= (const IntArray& other);
			friend std::ostream& operator<< (std::ostream &out, const IntArray& iArr);

		};

		int& IntArray::operator[] (int index)
		{
			assert(index >= 0 && index < m_length);
			return m_arr[index];
		}

		IntArray& IntArray::operator= (const IntArray& other)
		{
			if (this == &other)
				return *this;
			delete[] m_arr;

			m_length = other.m_length;
			m_arr = new int[m_length];
			for (int i = 0; i < m_length; ++i)
				m_arr[i] = other.m_arr[i];
		}

		std::ostream& operator<< (std::ostream &out, const IntArray& iArr)
		{
			for (int i = 0; i < iArr.m_length; ++i)
			{
				out << iArr.m_arr[i];
				if (i < iArr.m_length - 1)
					out << " ";
			}
			return out;
		}

		IntArray fillArray()
		{
			IntArray a(5);
			a[0] = 5;
			a[1] = 8;
			a[2] = 2;
			a[3] = 3;
			a[4] = 6;
			return a;
		}

		void main()
		{
			IntArray a = fillArray();
			std::cout << a << '\n';

			IntArray b(1);
			a = a;
			b = a;

			std::cout << b << '\n';
		}
	}
	namespace Four {
		class FixedPoint2 {
		private:
			std::int16_t m_whole;
			std::int8_t m_fraction;
			bool m_isNegative;
		public:
			FixedPoint2(std::int16_t whole = 0, std::int8_t fraction = 0)
			{
				m_isNegative = whole < 0 || fraction < 0;
				m_whole = fabs(whole);
				m_fraction = fabs(fraction);
			}
			FixedPoint2(double d)
			{
				m_isNegative = d < 0;
				m_whole = fabs(static_cast<std::int16_t>(d));
				m_fraction = round((fabs(d) - m_whole) * 100);
			}

			operator double() const;
			FixedPoint2 operator- () const;
			friend std::ostream& operator<< (std::ostream& out, const FixedPoint2& fp2);
			friend std::istream& operator>> (std::istream& in, FixedPoint2& fp2);
			friend bool operator== (const FixedPoint2& left, const FixedPoint2& right);
			friend FixedPoint2 operator+ (const FixedPoint2& left, const FixedPoint2& right);
		};

		FixedPoint2::operator double() const
		{
			double d = m_whole + (m_fraction / 100.0);
			if (m_isNegative)
				d *= -1;
			return d;
		}
		FixedPoint2 FixedPoint2::operator- () const
		{
			FixedPoint2 neg = *this;
			neg.m_isNegative = !m_isNegative;
			return neg;
		}
		std::ostream& operator<< (std::ostream& out, const FixedPoint2& fp2) 
		{
			out << static_cast<double>(fp2);
			return out;
		}
		std::istream& operator>> (std::istream& in, FixedPoint2& fp2)
		{
			double temp;
			in >> temp;
			fp2 = temp; //Implicitly uses double constructor
			return in;
		}
		bool operator== (const FixedPoint2& left, const FixedPoint2& right)
		{
			return left.m_isNegative == right.m_isNegative && left.m_fraction == right.m_fraction && left.m_whole == right.m_whole;
		}
		FixedPoint2 operator+ (const FixedPoint2& left, const FixedPoint2& right)
		{
			return static_cast<double>(left) + static_cast<double>(right); //Implicitly uses double constructor
		}

		void testAddition()
		{
			// h/t to reader Sharjeel Safdar for this function
			std::cout << std::boolalpha;
			std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
			std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
			std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
			std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
			std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
			std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
			std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
			std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
		}

		void main()
		{
			testAddition();

			FixedPoint2 a(-0.48);
			std::cout << a << '\n';

			std::cout << -a << '\n';

			std::cout << "Enter a number: "; // enter 5.678
			std::cin >> a;

			std::cout << "You entered: " << a << '\n';
		}
	}
}
int main()
{
	//Arithmetic::main();
	//Arithmetic::mainA();
	//Unary::main();
	//Comparison::One::main();
	//Comparison::Two::main();
	//Subscript::main();
	//Parenthesis::main();
	//Quiz::Two::main();
	//Quiz::Three::main();
	Quiz::Four::main();
    return 0;
}

