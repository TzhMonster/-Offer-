/*
给你一根长度为n的绳子，请把绳子剪成m段(m,n都是整数，n>1并且m>1)，每段绳子的长度记为
k[0],k[1],...,k[m]。请问ml[0]*k[1]*...*k[m]可能的最大乘积是多少。
例如，当绳子的长度是9时，我们把它剪成长度分别为2,3,3的三段，此时可得到的最大乘积是18.
*/

#include<iostream>
using namespace std;

//动态规划
//通过计算f（n）=f(i)*f（n-i)
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//用来保存长度0,1,2...length的最大乘积
	int *products = new int[length + 1];
	//因为分段长度为0,1,2,3时，不再继续分段就是能出现的最大乘积
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	//计算长度为i的分段最大乘积
	for (int i = 4; i <= length; ++i)
	{
		int max = 0;
		//计算长度为i的分段分别从1开始重新分段的最大乘积，从i=4计算到i=length
		//如i=4时，计算f(1)*f(3）和f(2)*f(2)，并记录最大值就是f(i)的最大值
		//j到i/2为了避免重复计算，如1*4和4*1
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
			products[i] = max;
		}
	}

	//不直接返回products[length]为了防止内存泄漏
	int max = products[length];
	delete[] products;
	return max;
}

//贪婪算法
//当长度大于5时，尽可能剪成长度为3的绳子，当长度为4时，剪成两端长度为2的绳子
int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOfThree = length / 3;
	if (length - timesOfThree * 3 == 1)
		--timesOfThree;

	int timesOfTow = (length - timesOfThree * 3) / 2;

	return (int)pow(3, timesOfThree) * (int)pow(2, timesOfTow);
}


// ====================测试代码====================
void test(const char* testName, int length, int expected)
{
	int result1 = maxProductAfterCutting_solution1(length);
	if (result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = maxProductAfterCutting_solution2(length);
	if (result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
	int length = 1;
	int expected = 0;
	test("test1", length, expected);
}

void test2()
{
	int length = 2;
	int expected = 1;
	test("test2", length, expected);
}

void test3()
{
	int length = 3;
	int expected = 2;
	test("test3", length, expected);
}

void test4()
{
	int length = 4;
	int expected = 4;
	test("test4", length, expected);
}

void test5()
{
	int length = 5;
	int expected = 6;
	test("test5", length, expected);
}

void test6()
{
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7()
{
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}

void test8()
{
	int length = 8;
	int expected = 18;
	test("test8", length, expected);
}

void test9()
{
	int length = 9;
	int expected = 27;
	test("test9", length, expected);
}

void test10()
{
	int length = 10;
	int expected = 36;
	test("test10", length, expected);
}

void test11()
{
	int length = 50;
	int expected = 86093442;
	test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();

	return 0;
}