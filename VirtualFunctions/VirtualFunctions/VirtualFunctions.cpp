// VirtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "Point.h"

namespace PointersToBaseClass
{
	class Animal
	{
	protected:
		std::string m_name;
		const char* m_speak;

		// We're making this constructor protected because
		// we don't want people creating Animal objects directly,
		// but we still want derived classes to be able to use it.
		Animal(std::string name, const char *speak)
			: m_name(name), m_speak(speak)
		{
		}

	public:
		std::string getName() { return m_name; }
		const char* speak() { return m_speak; }
	};

	class Cat : public Animal
	{
	public:
		Cat(std::string name)
			: Animal(name, "meow")
		{
		}
	};

	class Dog : public Animal
	{
	public:
		Dog(std::string name)
			: Animal(name, "woof")
		{
		}
	};

	void main()
	{
		Cat fred("Fred"), misty("Misty"), zeke("Zeke");
		Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

		// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
		Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
		for (int iii = 0; iii < 6; iii++)
			std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';

	}
}

namespace VirtualFunctions
{
	/*
	1)
		a) B
		b) C
		C) A
		D) C
		E) A
		F) A
	*/
}
namespace Quiz
{
	namespace One
	{
		/*
		A) b references the base portion of d. Because getName is not virtual, it'll call Base::getName instead of Derived::getName
		B) signatures of Base::getName and Derived::getName do not match
		C) b was initialized to the base part of d via object slicing, so it doesn't know anything about Derived's getName
		D) Base is final so it can't be derived from
		E) Derived::getName is a pure virtual function, and even though an implementation is provided, 
		it could only be used in a child class if the child class explicitly invokes it. Also Derived can't be instantiated with a pure virtual function.
		F) Correct output but there is a memory leak because Base's destructor is not virtual, meaning only the Base portion of b was given back to the os, and we're leaking the derived portion. 
		*/
	}
	namespace Two
	{
		class Shape
		{
		public:
			virtual std::ostream& print(std::ostream& out) const = 0;
			friend std::ostream& operator<<(std::ostream& out, const Shape &shape)
			{
				return shape.print(out);
			}
			virtual ~Shape() 
			{

			}
		};
		class Triangle : public Shape
		{
		private:
			Point m_p1;
			Point m_p2;
			Point m_p3;
		public:
			Triangle(const Point &p1, const Point &p2, const Point &p3) : m_p1(p1), m_p2(p2), m_p3(p3)
			{

			}
			virtual std::ostream& print(std::ostream& out) const override 
			{
				out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
				return out;
			}
		};

		class Circle : public Shape
		{
		private:
			Point m_center;
			int m_radius;
		public:
			Circle(const Point &center, int radius) : m_center(center), m_radius(radius)
			{

			}
			int getRadius() { return m_radius; }

			virtual std::ostream& print(std::ostream& out) const override
			{
				out << "Circle(" << m_center << ", radius " << m_radius << ")";
				return out;
			}
		};

		int getLargestRadius(const std::vector<Shape*> &shapes)
		{
			int largestRadius = 0;
			for (const auto shape : shapes)
			{
				Circle* circle = dynamic_cast<Circle*>(shape);
				if (circle)
				{
					if (circle->getRadius() > largestRadius)
						largestRadius = circle->getRadius();
				}
			}
			return largestRadius;
		}

		void main()
		{
			std::vector<Shape*> v;
			v.push_back(new Circle(Point(1, 2, 3), 7));
			v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
			v.push_back(new Circle(Point(4, 5, 6), 3));

			// print each shape in vector v on its own line here
			for (const auto shape : v)
			{
				std::cout << *shape << "\n";
			}
			std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; 

			for (const auto shape : v)
			{
				delete shape;
			}
			v.clear();
		}
	}
}

int main()
{
	//PointersToBaseClass::main();
	Quiz::Two::main();
}

