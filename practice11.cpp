/*
��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ���������е������һ����ת�������ת�������СԪ�ء�
���磬����{3��4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1.
*/
#include<iostream>
using namespace std;

//˳������㷨
int MinInOrder(int *numbers, int index1, int index2)
{
	if (numbers == nullptr || index1 >= index2)
		throw new exception("Error!");

	int min = numbers[index1];
	for (int i = index1; i != index2; ++i)
		if (numbers[i] < min)
			min = numbers[i];

	return min;
}

//��Ҫ�㷨
int Min(int* numbers, int length) 
{
	if (numbers == nullptr || length <= 0)
		throw new exception("Empty!");

	int index1 = 0, index2 = length - 1;

	//ֻ��һ������
	if (index1 == index2)
		return numbers[index1];
	
	while (index1 < index2)
	{
		//�ǵ������У��ҳ���Сֵʱ,index1��index2����
		//ע���е��ڣ�eg��112����ת���飬211������ж�ʱ��index1=1,index2=2���е��ں�
		if ((index2 - index1) == 1 && numbers[index2] <= numbers[index1])
			return numbers[index2];

		int mid = (index1 + index2) / 2;
		//mid��index1��index2���ʱ�޷��ж�����һ�࣬��˳�����
		if (numbers[index1] == numbers[mid] && numbers[mid] == numbers[index2])
			return MinInOrder(numbers, index1, index2);

		//numbers[mid] >= numbers[index1] && numbers[index2] < numbers[mid],���Ҳ�
		//numbers[mid] >= numbers[index1] && numbers[index2] > numbers[mid],˳�����У������
		//numbers[mid] < numbers[index1]�������
		if (numbers[mid] >= numbers[index1] && numbers[index2] < numbers[mid])
			index1 = mid;
		else
			index2 = mid;
	}
	//������index1==index2�Ķ���������ʱ��Ϊ�������У���ʱindex1��index2ָ����Сֵ
	return numbers[index1];
}


// ====================���Դ���====================
void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char* argv[])
{
	// �������룬��������������һ����ת
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// ���ظ����֣������ظ������ָպõ���С������
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// ������ֻ��һ������
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// ����nullptr
	Test(nullptr, 0, 0);

	return 0;
}