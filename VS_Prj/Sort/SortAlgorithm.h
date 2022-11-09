#pragma once

#include "Sort_DataStruct.h"

class SortAlgorithm
{
public:
	
	SortAlgorithm();

	~SortAlgorithm();

public:
	//Init
	void InitData();

	//InsertionSort
	void StraightInsertionSort(SqList &l_Data);

	void ShellSort(SqList &l_Data);

	void ShellInsert(SqList &l_Data, int d);

	//ExchangeSort
	void BubbleSort(SqList &l_Data);

	void QuickSort(SqList &l_Data);


	//print Data
	void printData();

public:

	SqList *m_Data2Sort;
		   
	SqList *m_DataSorted;
};

