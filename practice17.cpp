/*
事故如数字n，按顺序打印出从1到最大的n位十进制。比如输入3，
则打印从1、2、3一直到最大的3位数999.
*/


#include<iostream>
using namespace std;

bool Increment(char * number);
void PrintNumber(char * number);

//方法1
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char * number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
		PrintNumber(number);
	
	printf("\n");
	delete[] number;
}

bool Increment(char * number)
{
	//进位
	int nTakeOver = 0;
	bool isOverflow = false;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; --i)
	{
		//字符转成数字
		int nSum = number[i] - '0' + nTakeOver;

		if (i == nLength-1)
			++nSum;

		if (nSum >= 10)
		{
			//最高位进位则表示结束
			if (i == 0)
				isOverflow = true;
			else
			{
				nTakeOver = 1;
				nSum -= 10;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}


void Print1ToMaxOfNDigitsRecursively(char * number, int length, int index);
//方法2
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;

	char * number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char * number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return ;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index+1] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}


//打印
void PrintNumber(char * number)
{
	bool isBegining0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; ++i)
	{
		if (isBegining0 && number[i] != '0')
			isBegining0 = false;
		if (!isBegining0)
			printf("%c", number[i]);
	}
	printf("\t");
}




// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);

	return 0;
}