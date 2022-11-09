#ifndef SORT_DATASTRUCT_H_
#define SORT_DATASTRUCT_H_
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <windows.h>



struct SqList
{
public:

	SqList();
	SqList(const SqList &b);
	SqList(const int *b, int len, char *l_pName = nullptr);
	~SqList();

	SqList  &operator+(const SqList &b);
	SqList  &operator+=(SqList &b);
	SqList  &operator=(const SqList &b);

	void Init();

	//��������
	void setData(const int *b, int len);

	//

public:
	//���������
	void makeDate(int len, int begin, int end);
	
public:
	int *r;		//��ַ ������ʱ��ʵ��ֵ����
	int length;	//��
	char name[255] = {0};//
};
#endif