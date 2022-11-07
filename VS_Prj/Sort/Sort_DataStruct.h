#ifndef SORT_DATASTRUCT_H_
#define SORT_DATASTRUCT_H_
#include <iostream>


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

public:
	int *r;		//��ַ ������ʱ��ʵ��ֵ����
	int length;	//��
	char name[255] = {0};//
};


#endif