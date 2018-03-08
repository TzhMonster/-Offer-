/*
*������5
*��ʵ��һ�����������ַ��е�ÿ���ո��滻��%20.���磬���롰We are happy.����
*�������We%20are%20happy.��
*ʱ�临�Ӷ�O(n)
*�ռ临�Ӷ�O(1)
*/

#include<iostream>

const int MAXSIZE = 100;

/*�㷨����*/
void ReplaceBlank(char string[], int length);
/*We are happy.����*/
void test1();
/*�մ�����*/
void test2();
/*�ռ䲻��*/
void test3();

int main()
{
	test1();
	test2();
	test3();
	return 0;
}

void ReplaceBlank(char string[], int length)//lengthΪ���鳤��
{
	//�����ַ���������չ���ַ�����
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
		std::cout << "ʧ�ܣ�ԭ�ַ���Ϊ:";
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
