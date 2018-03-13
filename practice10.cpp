/*
дһ������������n����쳲��������еĵ�n�쳲��������еĶ�������
      0              n=0
f(n)= 1              n=1
      f(n-1)+f(n-2)  n>1
*/

#include<iostream>
using namespace std;

//�ǵݹ��㷨
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

//�ݹ��㷨
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
	cout << "����Ҫ��쳲��������еĵڶ����" << endl;
	unsigned int n=0;
	cin >> n;
	cout << "�ǵݹ��㷨����" << n << "��쳲��������е�ֵΪ��" << Fibonacci(n) << endl;
	cout << "�ݹ��㷨����" << n << "��쳲��������е�ֵΪ��" << Fibonacci(n, 0) << endl;
	return 0;
}