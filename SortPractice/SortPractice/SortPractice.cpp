// SortPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RadixSort.h"

void PrintArray(int* arrayToPrint, const int * length)
{
	printf("[");
	for (int i = 0; i < *length; i++)
	{
		printf(" %d", arrayToPrint[i]);
		if (i != *length - 1)
		{
			printf(",");
		}
	}
	printf(" ] \n");

}

int main()
{
	const int _arrayLength = 10;
	int _array[_arrayLength] = { 100,152,2,645,75,55,256,989,640,55 };
	RadixSort _radixSort;

	PrintArray(_array, &_arrayLength);

	
	_radixSort.SortInt(_array, &_arrayLength);


	
	getchar();
	return 0;
}



