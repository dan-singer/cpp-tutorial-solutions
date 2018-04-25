// ObjectRelationships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

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

int main()
{
	CompositionAndAggregation::Two::main();
    return 0;
}

