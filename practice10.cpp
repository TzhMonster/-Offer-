/*
写一个函数，输入n，求斐波那契数列的第n项。斐波那契数列的定义如下
      0              n=0
f(n)= 1              n=1
      f(n-1)+f(n-2)  n>1
*/

#include<iostream>
using namespace std;

//非递归算法
long int Fibonacci(unsigned int n)
{
	long int fibNminusOne = 0;
	long int fibNminuxTwo = 1;

	if (n == 0)
		return fibNminusOne;
	if (n == 1)
		return fibNminuxTwo;

	long int fibN = 0;
	for (int i = 2; i <= n; ++i)
	{
		fibN = fibNminusOne + fibNminuxTwo;
		fibNminusOne = fibNminuxTwo;
		fibNminuxTwo = fibN;
	}
	return fibN;
}

//递归算法
long int Fibonacci(unsigned int n, int)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1, 0) + Fibonacci(n - 2, 0);
}

int main()
{
	cout << "请问要求斐波那契数列的第多少项？" << endl;
	unsigned int n=0;
	cin >> n;
	cout << "非递归算法，第" << n << "项斐波那契数列的值为：" << Fibonacci(n) << endl;
	cout << "递归算法，第" << n << "项斐波那契数列的值为：" << Fibonacci(n, 0) << endl;
	return 0;
}