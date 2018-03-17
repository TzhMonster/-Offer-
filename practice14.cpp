/*
����һ������Ϊn�����ӣ�������Ӽ���m��(m,n����������n>1����m>1)��ÿ�����ӵĳ��ȼ�Ϊ
k[0],k[1],...,k[m]������ml[0]*k[1]*...*k[m]���ܵ����˻��Ƕ��١�
���磬�����ӵĳ�����9ʱ�����ǰ������ɳ��ȷֱ�Ϊ2,3,3�����Σ���ʱ�ɵõ������˻���18.
*/

#include<iostream>
using namespace std;

//��̬�滮
//ͨ������f��n��=f(i)*f��n-i)
int maxProductAfterCutting_solutiong1(int length)
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