#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 1.7/lab 1.7/Angle.h"
#include "../lab 1.7/lab 1.7/Triangle.h"
#include "../lab 1.7/lab 1.7/Angle.cpp"
#include "../lab 1.7/lab 1.7/Triangle.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Angle A, B, C;
			Triangle first;

			A.Init(90, 0);
			B.Init(180, 0);
			Assert::AreEqual(round(A.getSin()), 1.);
			Assert::AreEqual(round(B.getSin()), 0.);
		}
	};
}

