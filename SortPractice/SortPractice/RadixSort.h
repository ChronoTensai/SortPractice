#pragma once


class RadixItem
{
	public:
		RadixItem(){}
		void CreateQueue(const int * length);
		~RadixItem();	
		void AddItem(int value);
		int GetItem();
		bool IsEmpty() {return isEmpty;}
	private:
		//Should better use nodes instead of array
		int* _arrayValues = nullptr;
		int _lastIndexPushed = -1;
		int _lastIndexPoped = 0;
		bool isEmpty = true;
};


class RadixIntSort
{

public:
	RadixIntSort() {};
	void Sort(int* arrayToSort,const int * length);	
	~RadixIntSort() {};
private:
	static const int INTEGERS_SLOTS = 10;
	int GetUnit(int currentIteration, int number);
	int GetNumberOfIterations(int * arrayToSort, const int * length);
};

