#include <iostream>
#include "lab2.h"
#include <time.h>

using namespace std;


int main()
{
	int midd = 0, size = -1, i, max;
    int* array1 = nullptr, * array2 = nullptr;
	clock_t begin, end;
	double sec;

    max = rand();
	srand(time(0));

    for (i = 10; i <= 100000; i *= 10)
    {
        begin = clock();
        array2 = create_array(max, i);
        quick_sort(array2, 0, i - 1);
        end = clock();
        sec = ((double)end - (double)begin)/ CLOCKS_PER_SEC;
        cout << "Quick sort, elements: " << i << ", time: " << sec << " sec" << endl;
        delete[] array2;
        array2 = nullptr;
    }

    puts("\n");

    for (i = 10; i <= 100000; i *= 10)
    {
        begin = clock();
        array1 = create_array(max, i);
        bubble_sort(array1, i);
        end = clock();
        sec = ((double)end - (double)begin) / CLOCKS_PER_SEC;
        cout << "Bubble sort, elements: " << i << ", time: " << sec << " sec" << endl;
        delete[] array1;
        array1 = nullptr;
    }

    return 0;
}
