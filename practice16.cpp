/*
ʵ�ֺ���double Power(double base,int exponent),��base��exponent�η���
����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
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
		//��Ϊ0��ָ��Ϊ����0�ĵ���û���������
		g_InvalidInput = true;
		return 0;
	}

	//����ת��unsigned���Ͳ�����ת�������
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

	//��absExponent����һλ�൱�ڳ���2
	//a^n=a^(n/2)*a^(n/2)   nΪż��ʱ
	//a^n=a^((n-1)/2)*a^((n-1)/2)*a    nΪ����ʱ
	double result = PowerWithUnsignedExponent(base, absExponent >> 1);
	result *= result;
	//��0x1�����ж��Ƿ�Ϊ����
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

// ====================���Դ���====================
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
	// ������ָ����Ϊ����
	Test("Test1", 2, 3, 8, false);

	// ����Ϊ������ָ��Ϊ����
	Test("Test2", -2, 3, -8, false);

	// ָ��Ϊ����
	Test("Test3", 2, -3, 0.125, false);

	// ָ��Ϊ0
	Test("Test4", 2, 0, 1, false);

	// ������ָ����Ϊ0
	Test("Test5", 0, 0, 1, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test6", 0, 4, 0, false);

	// ����Ϊ0��ָ��Ϊ����
	Test("Test7", 0, -4, 0, true);

	return 0;
}