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
	//������������
	int j = 0;
	for (int i = 1; i < l_Data.length; ++i)	//��������˳���
	{
		if (l_Data.r[i] < l_Data.r[i - 1])
		{
			//��ʱ���潫Ҫ�����Ԫ�� 
			int tmp = l_Data.r[i];
			//������������
			for (j = i - 1; (tmp < l_Data.r[j]) && (j >= 0); j--)//��������Ԫ�����κ����������е�Ԫ�رȽ� 
			{
				//������Ԫ�� С�� ���������е�ǰԪ��ʱ ����Ԫ�غ���
				l_Data.r[j + 1] = l_Data.r[j];
			}
			//������Ԫ�� ���� �����������һ��Ԫ�� ֱ�ӽ���Ԫ�ز��뵽�����������
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
	//��˳���L��һ��ϣ����������ǰ��������d��L.r[0]ֻ��Ϊ�ݴ浥Ԫ
	for (int i = 0; i < d; i++)
	{
		//��������
		for (int j = d + i; j < l_Data.length; j += d)
		{
			if (l_Data.r[j] < l_Data.r[j - d])
			{
				int tmp = l_Data.r[j];
				int k = 0;
				for (k = j - d; (tmp < l_Data.r[k]) && (k >= 0); k -= d)
				{
					//������Ԫ�� С�� ���������е�ǰԪ��ʱ ����Ԫ�غ���
					l_Data.r[k + d] = l_Data.r[k];
				}
				//������Ԫ�� ���� �����������һ��Ԫ�� ֱ�ӽ���Ԫ�ز��뵽�����������
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
	//		//����
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
	//		//����
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

