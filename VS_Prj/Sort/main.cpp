#include "Sort_DataStruct.h"
#include "SortAlgorithm.h"


int main(void)
{
	SortAlgorithm test_class;

	test_class.printData();

	test_class.BubbleSort(*test_class.m_Data2Sort);
	//test_class.StraightInsertionSort();
	//test_class.ShellSort(*test_class.m_Data2Sort);

	test_class.printData();

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[10] = { 11,12,13,14,15,16,17,18,19,20 };

	int tmp_01 = sizeof(a);
	int tmp_02 = sizeof(a[0]);

	int *l_pTestData_01 = new int[10];
	int *l_pTestData_02 = new int[10];

	memcpy(l_pTestData_01, a, sizeof(int) * 10);
	memcpy(l_pTestData_02, b, sizeof(int) * 10);

 	char name_01[255] = "SqList_01";
	char name_02[255] = "SqList_02";

	SqList l_a = SqList(a, 10, name_01);
	
	l_a.setData(b, 10);

	l_a.makeDate(20, 100, 200);
	std::cout << " " << std::endl;

	for (int i = 0; i < l_a.length; i++)
	{
		std::cout << l_a.r[i] << std::endl;
	}
	
	SqList l_b = SqList(b, 10, name_02);

	std::cout << " " << std::endl;

	l_a += l_b;
	
	l_a = l_a + l_b;

	//*l_a = *l_a + *l_b;

	/*for (i = 0; i < l_a.length; i++)
	{
		std::cout << l_a.r[i] << std::endl;
	}*/
	
	return 0;
}