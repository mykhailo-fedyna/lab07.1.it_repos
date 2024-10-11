#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.1(it).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 3;
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];
			testMatrix[0][0] = 3;
			testMatrix[0][1] = 5;
			testMatrix[0][2] = 9;
			testMatrix[1][0] = 7;
			testMatrix[1][1] = 6;
			testMatrix[1][2] = 8;
			int S = 0;
			int k = 0;
			Calc(testMatrix, rowCount, colCount, S, k);
			Assert::AreEqual(32, S);
			Assert::AreEqual(5, k);
			Assert::AreEqual(0, testMatrix[0][1]);
			Assert::AreEqual(0, testMatrix[1][0]);
			Assert::AreEqual(0, testMatrix[1][2]);
			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
