// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <functional>
namespace Returning {
	int sumTo(const int max);

	struct Employee {
		std::string name;
	};
	void printEmployeeName(const Employee &employee);

	void minmax(const int a, const int b, int &min_out, int &max_out);

	int getIndexOfLargestValue(const int *arr, const int len);

	const int& getElement(const int *arr, const int index);
}

namespace FunctionPtrs {

	using arithemeticFcn = int(*)(const int, const int);

	int add(const int a, const int b)
	{
		return a + b;
	}
	int subtract(const int a, const int b)
	{
		return a - b;
	}
	int multiply(const int a, const int b)
	{
		return a * b;
	}
	int divide(const int a, const int b)
	{
		return a / b;
	}


	struct ArithmeticStruct {
		char op;
		arithemeticFcn fnPtr;
	};

	static ArithmeticStruct arithmeticArray[]{
		{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
	};

	arithemeticFcn getArithmeticFunction(const char op)
	{
		for (const ArithmeticStruct &arStruct : arithmeticArray)
		{
			if (arStruct.op == op)
				return arStruct.fnPtr;
		}
		//Default to add
		return add;
	}

	void main()
	{
		std::cout << "Enter a mathematical expression, e.g. 5 + 7. Only integers allowed!\n";
		int aIn, bIn;
		char op;
		std::cin >> aIn;
		std::cin >> op;
		std::cin >> bIn;

		arithemeticFcn func = getArithmeticFunction(op);
		int res = func(aIn, bIn);
		std::cout << res << "\n";
	}
}

namespace Recursion {

	void printBinaryDigits(unsigned int b10)
	{
		if (b10 > 0)
		{
			printBinaryDigits(b10 / 2);
			std::cout << b10 % 2;
		}
	}
	void printBinary(int b10)
	{
		if (b10 == 0)
			std::cout << "0";
		else
			printBinaryDigits(static_cast<unsigned int>(b10));
	}

	void printBinaryDemo()
	{
		std::cout << "Enter an int in base 10: ";
		int in;
		std::cin >> in;
		printBinary(in);
		std::cout << "\n";
	}
	void main()
	{
		printBinaryDemo();
	}
}

namespace Quiz {
	namespace One {
		double max(double d1, double d2);
		void swap(int &a, int &b);
		int& getLargestElement(int *arr, int len);
	}
	namespace Two {}
	namespace Three {




		// array is the array to search over.
		// target is the value we're trying to determine exists or not.
		// min is the index of the lower bounds of the array we're searching.
		// max is the index of the upper bounds of the array we're searching.
		// binarySearch() should return the index of the target element if the target is found, -1 otherwise
		int binarySearch(int *array, int target, int min, int max)
		{
			while (max >= min) {
				// this way of calculating midpoint avoids integer overflow
				int midPt = min + ((max - min) / 2);
				if (array[midPt] > target)
					max = midPt - 1;
				else if (array[midPt] < target)
					min = midPt + 1;
				else
					return midPt;
			}
			return -1;
		}	
		int binarySearchRecursive(int *array, int target, int min, int max) {
			//Termination condition
			if (max < min)
				return -1;
			// this way of calculating midpoint avoids integer overflow
			int midPt = min + ((max - min) / 2);
			if (array[midPt] > target)
				return binarySearchRecursive(array, target, min, midPt - 1);
			else if (array[midPt] < target)
				return binarySearchRecursive(array, target, midPt + 1, max);
			else
				return midPt;
		}

		int main(bool recursive)
		{
			int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

			// We're going to test a bunch of values to see if they produce the expected results
			const int numTestValues = 9;
			// Here are the test values
			int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
			// And here are the expected results for each value
			int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

			int(*bSearch)(int*, int, int, int) = recursive ? binarySearchRecursive : binarySearch;

			// Loop through all of the test values
			for (int count = 0; count < numTestValues; ++count)
			{
				// See if our test value is in the array
				int index = bSearch(array, testValues[count], 0, 14);
				// If it matches our expected value, then great!
				if (index == expectedValues[count])
					std::cout << "test value " << testValues[count] << " passed!\n";
				else // otherwise, our binarySearch() function must be broken
					std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
			}

			return 0;
		}
	}
}

int main(int argc, char *argv[])
{
	//FunctionPtrs::main();
	//Recursion::main();
	bool recursive;
	if (argc < 2)
		recursive = false;
	else
		recursive = strcmp(argv[1], "recursive") == 0; //0 means they're equal...weird.
	std::cout << "Recursive? " << recursive << "\n";
	Quiz::Three::main(recursive);


	return 0;
}

