#include "stdafx.h"
#include "RadixSort.h"
#include <math.h>


void RadixIntSort::Sort(int * arrayToSort, const int * length)
{
	int iterations = GetNumberOfIterations(arrayToSort, length);
	int currentIterations = 0;

	RadixItem _itemArray[INTEGERS_SLOTS];

	for (int i = 0; i < INTEGERS_SLOTS; i++)
	{
		_itemArray[i].CreateQueue(length);
	}


	int * auxArraySort = new int[*length];
	memcpy(auxArraySort, arrayToSort, sizeof(int) * *length);

	while (iterations > currentIterations)
	{
		for (int i = 0; i < *length; i++)
		{
			_itemArray[GetUnit(currentIterations, auxArraySort[i])].AddItem(auxArraySort[i]);
		}
		
		int currentSortIndex = 0;
		for (int i = 0; i < INTEGERS_SLOTS; i++)
		{
			while (_itemArray[i].IsEmpty() == false)
			{
				auxArraySort[currentSortIndex] = _itemArray[i].GetItem();
				currentSortIndex++;
			}		
		}

		currentIterations++;
	}
	
	
	memcpy(arrayToSort, auxArraySort, sizeof(int) * *length);
	delete[] auxArraySort;
}

int RadixIntSort::GetUnit(int currentIteration, int number)
{
	//Draft
	// Example Value 878
	// 878  % 10 = 8
	// 878 % 100 = 78 - 8 = 70 / 10 = 7
	// 878 % 1000 = 878 - 78 = 800 /100 = 8

	return 0;

}

int RadixIntSort::GetNumberOfIterations(int * arrayToSort, const int * length)
{
	int iterations = 1;
	int auxLimit = 10;
	for (int i = 0; i < *length; i++)
	{
		if (auxLimit >= arrayToSort[i])
		{
			iterations++;
			auxLimit = pow(10, iterations);
		}
	}
	return iterations;
}

////// Radix Item

void RadixItem::CreateQueue(const int * length)
{	
	//_lastIndexUsed = 0;
	_arrayValues = new int[*length];
}

RadixItem::~RadixItem()
{
	if (_arrayValues != nullptr)
	{
		//I dont know why the software dont allow me erase this array
		//delete [] _arrayValues;
	}
}


void RadixItem::AddItem(int value)
{
	_lastIndexPushed++;
	if (_lastIndexPushed == 1)
	{
		isEmpty = false;
		_lastIndexPoped = 0;
	}
	_arrayValues[_lastIndexPushed] = value;
}

int RadixItem::GetItem()
{
	int returnValue = _arrayValues[_lastIndexPoped];
	_lastIndexPoped++;
	_lastIndexPushed--;
	if (_lastIndexPushed == -1)
	{
		isEmpty = true;
	}
	return returnValue;	
}
