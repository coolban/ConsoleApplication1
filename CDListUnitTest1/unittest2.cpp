#include "stdafx.h"
#include "CppUnitTest.h"
extern "C"
{
	#include "dynamicarray.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CDListUnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			TwoDimensionArray * tday;
			ArrayElement * ae;
			int * i,*i2;
			
			tday = (TwoDimensionArray *)malloc(sizeof(TwoDimensionArray));
			i =(int *)malloc(sizeof(int));
			*i = 1;

			i2 = (int *)malloc(sizeof(int));
			*i2 = 2;

			//init_ArrayElement(ae,)
			init_TwoDimensionArray(tday, 5, 5);
			set_TwoDimensionArray(tday, 0, 0, i);
			ae=get_TwoDimensionArray(tday,0,0);
			Assert::AreEqual(1, *((int *)ae->data));

			set_TwoDimensionArray(tday, 6, 6, i2);
			Assert::AreEqual(7, tday->sizeofcolumns);
			Assert::AreEqual(7, tday->sizeofrows);
			ae = get_TwoDimensionArray(tday, 6, 6);
			Assert::AreEqual(2, *((int *)ae->data));


		}

	};


}