#include "SortAlgorithm.h"

SortAlgorithm::SortAlgorithm()
{
	m_Data2Sort = nullptr;
	m_DataSorted = nullptr;
	InitData();
}

SortAlgorithm::~SortAlgorithm()
{
	if (m_Data2Sort != nullptr)
		delete m_Data2Sort;	
	if (m_DataSorted != nullptr)
		delete m_DataSorted;
}

void SortAlgorithm::InitData()
{
	m_Data2Sort = new SqList();
	m_DataSorted = new SqList();
	return;
}

//InsertionSort

//StraightInsertionSort
void SortAlgorithm::StraightInsertionSort(SqList & l_Data)
{
	//遍历无序序列
	int j = 0;
	for (int i = 1; i < l_Data.length; ++i)	//遍历整个顺序表
	{
		if (l_Data.r[i] < l_Data.r[i - 1])
		{
			//临时保存将要排序的元素 
			int tmp = l_Data.r[i];
			//遍历有序序列
			for (j = i - 1; (tmp < l_Data.r[j]) && (j >= 0); j--)//将待排序元素依次和有序序列中的元素比较 
			{
				//待排序元素 小于 有序序列中当前元素时 将该元素后移
				l_Data.r[j + 1] = l_Data.r[j];
			}
			//待排序元素 大于 有序序列最后一个元素 直接将该元素插入到有序序列最后
			l_Data.r[j + 1] = tmp;
		}
	}
	return;
}

//shellsort
void SortAlgorithm::ShellSort(SqList & l_Data)
{
	int dk = l_Data.length / 2;
	while (dk != 0)
	{
		ShellInsert(l_Data, dk);
		dk = dk / 2;
	}
	return;
}

void SortAlgorithm::ShellInsert(SqList & l_Data, int d)
{
	//对顺序表L做一趟希尔插入排序，前后增量是d；L.r[0]只作为暂存单元
	for (int i = 0; i < d; i++)
	{
		//插入排序
		for (int j = d + i; j < l_Data.length; j += d)
		{
			if (l_Data.r[j] < l_Data.r[j - d])
			{
				int tmp = l_Data.r[j];
				int k = 0;
				for (k = j - d; (tmp < l_Data.r[k]) && (k >= 0); k -= d)
				{
					//待排序元素 小于 有序序列中当前元素时 将该元素后移
					l_Data.r[k + d] = l_Data.r[k];
				}
				//待排序元素 大于 有序序列最后一个元素 直接将该元素插入到有序序列最后
				l_Data.r[k + d] = tmp;
			}
		}
	}
	return;
}


//BubbleSort
void SortAlgorithm::BubbleSort(SqList & l_Data)
{
	//for (int i = 0; i < l_Data.length; i++)
	//{
	//	for (int j = 0; j < l_Data.length-1; j++)
	//	{
	//		//交换
	//		if (l_Data.r[j] > l_Data.r[j + 1])
	//		{
	//			int tmp = l_Data.r[j + 1];
	//			l_Data.r[j + 1] = l_Data.r[j];
	//			l_Data.r[j] = tmp;
	//		}
	//	}
	//}

	//int tag = 0,bound = 0;
	//int n = 1;
	//for (bound = 0; tag == 0; ++bound)
	//{
	//	tag = 1;
	//	for (int j = l_Data.length - 2; j > bound; --j)
	//	{
	//		//交换
	//		if (l_Data.r[j] > l_Data.r[j + 1])
	//		{
	//			int tmp = l_Data.r[j + 1];
	//			l_Data.r[j + 1] = l_Data.r[j];
	//			l_Data.r[j] = tmp;
	//		}
	//	}
	//}
}

//QuickSort
void SortAlgorithm::QuickSort(SqList & l_Data)
{
}


void SortAlgorithm::printData()
{
	for (int i = 0; i < m_Data2Sort->length; i++)
	{
		std::cout << m_Data2Sort->r[i] << "  ";
	}
	std::cout << "  "<< std::endl;
	return;
}

