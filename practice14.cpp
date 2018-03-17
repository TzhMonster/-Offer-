/*
����һ������Ϊn�����ӣ�������Ӽ���m��(m,n����������n>1����m>1)��ÿ�����ӵĳ��ȼ�Ϊ
k[0],k[1],...,k[m]������ml[0]*k[1]*...*k[m]���ܵ����˻��Ƕ��١�
���磬�����ӵĳ�����9ʱ�����ǰ������ɳ��ȷֱ�Ϊ2,3,3�����Σ���ʱ�ɵõ������˻���18.
*/

#include<iostream>
using namespace std;

//��̬�滮
//ͨ������f��n��=f(i)*f��n-i)
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//�������泤��0,1,2...length�����˻�
	int *products = new int[length + 1];
	//��Ϊ�ֶγ���Ϊ0,1,2,3ʱ�����ټ����ֶξ����ܳ��ֵ����˻�
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	//���㳤��Ϊi�ķֶ����˻�
	for (int i = 4; i <= length; ++i)
	{
		int max = 0;
		//���㳤��Ϊi�ķֶηֱ��1��ʼ���·ֶε����˻�����i=4���㵽i=length
		//��i=4ʱ������f(1)*f(3����f(2)*f(2)������¼���ֵ����f(i)�����ֵ
		//j��i/2Ϊ�˱����ظ����㣬��1*4��4*1
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
			products[i] = max;
		}
	}

	//��ֱ�ӷ���products[length]Ϊ�˷�ֹ�ڴ�й©
	int max = products[length];
	delete[] products;
	return max;
}

//̰���㷨
//�����ȴ���5ʱ�������ܼ��ɳ���Ϊ3�����ӣ�������Ϊ4ʱ���������˳���Ϊ2������
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


// ====================���Դ���====================
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