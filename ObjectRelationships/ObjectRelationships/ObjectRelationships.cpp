// ObjectRelationships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "IntArray.h"

namespace CompositionAndAggregation
{
	namespace One 
	{
		/*
		a) Composition
		b) Aggregation
		c) Composition
		d) Composition
		e) Aggregation
		*/
	}

	namespace Two
	{
		class Teacher
		{
		private:
			std::string m_name;

		public:
			Teacher(std::string name)
				: m_name(name)
			{
			}

			std::string getName() { return m_name; }
		};

		class Department
		{
		private:
			std::vector<Teacher*> m_teachers;

		public:
			Department()
			{
			}
			void add(Teacher *teacher)
			{
				m_teachers.push_back(teacher);
			}
			friend std::ostream& operator<< (std::ostream& out, const Department &dept);
		};
		std::ostream& operator<< (std::ostream &out, const Department &dept)
		{
			out << "Department: ";
			for (const auto &teacher : dept.m_teachers)
			{
				out << teacher->getName() << " ";
			}
			return out;
		}


		void main()
		{
			// Create a teacher outside the scope of the Department
			Teacher *t1 = new Teacher("Bob"); // create a teacher
			Teacher *t2 = new Teacher("Frank");
			Teacher *t3 = new Teacher("Beth");

			{
				// Create a department and use the constructor parameter to pass
				// the teacher to it.
				Department dept; // create an empty Department
				dept.add(t1);
				dept.add(t2);
				dept.add(t3);

				std::cout << dept << "\n";

			} // dept goes out of scope here and is destroyed

			std::cout << t1->getName() << " still exists!\n";
			std::cout << t2->getName() << " still exists!\n";
			std::cout << t3->getName() << " still exists!\n";

			delete t1;
			delete t2;
			delete t3;
		}
	}
}
namespace Containers
{
	void main()
	{
		// Declare an array with 10 elements
		IntArray array(10);

		// Fill the array with numbers 1 through 10
		for (int i = 0; i<10; i++)
			array[i] = i + 1;

		// Resize the array to 8 elements
		array.resize(8);

		// Insert the number 20 before element with index 5
		array.insertBefore(20, 5);

		// Remove the element with index 3
		array.remove(3);

		// Add 30 and 40 to the end and beginning
		array.insertAtEnd(30);
		array.insertAtBeginning(40);

		// Print out all the numbers
		for (int j = 0; j<array.getLength(); j++)
			std::cout << array[j] << " ";
	}
}
namespace stdInitializerList
{
	void main()
	{
		IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
		for (int count = 0; count < array.getLength(); ++count)
			std::cout << array[count] << ' ';

		std::cout << '\n';

		array = { 1, 3, 5, 7, 9, 11 };

		for (int count = 0; count < array.getLength(); ++count)
			std::cout << array[count] << ' ';
	}
}
namespace Quiz
{
	/*
	1)
		a) Composition
		b) Dependency
		c) Aggregation
		d) Association
		e) Aggregation
	2) Composition
	*/
}
int main()
{
	//CompositionAndAggregation::Two::main();
	//Containers::main();
	stdInitializerList::main();
    return 0;
}

