/*
*面试题5
*请实现一个函数，把字符中的每个空格替换成%20.例如，输入“We are happy.”，
*则输出“We%20are%20happy.”
*时间复杂度O(n)
*空间复杂度O(1)
*/

#include<iostream>

const int MAXSIZE = 100;

/*算法函数*/
void ReplaceBlank(char string[], int length);
/*We are happy.测试*/
void test1();
/*空串测试*/
void test2();
/*空间不足*/
void test3();

int main()
{
	test1();
	test2();
	test3();
	return 0;
}

void ReplaceBlank(char string[], int length)//length为数组长度
{
	//计算字符串长和扩展后字符串长
	int originalLength = 0, numOfBlank = 0, realLength = 0;
	while (string[originalLength] != '\0')
	{
		++originalLength;
		if (string[originalLength] == ' ')
			++numOfBlank;
	}
	realLength = originalLength + numOfBlank * 2;

	if (realLength >= length || originalLength == 0)
	{
		std::cout << "失败，原字符串为:";
		return;
	}

	int rear = realLength, front = originalLength;
	while (front != rear)
	{
		if (string[front] != ' ')
			string[rear--] = string[front--];
		else
		{
			string[rear--] = '0';
			string[rear--] = '2';
			string[rear--] = '%';
			--front;
		}
	}
}

void test1()
{
	char string[MAXSIZE] = "We are happy.";
	ReplaceBlank(string, MAXSIZE);
	std::cout << string << std::endl;
}

void test2()
{
	char string[MAXSIZE] = "";
	ReplaceBlank(string, MAXSIZE);
	std::cout << string << std::endl;
}

void test3()
{
	char string[6] = "Q a Q";
	ReplaceBlank(string, 6);
	std::cout << string <<std::endl;
}
