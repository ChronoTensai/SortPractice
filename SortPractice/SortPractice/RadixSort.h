#pragma once
class RadixItem
{
public:
	RadixItem(const int * length)
	{
		_arrayValues = new int[*length];
	}
	~RadixItem()
	{
		delete[] _arrayValues;
	}
	void AddItem(int value)
	{
		_lastIndexUsed++;
		_arrayValues[_lastIndexUsed] = value;
	}

	int GetItem()
	{
		int returnValue = _arrayValues[_lastIndexUsed];
		_lastIndexUsed--;
		return returnValue;
	}
private:
	int* _arrayValues;
	int _lastIndexUsed = 0;	
};

class RadixSort
{
public:
	RadixSort();
	void SortInt(int* arrayToSort,const int * length);
	~RadixSort();
private:
	int Iterances;
	int getUnit(int iterationTime)
};

