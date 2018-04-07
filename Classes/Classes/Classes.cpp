// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>

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


namespace AccessSpecifiers {
	namespace Two {
		class Point3d {
		//Classes are private by default!
			double m_x;
			double m_y;
			double m_z;
		public:
			void setValues(double x, double y, double z) {
				m_x = x;
				m_y = y;
				m_z = z;
			}
			void print() {
				std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
			}
			bool isEqual(const Point3d &other) {
				return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
			}
		};

		void main()
		{
			Point3d point;
			point.setValues(1.0, 2.0, 3.0);
			point.print();

			Point3d point1;
			point1.setValues(1.0, 2.0, 3.0);

			Point3d point2;
			point2.setValues(1.0, 2.0, 3.0);

			if (point1.isEqual(point2))
				std::cout << "point1 and point2 are equal\n";
			else
				std::cout << "point1 and point2 are not equal\n";

			Point3d point3;
			point3.setValues(3.0, 4.0, 5.0);

			if (point1.isEqual(point3))
				std::cout << "point1 and point3 are equal\n";
			else
				std::cout << "point1 and point3 are not equal\n";
		}
	}
	namespace Three {
		class Stack {
			int m_data[10];
			int m_next;
		public:
			void reset() {
				m_next = 0;
				for (int i = 0; i < 10; ++i)
					m_data[i] = 0;
			}
			bool push(int val) {
				if (m_next >= 10)
					return false;
				m_data[m_next++] = val;
				return true;
			}
			int pop() {
				assert(m_next > 0 && "There are no elements left on the stack");
				return m_data[--m_next];
			}
			void print() {
				std::cout << "( ";
				for (int i = 0; i < m_next; ++i)
					std::cout << m_data[i] << " ";
				std::cout << ")\n";
			}
		};
		void main()
		{
			Stack stack;
			stack.reset();

			stack.print();

			stack.push(5);
			stack.push(3);
			stack.push(8);
			stack.print();

			stack.pop();
			stack.print();

			stack.pop();
			stack.pop();

			stack.print();
		}
	}
}

int main()
{
	//ClassesAndClassMembers::main();
	//AccessSpecifiers::Two::main();
	AccessSpecifiers::Three::main();
}

