#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 6.1 rec\lab 6.1 rec\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			const int size = 5;
			int arr[size] = { 4, 9, -3, 7, 12 };
			int count = 0, sum = 0;

			countAndSumElements(arr, size, count, sum);


			int expected = 2;
			int actual = count;



			Assert::AreEqual(expected, actual);
		}
	};
}
