#pragma once
#include <iostream>

using namespace std;

int* create_array(int max, int size)
{
	if (max > 0 && size > 0)
	{
		int* arr = new int[size]; 
		int i;
		srand(time(0));

		arr[0] = max / 3 + rand() % max;
		for (i = 1; i < size; i++)
			arr[i] = 1 + rand() % max;
		return arr;
	}
}


int binary_search(int arr[], int left, int right, int key)
{
	int midd = 0;

	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       
			right = midd - 1;      
		else if (key > arr[midd]) 
			left = midd + 1;    
		else					
			return midd;  
		if (left > right)          
			return -1;
	}
}


void quick_sort(int* arr, int first, int last)
{
	int pivot, left, temp, right;

	if (arr != nullptr)
	{
		if (first < last) {
			pivot = first;
			right = first;
			left = last;

			while (right < left)
			{
				while (arr[right] <= arr[pivot] && right < last)
					right++;
				while (arr[left] > arr[pivot])
					left--;
				if (right < left)
				{
					temp = arr[right];
					arr[right] = arr[left];
					arr[left] = temp;
				}
			}

			temp = arr[pivot]; 
			arr[pivot] = arr[left];
			arr[left] = temp;
			quick_sort(arr, first, left - 1);
			quick_sort(arr, left + 1, last);
		}

	}
	else
	{
		cout << "Empty array" << endl;
	};
}


int is_correct(int* arr, int size)
{
	while (size-- > 0)
		if (arr[size - 1] > arr[size])
			return 0;
	return 1;
}


void bubble_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


void bogo_sort(int arr[], int n)
{
	int save, i, rand_i;
	while (is_correct(arr, n) != 1)
		for (i = 0; i < n; i++)
		{
			save = arr[i];
			rand_i = rand() % n;
			arr[i] = arr[rand_i];
			arr[rand_i] = save;
		}
}


int max_char(char* string, int size)
{
	int max, i;

	if (string && size > 0)
	{
		max = string[0];
		for (i = 1; i < size; i++)
		{
			if (max < string[i])
				max = (int)string[i];
		}
		return max;
	}
}



void counting_sort(char* string, int n) {
	if (string && n > 0)
	{
		int max, i, j, index = 0;

		max = max_char(string, n);
		char* arr = new char[max + 1];

		memset(arr, 0, sizeof(*string) * (max + 1));
		for (i = 0; i < n; ++i)
		{
			arr[string[i]]++;
		}

		for (i = 0; i < max + 1; i++) {
			for (j = 0; j < arr[i]; j++)
				string[index++] = i;
		}

		delete[] arr;
		arr = nullptr;
	}
}


int cout_array(int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " | ";
	}
	cout << "" << endl;

	return 0;
}