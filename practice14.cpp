/*
给你一根长度为n的绳子，请把绳子剪成m段(m,n都是整数，n>1并且m>1)，每段绳子的长度记为
k[0],k[1],...,k[m]。请问ml[0]*k[1]*...*k[m]可能的最大乘积是多少。
例如，当绳子的长度是9时，我们把它剪成长度分别为2,3,3的三段，此时可得到的最大乘积是18.
*/

#include<iostream>
using namespace std;

//动态规划
//通过计算f（n）=f(i)*f（n-i)
int maxProductAfterCutting_solutiong1(int length)
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