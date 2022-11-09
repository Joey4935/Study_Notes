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
}

//InsertionSort

//StraightInsertionSort
void SortAlgorithm::StraightInsertionSort(SqList & l_Data)
{
	int tmp = 0;
	//��˳���L��ֱ�Ӳ�������L.r[0]Ϊ�ڱ�
	int i = 0;
	for (i = 1; i <= l_Data.length; ++i)
	{
		if (l_Data.r[i] < l_Data.r[i - 1])
		{
			tmp = l_Data.r[i];


			int j = 0;
			for (j = i - 1; tmp < l_Data.r[j]; --j)
			{
				l_Data.r[j + 1] = l_Data.r[j];
			}
			l_Data.r[j + 1] = l_Data.r[0];
		}
	}
	return;
}

//shellsort
void SortAlgorithm::ShellSort(SqList & l_Data)
{
	int dk = l_Data.length / 2;
	while (dk != 1)
	{
		ShellInsert(l_Data,dk);
		dk = dk / 2;
	}
}

void SortAlgorithm::ShellInsert(SqList & l_Data, int d)
{
	//��˳���L��һ��ϣ����������ǰ��������d��L.r[0]ֻ��Ϊ�ݴ浥Ԫ
	int i = 0;
	int tmp = 0;
	for (i = d + 1; i <= l_Data.length; ++i)
	{
		if (l_Data.r[i] < l_Data.r[i - d])
		{
			tmp = l_Data.r[i];		//�ݴ�
			int j = 0;

			for (j = i - d; (j > 0) && (l_Data.r[0] < l_Data.r[j]); j -= d)
			{
				l_Data.r[j + d] = l_Data.r[j];
			}
			l_Data.r[j + d] = tmp;    //���뵽��ȷλ��
		}
	}
}

void SortAlgorithm::printData()
{
	for (int i = 0; i < m_Data2Sort->length; i++)
	{
		std::cout << m_Data2Sort->r[i] << std::endl;
	}
	std::cout << "  "<< std::endl;
	return;
}

