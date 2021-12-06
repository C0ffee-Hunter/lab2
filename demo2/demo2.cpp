#include "pch.h"
#include "CppUnitTest.h"
#include"../lab2/lab2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace demo2
{
	TEST_CLASS(demo2)
	{
	public:
		
		TEST_METHOD(quick_sort_test)
		{
			int* arr = nullptr;
			int i;

			arr = new int[10];
			for (i = 0; i < 10; i++)
			{
				arr[i] = 10 - i;
			}
			quick_sort(arr, 0, 9);
			int* new_arr = nullptr;
			new_arr = new int[10];
			new_arr[0] = 1;
			new_arr[1] = 2;
			new_arr[2] = 3;
			new_arr[3] = 4;
			new_arr[4] = 5;
			new_arr[5] = 6;
			new_arr[6] = 7;
			new_arr[7] = 8;
			new_arr[8] = 9;
			new_arr[9] = 10;
			Assert::IsTrue(arr[0] == new_arr[0]);
			Assert::IsTrue(arr[1] == new_arr[1]);
			Assert::IsTrue(arr[2] == new_arr[2]);
			Assert::IsTrue(arr[3] == new_arr[3]);
			Assert::IsTrue(arr[4] == new_arr[4]);
			Assert::IsTrue(arr[5] == new_arr[5]);
			Assert::IsTrue(arr[6] == new_arr[6]);
			Assert::IsTrue(arr[7] == new_arr[7]);
			Assert::IsTrue(arr[8] == new_arr[8]);
			Assert::IsTrue(arr[9] == new_arr[9]);
			delete[] arr;
			delete[] new_arr;
		}
		TEST_METHOD(binary_search_test)
		{
			int* arr = nullptr;
			int i, number;

			arr = new int[4];
			for (i = 0; i < 4; i++)
			{
				arr[i] = 4 - i;
			}
			number = 0;
			number = binary_search(arr, 0, 4, 1);
			Assert::IsFalse(number == 0);
			Assert::IsFalse(number == 1);
			Assert::IsFalse(number == 2);
			delete[] arr;
		}
		TEST_METHOD(bubble_sort_test)
		{
			int* arr = nullptr;
			int i;

			arr = new int[4];
			for (i = 0; i < 4; i++)
			{
				arr[i] = 4 - i;
			}
			bubble_sort(arr, 4);
			int* arr_true = nullptr;
			arr_true = new int[4];
			arr_true[0] = 1;
			arr_true[1] = 2;
			arr_true[2] = 3;
			arr_true[3] = 4;
			Assert::IsTrue(arr[0] == arr_true[0]);
			Assert::IsTrue(arr[3] == arr_true[3]);
			Assert::IsTrue(arr[2] == arr_true[2]);
			Assert::IsTrue(arr[1] == arr_true[1]);
			delete[] arr;
			delete[] arr_true;
		}

		TEST_METHOD(bogo_sort_test)
		{
			int* arr = nullptr;

			arr = create_array(32, 10);
			bogo_sort(arr, 10);
			Assert::IsTrue(is_correct(arr, 10));
			delete[] arr;
		}
		TEST_METHOD(countingsort_test)
		{
			char* string = nullptr;

			string = new char[5];
			string[0] = 'b';
			string[1] = 'd';
			string[2] = 'c';
			string[3] = 'a';
			string[4] = '\0';
			counting_sort(string, 4);
			Assert::AreEqual("abcd", string);
			delete[] string;
		}
	};
};
