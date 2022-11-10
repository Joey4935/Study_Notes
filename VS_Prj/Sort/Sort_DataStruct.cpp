#include "Sort_DataStruct.h"

SqList::SqList()
{
	r = nullptr;
	length = 0;
	strcpy(name, "NULL");

	Init();
}

SqList::SqList(const SqList & b)
{
	length = b.length;
	r = new int[length];
	memcpy(r, b.r, sizeof(int) * length);
	
}

SqList::SqList(const int * b, int len, char *l_pName)
{
	length = len;
	r = new int[len];
	memcpy(r,b,sizeof(int)*len);

	if (l_pName == nullptr)
	{
		strcpy(this->name, "NULL");
	}
	else
	{
		strcpy(this->name, l_pName);
	}
}

SqList::~SqList()
{
	if (r != nullptr)
		delete []r;
	r = nullptr;
}

SqList &SqList::operator+(const SqList &b) 
{
	char name[255] = "+temp";
	SqList *newSqList = new SqList(nullptr, 0, name);
	newSqList->length = this->length + b.length;
	newSqList->r = new int[newSqList->length];
	memcpy(newSqList->r, this->r, sizeof(int)*length);
	memcpy(&newSqList->r[length], b.r, sizeof(int)*b.length);
	return *newSqList;
}

SqList &SqList::operator+=(SqList & b)
{
	char name[255] = "+=temp";
	SqList *newSqList = new SqList(nullptr, 0, name);
	newSqList->length = this->length + b.length;
	newSqList->r = new int[newSqList->length];
	
	if (r != nullptr)
	{
		memcpy(newSqList->r, r, sizeof(int)*length);
	}
	memcpy(&newSqList->r[length], b.r, sizeof(int)*b.length);

	int *temp = nullptr;
	temp = new int[length];
	memcpy(temp,r,sizeof(int) * length);
	delete r;
	r = new int[length + b.length];
	memcpy(r, temp, sizeof(int) * length);
	memcpy(&r[length], b.r, sizeof(int) * b.length);
	
	length += b.length;

	delete []temp;
	delete newSqList;
	return *this;
}

SqList &SqList::operator=(const SqList & b)
{
	if (this == &b)
	{
		return *this;
	}
	else
	{
		delete[]r;
		r = new int[b.length];
		length = b.length;
		memcpy(r, b.r, sizeof(int) * length);
		return *this;
	}
}

void SqList::Init()
{
	makeDate(10,0,10);
}

void SqList::setData(const int *b, int len)
{
	if (r != nullptr)
	{
		delete[] r;
	}
	r = new int[len];
	memcpy(r, b, sizeof(int) * len);
}

void SqList::makeDate(int len, int begin, int end)
{
	if (end < begin)
	{
		return;
	}
	if (len != length)
	{
		delete []r;
		r = new int[len];
	}
	length = len;
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		r[i] = begin + (int)end*rand() / (RAND_MAX + 1);
		//std::cout << r[i] << std::endl;
	}
	return;
}
