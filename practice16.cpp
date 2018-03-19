/*
实现函数double Power(double base,int exponent),求base的exponent次方。
不得使用库函数，同时不需要考虑大数问题。
*/

#include<iostream>
using namespace std;

bool g_InvalidInput = false;

bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base,unsigned int absExponent);
double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base,0.0) && exponent < 0)
	{
		//底为0，指数为负，0的倒数没有意义出错
		g_InvalidInput = true;
		return 0;
	}

	//负数转成unsigned类型并不会转变二进码
	unsigned int absExponent = (unsigned int)exponent;
	if(exponent<0)
		absExponent= (unsigned int)-exponent;

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int absExponent)
{
	if (absExponent == 0)
		return 1;
	if (absExponent == 1)
		return base;

	//对absExponent右移一位相当于除以2
	//a^n=a^(n/2)*a^(n/2)   n为偶数时
	//a^n=a^((n-1)/2)*a^((n-1)/2)*a    n为奇数时
	double result = PowerWithUnsignedExponent(base, absExponent >> 1);
	result *= result;
	//与0x1相与判断是否为奇数
	if (absExponent & 0x1 == 1)
		result *= base;
	
	return result;
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
	// 底数、指数都为正数
	Test("Test1", 2, 3, 8, false);

	// 底数为负数、指数为正数
	Test("Test2", -2, 3, -8, false);

	// 指数为负数
	Test("Test3", 2, -3, 0.125, false);

	// 指数为0
	Test("Test4", 2, 0, 1, false);

	// 底数、指数都为0
	Test("Test5", 0, 0, 1, false);

	// 底数为0、指数为正数
	Test("Test6", 0, 4, 0, false);

	// 底数为0、指数为负数
	Test("Test7", 0, -4, 0, true);

	return 0;
}