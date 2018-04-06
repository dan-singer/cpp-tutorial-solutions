// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace ClassesAndClassMembers {

	class IntPair {
	public:
		int m_1;
		int m_2;

		void set(int v1, int v2) {
			m_1 = v1;
			m_2 = v2;
		}

		void print() {
			std::cout << "Pair(" << m_1 << ", " << m_2 << ")\n";
		}
	};

	void main()
	{
		IntPair p1;
		p1.set(1, 1); // set p1 values to (1, 1)

		IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

		p1.print();
		p2.print();
	}
}

int main()
{
	ClassesAndClassMembers::main();
}

