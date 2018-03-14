/*
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增序列的数组的一个旋转，输出旋转数组的最小元素。
例如，数组{3，4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1.
*/
#include<iostream>
using namespace std;

//顺序查找算法
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

//主要算法
int Min(int* numbers, int length) 
{
	if (numbers == nullptr || length <= 0)
		throw new exception("Empty!");

	int index1 = 0, index2 = length - 1;

	//只有一个数字
	if (index1 == index2)
		return numbers[index1];
	
	while (index1 < index2)
	{
		//非递增序列，找出最小值时,index1与index2相邻
		//注意有等于，eg：112的旋转数组，211，最后判定时，index1=1,index2=2，有等于号
		if ((index2 - index1) == 1 && numbers[index2] <= numbers[index1])
			return numbers[index2];

		int mid = (index1 + index2) / 2;
		//mid，index1，index2相等时无法判定在哪一侧，用顺序查找
		if (numbers[index1] == numbers[mid] && numbers[mid] == numbers[index2])
			return MinInOrder(numbers, index1, index2);

		//numbers[mid] >= numbers[index1] && numbers[index2] < numbers[mid],在右侧
		//numbers[mid] >= numbers[index1] && numbers[index2] > numbers[mid],顺序序列，在左侧
		//numbers[mid] < numbers[index1]，在左侧
		if (numbers[mid] >= numbers[index1] && numbers[index2] < numbers[mid])
			index1 = mid;
		else
			index2 = mid;
	}
	//若出现index1==index2的多数据序列时，为递增序列，此时index1和index2指向最小值
	return numbers[index1];
}


// ====================测试代码====================
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
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入nullptr
	Test(nullptr, 0, 0);

	return 0;
}