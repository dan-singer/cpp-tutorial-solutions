// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Pair.h"

int main()
{
	{
		std::cout << "Q1:\n";
		Pair1<int> p1(5, 8);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair1<double> p2(2.3, 4.5);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}

	{
		std::cout << "\nQ2:\n";

		Pair<int, double> p1(5, 6.7);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair<double, int> p2(2.3, 4);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}
	{
		std::cout << "\nQ3:\n";

		StringValuePair<int> svp("Hello", 5);
		std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	}
	std::cout << "\n";

	return 0;
}

