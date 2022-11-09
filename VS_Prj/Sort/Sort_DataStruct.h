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

	//设置数据
	void setData(const int *b, int len);

	//

public:
	//生成随机数
	void makeDate(int len, int begin, int end);
	
public:
	int *r;		//基址 ，建表时按实际值分配
	int length;	//表长
	char name[255] = {0};//
};
#endif