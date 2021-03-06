// MoveSemantics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
using namespace std;

namespace UniquePtr {

	class Fraction
	{
	private:
		int m_numerator = 0;
		int m_denominator = 1;

	public:
		Fraction(int numerator = 0, int denominator = 1) :
			m_numerator(numerator), m_denominator(denominator)
		{
		}

		friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
		{
			out << f1.m_numerator << "/" << f1.m_denominator;
			return out;
		}
	};

	void printFraction(const Fraction* const ptr)
	{
		if (ptr)
			std::cout << *ptr;
	}

	int main()
	{
		unique_ptr<Fraction> ptr = make_unique<Fraction>(3, 5);

		printFraction(ptr.get());

		return 0;
	}
}

namespace SharedWeak {
	class Resource
	{
	public:
		std::weak_ptr<Resource> m_ptr; // initially created empty

		Resource() { std::cout << "Resource acquired\n"; }
		~Resource() { std::cout << "Resource destroyed\n"; }
	};

	int main()
	{
		auto ptr1 = std::make_shared<Resource>();

		ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

		return 0;
	}
}

namespace Quiz {
	namespace A {
		class Resource
		{
		public:
			Resource() { std::cout << "Resource acquired\n"; }
			~Resource() { std::cout << "Resource destroyed\n"; }
		};

		int main()
		{
			std::shared_ptr<Resource> ptr1 = make_shared<Resource>();
			std::shared_ptr<Resource> ptr2(ptr1);

			return 0;
		}
	}
}

int main()
{
	UniquePtr::main();
	cout << endl;
	SharedWeak::main();
	cout << endl;
	Quiz::A::main();
	return 0;
}